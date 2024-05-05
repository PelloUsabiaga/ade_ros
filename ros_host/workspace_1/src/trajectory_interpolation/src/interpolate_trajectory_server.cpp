#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/interpolate_trajectory.hpp"

#include <memory>

void add(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response)
{
	response->sum = request->a +request->b;
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Icoming request\na: %ld" "b: %ld", request->a, request->b);
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending response: [%ld]", (long int)response->sum);
}


int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);

	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("interpolate_trajectory_server");

	rclcpp::Service<custom_interfaces::srv::InterpolateTrajectory>::SharedPtr service = node->create_service<custom_interfaces::srv::InterpolateTrajectory>("interpolate_trajectory", &add);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to interpolate trajectories");

	rclcpp::spin(node);
	rclcpp::shutdown();
}
