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
    mvibot_namespace=[TextSubstitution(text='/'),mvibot_seri]
    #path include file
    map_server_include=os.path.join(
        get_package_share_directory('lower_layer_mvibot'),
        'launch',
        'mvibot_map_server_launch.py'
    )
    amcl_include=os.path.join(
        get_package_share_directory('lower_layer_mvibot'),
        'launch',
        'mvibot_amcl_launch.py'
    )
    #run
    localization_group=GroupAction(
        actions=[
            PushROSNamespace(namespace=mvibot_namespace),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(map_server_include)
            ),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(amcl_include)
            ),
        ]
    )

    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(localization_group)
    return ld