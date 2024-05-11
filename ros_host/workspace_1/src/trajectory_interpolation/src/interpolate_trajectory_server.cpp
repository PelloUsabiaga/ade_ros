
#include <math.h>
#include <memory>

#include "interpolate_trajectory_server.h"


void interpolate_trajectory_server::handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response)
{
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Icoming request\nCurrent position: %ld" "Target position: %ld" "Mean speed: %ld" "Points: %ld", request->current_position, request->target_position, request->mean_speed, request->points);
	
	trajectory_interpolator::interpolation_type _interoplation_type = trajectory_interpolator::interpolation_type::linear;
	if (request->interpolation_type == "linear")
	{
		_interoplation_type = trajectory_interpolator::interpolation_type::linear;
	}
	else if (request->interpolation_type == "cubic")
	{
		_interoplation_type = trajectory_interpolator::interpolation_type::cubic;
	}
	else
	{
		std::vector<double> empty_response { 0 };
		response->positions = empty_response;
		response->times = empty_response;
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "The interpolation type is not supported, empty response sended.");
		return;
	}

	std::pair<std::vector<double>, std::vector<double>> trajectory_pair = this->_trajectory_interpolator->interpolate_trajectory(request->current_position, request->target_position, request->mean_speed, request->points, _interoplation_type);
	
	response->positions = trajectory_pair.first;
	response->times = trajectory_pair.second;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending response");
}

interpolate_trajectory_server::interpolate_trajectory_server() : Node("interpolate_trajectory_server")
{
	this->_trajectory_interpolator = new trajectory_interpolator();

	
	
	service_ptr_ = this->create_service<custom_interfaces::srv::InterpolateTrajectory>(
                "interpolate_trajectory",
                std::bind(&interpolate_trajectory_server::handle_request, this, 
				std::placeholders::_1, std::placeholders::_2)
        );

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to interpolate trajectories");
}

