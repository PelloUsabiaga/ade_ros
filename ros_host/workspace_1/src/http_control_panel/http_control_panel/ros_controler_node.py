import rclpy

from custom_interfaces.srv import InterpolateTrajectory


class ros_controler_node(rclpy.node.Node):
    def __init__(self):
        super().__init__("ros_controler_in_http_panel")
        self.cli = self.create_client(InterpolateTrajectory, "interpolate_trajectory")

        self.req = InterpolateTrajectory.Request()

        

    def send_get_trajectory_request(self, current_position, target_position, mean_speed, points):
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service not available, waiting again...")

        self.req.current_position = current_position
        self.req.target_position = target_position
        self.req.mean_speed = mean_speed
        self.req.points = points
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()
