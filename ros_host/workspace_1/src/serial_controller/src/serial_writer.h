#ifndef SERIAL_WRITER_H
#define SERIAL_WRITER_H

#include <vector>

class Serial_writer{
    public:
        Serial_writer();
        int write_to_serial(std::vector<double> positions, std::vector<double> times, int points);
};
#endif