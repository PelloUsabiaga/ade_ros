#ifndef interpolate_trajectory_server_file
#define interpolate_trajectory_server_file

#include "rclcpp/rclcpp.hpp"

#include "trajectory_interpolator.h"
#include "custom_interfaces/srv/interpolate_trajectory.hpp"
#include <vector>

class interpolate_trajectory_server : public rclcpp::Node
{

private:
    rclcpp::Service<custom_interfaces::srv::InterpolateTrajectory>::SharedPtr service_ptr_;

    trajectory_interpolator *_trajectory_interpolator;
    void handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response);

public:
    interpolate_trajectory_server();
    void dummy();

};

#endif