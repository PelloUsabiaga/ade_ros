#include <iostream>
#include "interpolate_trajectory_server.h"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    // interpolate_trajectory_server server = interpolate_trajectory_server();


    // interpolate_trajectory_server *server = new interpolate_trajectory_server();
    // std::shared_ptr<rclcpp::Node> server = interpolate_trajectory_server::make_shared();
    std::shared_ptr<interpolate_trajectory_server> server = std::make_shared<interpolate_trajectory_server>();
    // server->dummy();

    rclcpp::spin(server);
	rclcpp::shutdown();
}