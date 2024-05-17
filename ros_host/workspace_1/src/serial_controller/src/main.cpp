#include <iostream>
#include "serial_controller_server.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<Serial_controller_server> server = std::make_shared<Serial_controller_server>();

    rclcpp::spin(server);
    rclcpp::shutdown();
}