#include "rclcpp/rclcpp.hpp"
#include "serial_controller_server.h"
#include"serial_writer.h"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

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

void serial_controller_server::motor_position_readed_callback(const double position){
    auto message = custom_interfaces::msg::PositionMeasurement();
    message.position = position;

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");

    auto str_timestamp = oss.str();
    message.timestamp = str_timestamp;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.position);
    this->publisher_->publish(message);
}

serial_controller_server::serial_controller_server() : Node("serial_controller_server") {
    
    this->declare_parameter("serial_device", "/dev/ttyUSB0");

    std::string serial_device = this->get_parameter("serial_device").as_string();
    std::function<void(double)> callback_function = std::bind(&serial_controller_server::motor_position_readed_callback, this, std::placeholders::_1);

	this->_serial_writer = std::make_shared<serial_writer>(serial_device, callback_function);

    this->service_ptr_ = this->create_service<custom_interfaces::srv::PointsToSerial>(
                "write_serial",
                std::bind(&serial_controller_server::serial_request_handler, this, 
				std::placeholders::_1, std::placeholders::_2)
        );

    this->publisher_ = this->create_publisher<custom_interfaces::msg::PositionMeasurement>("motor_position", 10);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to write to serial.");
}
