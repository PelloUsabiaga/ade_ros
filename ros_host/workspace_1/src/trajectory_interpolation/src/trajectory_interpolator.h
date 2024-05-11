#ifndef trajectory_interpolator_file
#define trajectory_interpolator_file

#include <math.h>
#include <vector>

class trajectory_interpolator
{
public:
    enum interpolation_type { linear, cubic };


public:
    trajectory_interpolator();

    std::pair<std::vector<double>, std::vector<double>> interpolate_trajectory(double current_position, 
                double target_position, double mean_speed, int points, interpolation_type interpolation_type);

};

#endif