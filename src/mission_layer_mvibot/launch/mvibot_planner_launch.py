from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
from nav2_common.launch import RewrittenYaml
from launch_ros.descriptions import ComposableNode, ParameterFile
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
    planner_param_file_arg=DeclareLaunchArgument(
        'planner_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/param','mvibot_planner_server.yaml')
    )
    costmap_param_file_arg=DeclareLaunchArgument(
        'costmap_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/param','mvibot_costmap_2d.yaml')
    )
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart = LaunchConfiguration('autostart')
    planner_param_file=LaunchConfiguration('planner_param_file')
    costmap_param_file=LaunchConfiguration('costmap_param_file')
    param_substitutions = {'autostart': autostart}
    configured_planner_params = ParameterFile(
        RewrittenYaml(
            source_file=planner_param_file,
            root_key=mvibot_seri,
            param_rewrites=param_substitutions,
            convert_types=True,
        ),
        allow_substs=True,
    )
    configured_costmap_params = ParameterFile(
        RewrittenYaml(
            source_file=costmap_param_file,
            root_key=mvibot_seri,
            param_rewrites=param_substitutions,
            convert_types=True,
        ),
        allow_substs=True,
    )
    planner_server_node=Node(
        package='nav2_planner',
        executable='planner_server',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='planner_server',
        respawn=True,
        output='screen',
        parameters=[configured_planner_params,configured_costmap_params]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(planner_param_file_arg)
    ld.add_action(costmap_param_file_arg)
    ld.add_action(planner_server_node)
    return ld
