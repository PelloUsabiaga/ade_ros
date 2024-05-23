import os
import flask
import threading

import rclpy


from .ros_controler_node import ros_controler_node
from .serial_controler_client import serial_controller_client

class http_control_panel:

    def __init__(self):

        self.target_position = 0
        self.current_position = 0

        self.trajectory_points = []
        self.trajectory_times = []

        self.points = 3
        self.mean_speed = 0.1
        
        self.init_ros()

    def init_ros(self):
        rclpy.init()
        self.rc_node = ros_controler_node()
        self.serial_node = serial_controller_client()
        self.executor = rclpy.executors.MultiThreadedExecutor()
        self.executor.add_node(self.rc_node)

    

        self.rc_node_spin_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.rc_node_spin_thread.start()


    def create_flask_app(self):
        template_dir = os.path.abspath('src/http_control_panel/http_control_panel/templates')
        print(template_dir)
        app = flask.Flask(__name__, template_folder=template_dir)
        app.add_url_rule("/", "index", self.index_view, methods=('GET', 'POST'))
        app.add_url_rule("/add/<number>", "/add/<number>", self.number_view)
        return app

    def index_view(self):
        if flask.request.method == 'POST':
            new_target_position = flask.request.form['new_target_position']
            if ("" != flask.request.form['mean_speed']):
                self.mean_speed = flask.request.form['mean_speed']
            if ("" != flask.request.form['points']):
                self.points = flask.request.form['points']
            self.target_position = new_target_position
            result = self.rc_node.send_get_trajectory_request(self.current_position, self.target_position, self.mean_speed, self.points)
            self.trajectory_points = result.positions
            self.trajectory_times = result.times
            self.current_position = new_target_position

            self.serial_node.send_write_request(result.positions, result.times, n_points=30)

            return flask.redirect(flask.url_for('index'))

        return flask.render_template('index.html', target_position=self.target_position,
                                     current_position=self.target_position, 
                                     trajectory_points=self.trajectory_points, trajectory_times=self.trajectory_times,
                                     default_points=self.points, default_mean_speed=self.mean_speed)


    def number_view(self, number):
        int_number = int(number)

        result = self.rc_node.send_get_trajectory_request(0, 10, 1, 7)
        self.serial_node.send_write_request(result.positions, result.times, n_points=30)
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
