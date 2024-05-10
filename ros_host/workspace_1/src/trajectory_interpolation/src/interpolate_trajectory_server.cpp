#include "rclcpp/rclcpp.hpp"

#include <math.h>
#include <memory>

#include "interpolate_trajectory_server.h"


void handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response)
{
	// RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Icoming request\nSpeed: %ld" "Position: %ld" "Current position: %ld", request->speed, request->position, request->current_position);
	// rc = calculate(request->speed, request->position, request->current_position);
	std::cout << request->points;
	std::cout << request->mean_speed;
	// response->status = rc;	/*STATUS -> 0 = OK | ELSE error*/
	// RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending response: [%ld]", (long int)response->status);
}

interpolate_trajectory_server::interpolate_trajectory_server(int argc, char **argv)
{
	trajectory_interpolator::interpolation_type _interoplation_type = trajectory_interpolator::interpolation_type::linear;
	this->_trajectory_interpolator = new trajectory_interpolator(_interoplation_type);

	
	rclcpp::init(argc, argv);
	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("interpolate_trajectory_server");

	rclcpp::Service<custom_interfaces::srv::InterpolateTrajectory>::SharedPtr service = node->create_service<custom_interfaces::srv::InterpolateTrajectory>("interpolate_trajectory", &handle_request);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to interpolate trajectories");

	rclcpp::spin(node);
	rclcpp::shutdown();
}

void interpolate_trajectory_server::dummy(){
	std::cout << "kaixo lagun";
}

