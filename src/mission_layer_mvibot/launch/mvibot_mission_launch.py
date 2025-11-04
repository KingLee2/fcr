from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
    mission_node=Node(
            package='mission_layer_mvibot',
            executable='mvibot_mission',
    )
    return LaunchDescription([mission_node])