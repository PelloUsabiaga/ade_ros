#ifndef SERIAL_WRITER_H
#define SERIAL_WRITER_H

#include <vector>
#include <string>
#include <iostream>
#include <thread>

class serial_writer{
    private:
        int fd;
        void read_from_serial_in_background();
        bool run_in_background;
        std::thread background_thread;
    public:
        serial_writer(std::string serial_device);
        ~serial_writer();
        int write_to_serial(std::vector<double> positions, std::vector<double> times, int points);
};
#endif