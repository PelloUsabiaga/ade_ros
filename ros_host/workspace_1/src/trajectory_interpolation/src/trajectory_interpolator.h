#ifndef trajectory_interpolator_file
#define trajectory_interpolator_file

#include <math.h>

class trajectory_interpolator
{
public:
    enum interpolation_type { linear, cubic };


private:
    interpolation_type interp_type;

public:
    trajectory_interpolator(interpolation_type _interpolation_type);
    trajectory_interpolator();

    std::pair<float, float> interpolate_trajectory(double current_position, double target_position, double mean_speed, int points);

};

#endif