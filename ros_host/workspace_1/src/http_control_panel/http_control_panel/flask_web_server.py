from flask import Flask 
import rclpy

from custom_interfaces.srv import InterpolateTrajectory

from rclpy.node import Node

class ros_controler_node(Node):
    def __init__(self):
        super().__init__("ros_controler_in_http_panel")

        self.cli = self.create_client(InterpolateTrajectory, "interpolate_trajectory")
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service not available, waiting again...")
        self.req = InterpolateTrajectory.Request()
        

    def send_get_trajectory_request(self, number):
        self.req.a = number
        self.req.b = number
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()



class http_control_panel:

    def __init__(self):
        rclpy.init()
        self.rc_node = ros_controler_node()

    def create_flask_app(self):
        app = Flask(__name__)
        app.add_url_rule("/", "index", self.index_view)
        app.add_url_rule("/add/<number>", "/add/<number>", self.number_view)
        return app

    def index_view(self):
        return "Hello world"

    def number_view(self, number):
        int_number = int(number)

        result = self.rc_node.send_get_trajectory_request(int_number)
        return "Hello world {}".format(result.sum)




def main():
    print('Hi from http_control_panel.')
    
    hcp = http_control_panel()

    app = hcp.create_flask_app()
    app.run(host='0.0.0.0')


if __name__ == '__main__':
    main()
