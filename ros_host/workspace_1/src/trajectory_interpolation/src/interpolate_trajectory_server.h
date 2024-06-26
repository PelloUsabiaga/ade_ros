#ifndef interpolate_trajectory_server_file
#define interpolate_trajectory_server_file

#include "rclcpp/rclcpp.hpp"

#include "trajectory_interpolator.h"
#include "custom_interfaces/srv/interpolate_trajectory.hpp"
#include <vector>


/*
This node takes care of the service to interpolate trajectories, and enshures that the message content
is adecuate.
*/
class interpolate_trajectory_server : public rclcpp::Node
{

private:
    rclcpp::Service<custom_interfaces::srv::InterpolateTrajectory>::SharedPtr service_ptr_;

    std::shared_ptr<trajectory_interpolator> _trajectory_interpolator;
    void handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response);

public:
    interpolate_trajectory_server();
};

#endif