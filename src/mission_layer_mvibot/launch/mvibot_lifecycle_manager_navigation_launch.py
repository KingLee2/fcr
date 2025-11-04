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
    lifecycle_nodes = [
        'planner_server',
        'coverage_server',
        'controller_server',
        'behavior_server',
        'bt_navigator',
        'smoother_server',
        # 'velocity_smoother',
        # 'collision_monitor',
        # 'waypoint_follower',
        # 'docking_server',
    ]
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart=LaunchConfiguration('autostart')
    lifecycle_manager_node=Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='lifecycle_manager_navigation',
        respawn=True,
        output='screen',
        parameters=[{'autostart': autostart}, {'node_names': lifecycle_nodes}]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(lifecycle_manager_node)
    return ld