from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	return LaunchDescription([
		Node(
			package='http_control_panel',
			executable='flask_web_server',
			name='http'
		),
		Node(
			package='serial_controller',
			executable='serial_controller_server',
			name='serial'
		),
		Node(
			package='trajectory_interpolation',
			executable='trajectory_interpolation_server',
			name='interpolation'
		)
	])
