#include <iostream>
#include "interpolate_trajectory_server.h"

int main(int argc, char **argv)
{
	std::cout << "kaixo lucia";
    interpolate_trajectory_server *server = new interpolate_trajectory_server(argc, argv);
    server->dummy();
}