from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import GroupAction
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import PushROSNamespace
from ament_index_python import get_package_share_directory
import os

def generate_launch_description():
    # #declare arg
    # mvibot_seri_arg=DeclareLaunchArgument(
    #     'mvibot_seri',
    #     default_value='mvibot'
    # )
    # mvibot_seri=LaunchConfiguration('mvibot_seri')
    #path include file
    
    map_server_include=os.path.join(
        get_package_share_directory('higher_layer_mvibot'),
        'launch',
        'mvibot_map_server_launch.py'
    )
    # slam_toolbox_include=os.path.join(
    #     get_package_share_directory('higher_layer_mvibot'),
    #     'launch',
    #     'mvibot_slam_toolbox_launch.py'
    # )
    server_include=os.path.join(
        get_package_share_directory('higher_layer_mvibot'),
        'launch',
        'mvibot_server_launch.py'
    )
    
    #run
    manage_server_group=GroupAction(
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(map_server_include)
            ),
            # IncludeLaunchDescription(
            #     PythonLaunchDescriptionSource(slam_toolbox_include)
            # ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(server_include)
            )
        ]
    )

    ld=LaunchDescription()
    # ld.add_action(mvibot_seri_arg)
    ld.add_action(manage_server_group)
    return ld