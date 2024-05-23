from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="serial_controller",
            executable="serial_controller_server",
            name="serial_controller_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"serial_device": "/dev/ttyUSB0"}
            ]
        )
    ])