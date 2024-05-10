#include "trajectory_interpolator.h"
#include <math.h>
#include <memory>

trajectory_interpolator::trajectory_interpolator(interpolation_type _interpolation_type)
{

}

trajectory_interpolator::trajectory_interpolator()
{

}

std::pair<std::vector<double>, std::vector<double>> trajectory_interpolator::interpolate_trajectory(double current_position, double target_position, double mean_speed, int points)
{
    std::vector<double> positions { 10, 20, 30 };
    std::vector<double> times { 11, 21, 31 };
    std::pair<std::vector<double>, std::vector<double>> ret_pair;
    ret_pair.first = positions;
    ret_pair.second = times;
    return  ret_pair;
}