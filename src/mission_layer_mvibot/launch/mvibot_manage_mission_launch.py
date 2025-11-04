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
    #declare arg
    mvibot_seri_arg=DeclareLaunchArgument(
        'mvibot_seri',
        default_value='mvibot'
    )
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    #path include file
    amcl_include=os.path.join(
        get_package_share_directory('mission_layer_mvibot'),
        'launch',
        'mvibot_amcl_launch.py'
    )
    navigation_include=os.path.join(
        get_package_share_directory('mission_layer_mvibot'),
        'launch',
        'mvibot_navigation_launch.py'
    )
    mission_include=os.path.join(
        get_package_share_directory('mission_layer_mvibot'),
        'launch',
        'mvibot_mission_launch.py'
    )
    
    #run
    manage_mission_group=GroupAction(
        actions=[
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(amcl_include),
                launch_arguments={
                    'mvibot_seri': mvibot_seri
                }.items()
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(navigation_include),
                launch_arguments={
                    'mvibot_seri': mvibot_seri
                }.items()
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(mission_include)
            )
        ]
    )

    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(manage_mission_group)
    return ld