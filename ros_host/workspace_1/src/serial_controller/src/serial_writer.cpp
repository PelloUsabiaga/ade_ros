#include <stdexcept>
#include "serial_writer.h"
#include <wiringSerial.h>
#include <iomanip>
#include <sstream>
#include <chrono>

serial_writer::serial_writer(std::string serial_device){
    std::cout << serial_device << std::endl;
    std::cout << "here end" << std::endl;

    this->run_in_background = true;

    this->background_thread = std::thread{&serial_writer::read_from_serial_in_background, this};
    if((this->fd=serialOpen(serial_device.c_str(), 115200))<0){
        throw std::logic_error("Unable to open serial device.\n");
    }
    std::cout << "constructor end" << std::endl;
};

serial_writer::~serial_writer(){
    this->run_in_background = false;
}

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
    serialPrintf(this->fd, buffer.c_str()); //este o serialPrintf() ?
    serialFlush(this->fd); 

    return 0;
};


void serial_writer::read_from_serial_in_background(){
    std::cout << "thread start" << std::endl;
    while (this->run_in_background){
        std::cout << "kaixo" << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
};

