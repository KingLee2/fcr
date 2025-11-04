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
    opennav_coverage_param_file_arg=DeclareLaunchArgument(
        'opennav_coverage_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/param','mvibot_opennav_coverage.yaml')
    )
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart = LaunchConfiguration('autostart')
    opennav_coverage_param_file=LaunchConfiguration('opennav_coverage_param_file')
    param_substitutions = {'autostart': autostart}
    configured_opennav_coverage_params = ParameterFile(
        RewrittenYaml(
            source_file=opennav_coverage_param_file,
            root_key=mvibot_seri,
            param_rewrites=param_substitutions,
            convert_types=True,
        ),
        allow_substs=True,
    )
    opennav_coverage_server_node=Node(
        package='opennav_coverage',
        executable='opennav_coverage',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='coverage_server',
        # plugin='opennav_coverage::CoverageServer',
        respawn=True,
        output='screen',
        parameters=[configured_opennav_coverage_params]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(opennav_coverage_param_file_arg)
    ld.add_action(opennav_coverage_server_node)
    return ld
