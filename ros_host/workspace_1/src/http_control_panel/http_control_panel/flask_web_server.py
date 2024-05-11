import flask
import threading

import rclpy

from custom_interfaces.srv import InterpolateTrajectory

from rclpy.node import Node

class ros_controler_node(Node):
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



class http_control_panel:

    def __init__(self):

        self.target_position = 0
        self.current_position = 0
        

    def init_ros(self):
        rclpy.init()
        self.rc_node = ros_controler_node()

        self.executor = rclpy.executors.MultiThreadedExecutor()
        self.executor.add_node(self.rc_node)

    

        self.rc_node_spin_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.rc_node_spin_thread.start()


    def create_flask_app(self):
        app = flask.Flask(__name__)
        app.add_url_rule("/", "index", self.index_view, methods=('GET', 'POST'))
        app.add_url_rule("/add/<number>", "/add/<number>", self.number_view)
        return app

    def index_view(self):
        if flask.request.method == 'POST':
            new_target_position = flask.request.form['new_target_position']
            self.target_position = new_target_position
            self.current_position = new_target_position

            return flask.redirect(flask.url_for('index'))

        return flask.render_template('index.html', target_position=self.target_position,
                                     current_position=self.target_position)


    def number_view(self, number):
        int_number = int(number)

        result = self.rc_node.send_get_trajectory_request(0.1, 1.1, 2.1, 3)
        return "Hello world {}, {}".format(result.positions, result.times)

    def close(self):
        self.rc_node_spin_thread.join()



def main():
    print('Hi from http_control_panel.')
    
    hcp = http_control_panel()

    app = hcp.create_flask_app()
    app.run(host='0.0.0.0')

    hcp.close()



if __name__ == '__main__':
    main()
