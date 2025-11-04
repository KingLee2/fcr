from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
        tf2_web_republisher_node=Node(
                package='tf2_web_republisher',
                executable='tf2_web_republisher_node',
        )
        return LaunchDescription([tf2_web_republisher_node])
