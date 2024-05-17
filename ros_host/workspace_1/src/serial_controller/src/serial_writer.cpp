#include <stdexcept>
#include <iostream>
#include "serial_writer.h"


Serial_writer::Serial_writer(){};

Serial_writer::write_to_serial(std::vector<double> positions, std::vector<double> times, int n_points){
    if(positions.size() != times.size())
    {
        throw std::invalid_argument("Invalid 'size' arguments.");
    }
    std::cout << positions << times << n_points;
    return 0;
};

