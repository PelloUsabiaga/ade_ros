import rclpy
import sys

from custom_interfaces.srv import PointsToSerial
from rclpy.node import Node

class serial_controller_client(Node):

    def __init__(self):
        super().__init__('serial_controller_client')
        self.cli = self.create_client(PointsToSerial, 'write_serial')

        self.req = PointsToSerial.Request()


    def send_write_request(self, positions, times, n_points, max_connect_retries=2):
        retries = 0
        while not self.cli.wait_for_service(timeout_sec=1.0):
            if retries >= max_connect_retries:
                raise TimeoutError("Service not available, retries limit reached ({}).".format(retries))
            self.get_logger().info("service not available, waiting again...")
            retries += 1
        
        self.req.positions = positions
        self.req.times = times
        self.req.n_points = float(n_points)
        
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()