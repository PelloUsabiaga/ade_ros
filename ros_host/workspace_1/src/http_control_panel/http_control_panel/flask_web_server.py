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


"""
Creates and manages the Flask web server. It creates as a child a ros Node,
to consume the services of the rest of the Nodes, and it receives the motor 
possition from the dedicated topic, in order to plot it.
"""
class http_control_panel:

    def __init__(self):

        self.target_position = 0
        self.current_position = 0

        self.trajectory_points = []
        self.trajectory_times = []

        self.points = 3
        self.mean_speed = 0.1

        self.position_list = [0]
        self.time_list = [0]
        self.start_time = time.time()

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
        self.time_list.append(time.time() - self.start_time)


    """
    Instead of the deffault decorator sintax for flask, add_url_rule methods are used, so that
    the flask app can live inside a class.
    """
    def create_flask_app(self):
        template_dir = os.path.abspath('src/http_control_panel/http_control_panel/templates')
        app = flask.Flask(__name__, template_folder=template_dir)
        app.add_url_rule("/", "index", self.index_view, methods=('GET', 'POST'))
        app.add_url_rule('/plot.png', "image", self.plot_trajectory_png, methods=('GET', 'POST'))
        return app

    def index_view(self):
        if flask.request.method == 'POST':
            if ("" != flask.request.form['mean_speed']):
                self.mean_speed = flask.request.form['mean_speed']
            if ("" != flask.request.form['points']):
                self.points = flask.request.form['points']
            if ("" != flask.request.form['new_target_position']):
                new_target_position = flask.request.form['new_target_position']

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
        time.time()
        current_time_from_beguining = time.time() - self.start_time
        indexes_to_remove = []
        for i, time_i in enumerate(self.time_list):
            if (current_time_from_beguining - time_i) > 120:
                indexes_to_remove.append(i)
        
        for index in sorted(indexes_to_remove, reverse=True):
            del self.time_list[index]
            del self.position_list[index]

        fig = Figure()
        axis = fig.add_subplot(1, 1, 1)
        time_to_plot = self.time_list
        time_to_plot.append(time.time() - self.start_time)
        positions_to_plot = self.position_list
        if (len(self.position_list) != 0):
            positions_to_plot.append(self.position_list[-1])
        else:
            positions_to_plot.append(0)
        axis.plot(time_to_plot, positions_to_plot)
        return fig
    

    def plot_trajectory_png(self):
        fig = self.create_figure()
        output = io.BytesIO()
        FigureCanvas(fig).print_png(output)
        return flask.Response(output.getvalue(), mimetype='image/png')
    
   

    def close(self):
        self.rc_node_spin_thread.join()



"""
Entrypoint of the program.
"""
def main():
    print('Hi from http_control_panel.')
    
    hcp = http_control_panel()

    app = hcp.create_flask_app()
    app.run(host='0.0.0.0')

    hcp.close()



if __name__ == '__main__':
    main()
