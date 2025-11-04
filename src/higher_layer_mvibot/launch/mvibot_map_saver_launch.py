from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
import os

def generate_launch_description():
    mvibot_seri_arg=DeclareLaunchArgument(
        'mvibot_seri',
        default_value='mvibot'
    )
    declare_autostart_arg = DeclareLaunchArgument(
        'autostart',
        default_value='true',
        description='Automatically startup the nav2 stack',
    )
    lifecycle_nodes = ['map_saver']
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart=LaunchConfiguration('autostart')
    save_map_timeout = 2.0
    free_thresh_default = 0.25
    occupied_thresh_default = 0.65
    map_saver_server_node = Node(
        package='nav2_map_server',
        executable='map_saver_server',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        output='screen',
        emulate_tty=True,  
        parameters=[
            {'save_map_timeout': save_map_timeout},
            {'free_thresh_default': free_thresh_default},
            {'occupied_thresh_default': occupied_thresh_default},
        ],
    )
    lifecycle_manager_node=Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='lifecycle_manager_map_saver',
        respawn=True,
        output='screen',
        parameters=[{'autostart': autostart}, {'node_names': lifecycle_nodes}]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(map_saver_server_node)
    ld.add_action(lifecycle_manager_node)
    return ld
