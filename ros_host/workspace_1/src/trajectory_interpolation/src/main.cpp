#include <iostream>
#include "interpolate_trajectory_server.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<interpolate_trajectory_server> server = std::make_shared<interpolate_trajectory_server>();

    rclcpp::spin(server);
	rclcpp::shutdown();
}