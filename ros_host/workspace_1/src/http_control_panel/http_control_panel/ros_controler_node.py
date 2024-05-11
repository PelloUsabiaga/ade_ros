import rclpy

from custom_interfaces.srv import InterpolateTrajectory
from rclpy.node import Node


class ros_controler_node(Node):
    def __init__(self):
        super().__init__("ros_controler_in_http_panel")
        self.cli = self.create_client(InterpolateTrajectory, "interpolate_trajectory")

        self.req = InterpolateTrajectory.Request()

        self.allowed_interpolations = ("linear", "cubic")

        

    def send_get_trajectory_request(self, current_position, target_position, mean_speed, points, interpolation_type="linear", max_connect_retries=2):
        if interpolation_type not in self.allowed_interpolations:
            raise ValueError("Interpolation type {} not supported. Use only: {}.".format(interpolation_type, self.allowed_interpolations))
        
        retries = 0
        while not self.cli.wait_for_service(timeout_sec=1.0):
            if retries >= max_connect_retries:
                raise TimeoutError("Service not available, retries limit reached ({}).".format(retries))
            self.get_logger().info("service not available, waiting again...")
            retries += 1

        self.req.current_position = float(current_position)
        self.req.target_position = float(target_position)
        self.req.mean_speed = float(mean_speed)
        self.req.points = int(points)
        self.req.interpolation_type = str(interpolation_type)
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
