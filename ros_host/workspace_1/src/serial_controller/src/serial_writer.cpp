#include <stdexcept>
#include <string>
#include <iostream>
#include "serial_writer.h"
#include <wiringSerial.h>

serial_writer::serial_writer(){
    if((this->fd=serialOpen("/dev/ttyUSB0",115200))<0){
        throw std::logic_error("Unable to open serial device.\n");
    }
};

int serial_writer::write_to_serial(std::vector<double> positions, std::vector<double> times, int n_points){
    std::string buffer;

    if(positions.size() != times.size())
    {
        throw std::invalid_argument("Invalid 'size' arguments.");
    }
    

    for(int i=0; i < positions.size(); ++i)
    {
        if(i==0){buffer += "{";}
        buffer += std::to_string(positions[i]) + ",";
    }
    buffer.pop_back();
    buffer = buffer + "}";
    for(int i=0; i < times.size(); ++i)
    {
        if(i==0){buffer += "{";}
        buffer += std::to_string(times[i]) + ",";
    }
    buffer.pop_back();
    buffer = buffer + "}";
    buffer = buffer + std::to_string(n_points);
    std::cout << buffer << std::endl;
    serialPrintf(this->fd, buffer.c_str()); //este o serialPrintf() ?
    serialFlush(this->fd); 

    return 0;
};

