#ifndef SERIAL_WRITER_H
#define SERIAL_WRITER_H

#include <vector>
#include <string>
#include <iostream>

class serial_writer{
    private:
        int fd;
    public:
        serial_writer(std::string serial_device);
        int write_to_serial(std::vector<double> positions, std::vector<double> times, int points);
};
#endif