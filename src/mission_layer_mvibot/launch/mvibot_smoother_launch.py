from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode, ParameterFile
from nav2_common.launch import RewrittenYaml
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
    smoother_param_file_arg=DeclareLaunchArgument(
        'smoother_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/param','mvibot_smoother_server.yaml')
    )
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart = LaunchConfiguration('autostart')
    smoother_param_file=LaunchConfiguration('smoother_param_file')
    param_substitutions = {'autostart': autostart}

    configured_smoother_params = ParameterFile(
        RewrittenYaml(
            source_file=smoother_param_file,
            root_key=mvibot_seri,
            param_rewrites=param_substitutions,
            convert_types=True,
        ),
        allow_substs=True,
    )
    smoother_server_node=Node(
        package='nav2_smoother',
        executable='smoother_server',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='smoother_server',
        respawn=True,
        output='screen',
        parameters=[configured_smoother_params]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(smoother_param_file_arg)
    ld.add_action(smoother_server_node)
    return ld
