
#include <math.h>
#include <memory>

#include "interpolate_trajectory_server.h"


void interpolate_trajectory_server::handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response)
{
	// RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Icoming request\nSpeed: %ld" "Position: %ld" "Current position: %ld", request->speed, request->position, request->current_position);
	// rc = calculate(request->speed, request->position, request->current_position);
	std::cout << request->points;
	std::cout << request->mean_speed;

	std::pair<std::vector<double>, std::vector<double>> trajectory_pair = this->_trajectory_interpolator->interpolate_trajectory(request->current_position, request->target_position, request->mean_speed, request->points);
	
	response->positions = trajectory_pair.first;
	response->times = trajectory_pair.second;
	// response->status = rc;	/*STATUS -> 0 = OK | ELSE error*/
	// RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending response: [%ld]", (long int)response->status);
}

interpolate_trajectory_server::interpolate_trajectory_server() : Node("interpolate_trajectory_server")
{
	trajectory_interpolator::interpolation_type _interoplation_type = trajectory_interpolator::interpolation_type::linear;
	this->_trajectory_interpolator = new trajectory_interpolator(_interoplation_type);

	
	
	service_ptr_ = this->create_service<custom_interfaces::srv::InterpolateTrajectory>(
                "interpolate_trajectory",
                std::bind(&interpolate_trajectory_server::handle_request, this, 
				std::placeholders::_1, std::placeholders::_2)
        );

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to interpolate trajectories");
}

void interpolate_trajectory_server::dummy(){
	std::cout << "kaixo lagun";
}

