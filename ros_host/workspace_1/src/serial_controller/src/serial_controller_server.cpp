#include "rclcpp/rclcpp.hpp"
#include "serial_controller_server.h"
#include"serial_writer.h"
#include <memory>


void serial_controller_server::serial_request_handler(const std::shared_ptr<custom_interfaces::srv::PointsToSerial::Request> request,
          std::shared_ptr<custom_interfaces::srv::PointsToSerial::Response> response)
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

serial_controller_server::serial_controller_server() : Node("serial_controller_server") {
	this->_serial_writer = std::make_shared<serial_writer>();

    service_ptr_ = this->create_service<custom_interfaces::srv::PointsToSerial>(
                "write_serial",
                std::bind(&serial_controller_server::serial_request_handler, this, 
				std::placeholders::_1, std::placeholders::_2)
        );

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to write to serial.");
}
