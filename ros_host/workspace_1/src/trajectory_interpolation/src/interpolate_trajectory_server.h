#ifndef interpolate_trajectory_server_file
#define interpolate_trajectory_server_file

#include "trajectory_interpolator.h"
#include "custom_interfaces/srv/interpolate_trajectory.hpp"

class interpolate_trajectory_server
{

private:
    trajectory_interpolator *_trajectory_interpolator;
    // void handle_request(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response);

public:
    interpolate_trajectory_server(int argc, char **argv);
    void dummy();

};

#endif