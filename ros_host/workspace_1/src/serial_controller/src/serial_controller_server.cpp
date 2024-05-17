#include "rclcpp/rclcpp.hpp"
#include "serial_controller_server.h"
#include"serial_writer.h"
#include <memory>


void Serial_controller_server::serial_request_handler(const std::shared_ptr<custom_interfaces::srv::points_to_serial::Request> request,
          std::shared_ptr<custom_interfaces::srv::points_to_serial::Response> response)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request");
    int rc = this -> _serial_writer -> write_to_serial(request -> positions, request -> times, request -> n_points);
    if(rc != 0)
    {
        response -> status = "ERROR: can't write to serial";
    }
    else
    {
        response -> status = "OK";
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back response.");
}

Serial_controller_server::Serial_controller_server() : Node("serial_controller_server") {
    this -> _serial_writer = new Serial_writer();

    service_ptr_ = this->create_service<custom_interfaces::srv::points_to_serial>(
                "write_serial",
                std::bind(&Serial_controller_server::serial_request_handler, this, 
				std::placeholders::_1, std::placeholders::_2)
        );

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to write to serial.")
}
