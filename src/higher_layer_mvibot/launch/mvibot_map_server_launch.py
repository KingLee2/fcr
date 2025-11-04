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
    map_yaml_file_arg=DeclareLaunchArgument(
        'map_yaml_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/higher_layer_mvibot/maps','28_11ok.yaml')
        # default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/higher_layer_mvibot/param','mvibot_map_server.yaml')
    )
    declare_autostart_arg = DeclareLaunchArgument(
        'autostart',
        default_value='true',
        description='Automatically startup the nav2 stack',
    )
    lifecycle_nodes = ['map_server']
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    map_yaml_file=LaunchConfiguration('map_yaml_file')
    autostart=LaunchConfiguration('autostart')
    map_server_node=Node(
        package='nav2_map_server',
        executable='map_server',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='map_server',
        respawn=True,
        output='screen',
        # parameters=[{'yaml_filename': map_yaml_file}]
        parameters=[{'yaml_filename': map_yaml_file},{'frame_id': "map"}]
    )
    lifecycle_manager_node=Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='lifecycle_manager_map_server',
        respawn=True,
        output='screen',
        parameters=[{'autostart': autostart}, {'node_names': lifecycle_nodes}]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(map_yaml_file_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(map_server_node)
    ld.add_action(lifecycle_manager_node)
    return ld
