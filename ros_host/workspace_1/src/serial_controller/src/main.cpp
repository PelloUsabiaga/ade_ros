#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include "serial_controller_server.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<serial_controller_server> server = std::make_shared<serial_controller_server>();

    rclcpp::spin(server);
    rclcpp::shutdown();
}