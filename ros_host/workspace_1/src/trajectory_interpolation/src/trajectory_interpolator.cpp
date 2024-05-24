#include <string>
#include "trajectory_interpolator.h"
#include <math.h>
#include <memory>
#include <stdexcept>


trajectory_interpolator::trajectory_interpolator()
{

}

std::pair<std::vector<double>, std::vector<double>> trajectory_interpolator::interpolate_trajectory(double current_position, 
                                    double target_position, double mean_speed, int points, interpolation_type interpolation_type)
{
    if (interpolation_type == interpolation_type::linear)
    {
        std::vector<double> positions(points, 0);;
        std::vector<double> times(points, 0);

        double total_distance = (target_position - current_position);
        double distance_delta = total_distance / (points - 1);

        double total_time = std::abs(total_distance)/mean_speed;
        double time_delta = total_time / (points - 1);

        for (int i = 0; i < points; i++) 
        {
            times[i] = time_delta*i;
            positions[i] = current_position + distance_delta*i;
        }
        std::pair<std::vector<double>, std::vector<double>> ret_pair;
        ret_pair.first = positions;
        ret_pair.second = times;
        return  ret_pair;
    }
    else if (interpolation_type == interpolation_type::cubic) // Currently cubic interpolation is not implemented. Return dummy response.
    {
        std::vector<double> positions { 10, 20, 30 };
        std::vector<double> times { 11, 21, 31 };
        std::pair<std::vector<double>, std::vector<double>> ret_pair;
        ret_pair.first = positions;
        ret_pair.second = times;
        return  ret_pair;
    }
    else
    {
        throw std::invalid_argument("Interpolation type is not supported");
    }
}