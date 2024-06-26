#ifndef SERIAL_WRITER_H
#define SERIAL_WRITER_H

#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

/*
This class takes care of the serial communication with the motor microcontroller.
*/
class serial_writer{
    private:
        int fd;

        void read_from_serial_in_background();
        bool run_in_background;
        std::thread background_thread;
        std::mutex serial_lock; // Since the serial port is used from different threads, it is necessary to guard it.

        std::function<void(const double)> action_on_float_read;
    public:
        // The constructor receives the callback of the position received event, with a simple Observer Pattern.
        serial_writer(const std::string serial_device, const std::function<void(const double)> action_on_float_read);
        ~serial_writer();
        int write_to_serial(const std::vector<double> positions, const std::vector<double> times, const int points);
};
#endif