import rclpy

from custom_interfaces.srv import InterpolateTrajectory
from custom_interfaces.srv import PointsToSerial
from custom_interfaces.msg import PositionMeasurement

from rclpy.node import Node


class ros_controler_node(Node):
    def __init__(self, position_received_callback):
        super().__init__("ros_controler_in_http_panel")
        self.position_received_callback = position_received_callback


        self.interpolation_client = self.create_client(InterpolateTrajectory, "interpolate_trajectory")
        self.interpolate_request = InterpolateTrajectory.Request()

        self.allowed_interpolations = ("linear", "cubic")

        self.points_to_serial_client = self.create_client(PointsToSerial, 'write_serial')
        self.points_to_serial_request = PointsToSerial.Request()

        self.position_subscription = self.create_subscription(
            PositionMeasurement,
            'motor_position',
            self.motor_position_received_callback,
            10)
        
    def motor_position_received_callback(self, msg):
        self.get_logger().info("Position received: {} at time: {}".format(msg.position, msg.timestamp))
        self.position_received_callback(msg.position, msg.timestamp)

    def send_get_trajectory_request(self, current_position, target_position, mean_speed, points, interpolation_type="linear", max_connect_retries=2):
        if interpolation_type not in self.allowed_interpolations:
            raise ValueError("Interpolation type {} not supported. Use only: {}.".format(interpolation_type, self.allowed_interpolations))
        
        retries = 0
        while not self.interpolation_client.wait_for_service(timeout_sec=1.0):
            if retries >= max_connect_retries:
                raise TimeoutError("Service not available, retries limit reached ({}).".format(retries))
            self.get_logger().info("service not available, waiting again...")
            retries += 1

        self.interpolate_request.current_position = float(current_position)
        self.interpolate_request.target_position = float(target_position)
        self.interpolate_request.mean_speed = float(mean_speed)
        self.interpolate_request.points = int(points)
        self.interpolate_request.interpolation_type = str(interpolation_type)
        result = self.interpolation_client.call(self.interpolate_request)

        return result
    
    def send_write_trajectory_request(self, positions, times, n_points, max_connect_retries=2):
        retries = 0
        while not self.points_to_serial_client.wait_for_service(timeout_sec=1.0):
            if retries >= max_connect_retries:
                raise TimeoutError("Service not available, retries limit reached ({}).".format(retries))
            self.get_logger().info("service not available, waiting again...")
            retries += 1
        
        self.points_to_serial_request.positions = positions
        self.points_to_serial_request.times = times
        self.points_to_serial_request.n_points = float(n_points)
        
        result = self.points_to_serial_client.call(self.points_to_serial_request)
        return result
