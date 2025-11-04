from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
from launch_ros.descriptions import ParameterFile
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
    bt_navigator_param_file_arg=DeclareLaunchArgument(
        'bt_navigator_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/mission_layer_mvibot/param','mvibot_bt_navigator.yaml')
    )
    mvibot_seri=LaunchConfiguration('mvibot_seri')
    autostart = LaunchConfiguration('autostart')
    bt_navigator_param_file=LaunchConfiguration('bt_navigator_param_file')
    param_substitutions = {'autostart': autostart}

    configured_bt_navigator_params = ParameterFile(
        RewrittenYaml(
            source_file=bt_navigator_param_file,
            root_key=mvibot_seri,
            param_rewrites=param_substitutions,
            convert_types=True,
        ),
        allow_substs=True,
    )
    bt_navigator_node=Node(
        package='nav2_bt_navigator',
        executable='bt_navigator',
        namespace=[TextSubstitution(text='/'),mvibot_seri],
        name='bt_navigator',
        respawn=True,
        output='screen',
        parameters=[configured_bt_navigator_params]
    )
    ld=LaunchDescription()
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(bt_navigator_param_file_arg)
    ld.add_action(bt_navigator_node)
    return ld