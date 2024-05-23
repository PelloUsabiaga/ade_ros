import io
import os
import random
import time
import flask
import threading

import rclpy
from matplotlib import pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure


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

        self.position_list = [0]
        self.time_list = [time.time()]
        
        self.init_ros()

    def init_ros(self):
        rclpy.init()
        self.rc_node = ros_controler_node(self.position_received_callback)
        self.executor = rclpy.executors.MultiThreadedExecutor()
        self.executor.add_node(self.rc_node)

        self.rc_node_spin_thread = threading.Thread(target=self.executor.spin, daemon=True)
        self.rc_node_spin_thread.start()

    def position_received_callback(self, position, timestamp):
        print("called!")
        self.position_list.append(position)
        self.time_list.append(time.time())


    def create_flask_app(self):
        template_dir = os.path.abspath('src/http_control_panel/http_control_panel/templates')
        app = flask.Flask(__name__, template_folder=template_dir)
        app.add_url_rule("/", "index", self.index_view, methods=('GET', 'POST'))
        app.add_url_rule('/plot.png', "image", self.plot_trajectory_png, methods=('GET', 'POST'))
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

            self.rc_node.send_write_trajectory_request(result.positions, result.times, n_points=30)

            return flask.redirect(flask.url_for('index'))

        plt.plot(self.time_list, self.position_list)
        
        return flask.render_template('index.html', target_position=self.target_position,
                                     current_position=self.target_position, 
                                     trajectory_points=self.trajectory_points, trajectory_times=self.trajectory_times,
                                     default_points=self.points, default_mean_speed=self.mean_speed)

    def create_figure(self):
        fig = Figure()
        axis = fig.add_subplot(1, 1, 1)
        self.time_list.append(time.time())
        self.position_list.append(self.position_list[-1])
        axis.plot(self.time_list, self.position_list)
        return fig
    

    def plot_trajectory_png(self):
        fig = self.create_figure()
        output = io.BytesIO()
        FigureCanvas(fig).print_png(output)
        return flask.Response(output.getvalue(), mimetype='image/png')
    
   

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
