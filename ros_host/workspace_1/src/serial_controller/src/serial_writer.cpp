#include <stdexcept>
#include "serial_writer.h"
#include <wiringSerial.h>
#include <iomanip>
#include <sstream>
#include <chrono>

serial_writer::serial_writer(std::string serial_device, std::function<void(double)> action_on_float_read){
    this->action_on_float_read = action_on_float_read;
    
    std::cout << serial_device << std::endl;
    if((this->fd=serialOpen(serial_device.c_str(), 115200))<0){
        throw std::logic_error("Unable to open serial device.\n");
    }
    this->run_in_background = true;

    this->background_thread = std::thread{&serial_writer::read_from_serial_in_background, this};
};

serial_writer::~serial_writer(){
    this->run_in_background = false;
}

// The message format has to be the same of the microcontroller.
int serial_writer::write_to_serial(std::vector<double> positions, std::vector<double> times, int n_points){
    std::string buffer;

    if(positions.size() != times.size())
    {
        throw std::invalid_argument("Invalid 'size' arguments.");
    }
    

    for(int i=0; i < positions.size(); ++i)
    {
        if(i==0){buffer += "{";}
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << positions[i];
        std::string s = stream.str();
        buffer += s + ",";
    }
    buffer.pop_back();
    buffer = buffer + "}";
    for(int i=0; i < times.size(); ++i)
    {
        if(i==0){buffer += "{";}
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << times[i];
        std::string s = stream.str();
        buffer += s + ",";
    }
    buffer.pop_back();
    buffer = buffer + "}";
    buffer = buffer + std::to_string(n_points);
    std::cout << buffer << std::endl;
    this->serial_lock.lock();
    serialPrintf(this->fd, buffer.c_str()); //este o serialPrintf() ?
    serialFlush(this->fd); 
    this->serial_lock.unlock();

    return 0;
};


void serial_writer::read_from_serial_in_background(){
    std::cout << "thread start" << std::endl;
    std::string buffer;
    while (this->run_in_background){
        this->serial_lock.lock();
        if (serialDataAvail(this->fd)){
            int s = serialGetchar(this->fd);
            this->serial_lock.unlock();
            std::string str(1, char(s));
            if (char(s) == '\n'){
                double buffer_double = -1;
                std::string buffer_copy = buffer;
                buffer = "";
                try {
                    buffer_double = std::stod(buffer_copy);
                } catch (const std::invalid_argument&) {
                    this->serial_lock.unlock();
                    std::cerr << "Argument is invalid\n";
                    continue;
                } catch (const std::out_of_range&) {
                    this->serial_lock.unlock();
                    std::cerr << "Argument is out of range for a double\n";
                    continue;
                } 
                this->action_on_float_read(buffer_double);
            }
            else {
                buffer += str;
            }
        }
        else {
            this->serial_lock.unlock();
        }
    }
    std::cout << "thread end" << std::endl;
};

