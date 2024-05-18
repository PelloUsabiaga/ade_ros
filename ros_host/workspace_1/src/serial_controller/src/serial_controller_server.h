#ifndef SERIAL_CONTROLLER_SERVER_H
#define SERIAL_CONTROLER_SERVER_H

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/points_to_serial.hpp"
#include "serial_writer.h"

class serial_controller_server : public rclpp::Node{
    public:
        serial_controller_server();

    private:
        serial_writer *_serial_writer;

        rclcpp::Service<custom_interfaces::srv::points_to_serial>::SharedPtr service_ptr_;

        void serial_request_handler(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
          std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response);
}

#endif 