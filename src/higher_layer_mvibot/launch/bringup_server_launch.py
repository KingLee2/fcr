import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource

from launch_ros.actions import Node


def generate_launch_description():

    # Load mode: navigation / slam
    mode_file = "/home/mvibot/floorCleaningRobot_ws/config/mode"
    mode = "navigation"
    if os.path.exists(mode_file):
        with open(mode_file, "r") as f:
            mode = f.read().strip()

    # Paths
    pkg_path = os.path.join(
        os.getenv("HOME"),
        # "mvibot",
        "floorCleaningRobot_ws",
        "install",
        "higher_layer_mvibot"
    )

    # Launch paths
    tf2_launch = os.path.join(pkg_path, "share/higher_layer_mvibot/launch/tf2_web_republisher_launch.py")
    map_saver_launch = os.path.join(pkg_path, "share/higher_layer_mvibot/launch/mvibot_map_saver_launch.py")
    slam_launch = os.path.join(pkg_path, "share/higher_layer_mvibot/launch/mvibot_slam_toolbox_launch.py")
    map_server_launch = os.path.join(pkg_path, "share/higher_layer_mvibot/launch/mvibot_map_server_launch.py")
    server_launch = os.path.join(pkg_path, "share/higher_layer_mvibot/launch/mvibot_server_launch.py")

    # rosbridge launch (XML)
    rosbridge_launch = os.path.join(
        "/opt/ros/jazzy/share/rosbridge_server/launch/rosbridge_websocket_launch.xml"
    )

    # Bringup description
    ld = LaunchDescription()

    ld.add_action(
        IncludeLaunchDescription(
            XMLLaunchDescriptionSource(rosbridge_launch)
        )
    )

    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(tf2_launch)
        )
    )

    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(map_saver_launch)
        )
    )

    if mode == "slam":
        ld.add_action(
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(slam_launch)
            )
        )
    else:
        ld.add_action(
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(map_server_launch)
            )
        )

    ld.add_action(
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(server_launch)
        )
    )

    return ld
