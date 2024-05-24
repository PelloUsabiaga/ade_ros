#ifndef trajectory_interpolator_file
#define trajectory_interpolator_file

#include <math.h>
#include <vector>


/*
This class interpolates trajectories for the Node.
*/
class trajectory_interpolator
{
public:
    enum interpolation_type { linear, cubic };


public:
    trajectory_interpolator();

    std::pair<std::vector<double>, std::vector<double>> interpolate_trajectory(const double current_position, 
                                    const double target_position, const double mean_speed, const int points, 
                                    const interpolation_type interpolation_type);

};

#endif