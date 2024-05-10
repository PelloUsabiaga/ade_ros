#include "trajectory_interpolator.h"

trajectory_interpolator::trajectory_interpolator(interpolation_type _interpolation_type)
{

}

trajectory_interpolator::trajectory_interpolator()
{

}

std::pair<float, float> trajectory_interpolator::interpolate_trajectory(double current_position, double target_position, double mean_speed, int points)
{
    // std::vector<float> positions { 10, 20, 30 };
    // std::vector<float> times { 11, 21, 31 };
    std::pair<float, float> ret_pair;
    ret_pair.first = 10.2;
    ret_pair.second = 10.3;
    return  ret_pair;
}