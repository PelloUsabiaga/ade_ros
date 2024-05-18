#include <stdexcept>
#include <string>
#include <iostream>
#include "serial_writer.h"
#include <wiringSerial.h>

serial_writer::serial_writer(){};

serial_writer::write_to_serial(std::vector<double> positions, std::vector<double> times, int n_points){
    int fd;
    std::string buffer;

    if(positions.size() != times.size())
    {
        throw std::invalid_argument("Invalid 'size' arguments.");
    }
    if((fd=serialOpen("/dev/ttyACM0",115200))<0){
        throw std::logic_error("Unable to open serial device.\n");
    }

    for(int i=0; i < positions.size(); ++i)
    {
        if(i==0){buffer += "{"}
        buffer += std::to_string(positions[i]) + ",";
    }
    buffer = buffer.pop_back() + "}";
    for(int i=0; i < times.size(); ++i)
    {
        if(i==0){buffer += "{"}
        buffer += std::to_string(times[i]) + ",";
    }

    buffer = buffer.pop_back() + "}";
    buffer = buffer + "{" + std::to_string(n_points) + "}";
    std::cout << buffer << endl;
    //serialFlush(fd); no se si hace falta o va aqui.
    serialPuts(fd, buffer); //este o serialPrintf() ?
    serialClose(fd);
    return 0;
};

