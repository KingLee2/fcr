from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
    server_node=Node(
            package='higher_layer_mvibot',
            executable='mvibot_server',
    )
    return LaunchDescription([server_node])