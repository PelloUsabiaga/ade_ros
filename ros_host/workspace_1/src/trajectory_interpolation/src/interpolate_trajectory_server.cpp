#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/interpolate_trajectory.hpp"

#include <math.h>
#include <memory>

int rc;
static int rate = 200; /*rate in miliseconds*/
struct point{
		int pos;
		int t;
	};
	
struct point points[];

int calculate(int speed, int position, int current_position)
{
	int x0 = 0;
	int local_t = 0;
	float x1;
	float b;
	float a;

	int steps = 10;
	/*Inverse exponential curve trajectory*/
	x1 = x0 + ((float) (position - current_position)) / speed;
	b = pow((((float) position )/ current_position), (1 / -x1));
	a = (float) position*pow(b,x0);					/*If x0=0 is assumed a=position*/

	int i;
	for(i=0; i < steps; i++)
	{

		points[i] -> pos = a*pow(b, -local_t);
		points[i] -> t = local_t;
		local_t += rate;
	}
	return 0;
}

void send_response(const std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Request> request, std::shared_ptr<custom_interfaces::srv::InterpolateTrajectory::Response> response)
{
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Icoming request\nSpeed: %ld" "Position: %ld" "Current position: %ld", request->speed, request->position, request->current_position);
	rc = calculate(request->speed, request->position, request->current_position)

	response->status = rc;	/*STATUS -> 0 = OK | ELSE error*/
	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending response: [%ld]", (long int)response->status);
}


int main(int argc, char **argv)
{
	rclcpp::init(argc, argv);

	std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("interpolate_trajectory_server");

	rclcpp::Service<custom_interfaces::srv::InterpolateTrajectory>::SharedPtr service = node->create_service<custom_interfaces::srv::InterpolateTrajectory>("interpolate_trajectory", &send_response);

	RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to interpolate trajectories");

	rclcpp::spin(node);
	rclcpp::shutdown();
}
