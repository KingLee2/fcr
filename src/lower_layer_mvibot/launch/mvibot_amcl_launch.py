import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node
from launch_ros.descriptions import ParameterFile
from nav2_common.launch import RewrittenYaml

def generate_launch_description():
    # Get the launch directory
    mvibot_seri = LaunchConfiguration('mvibot_seri')
    autostart = LaunchConfiguration('autostart')
    amcl_param_file = LaunchConfiguration('amcl_param_file')

    lifecycle_nodes = ['amcl']

    configured_params = ParameterFile(
        RewrittenYaml(
            source_file=amcl_param_file,
            root_key=mvibot_seri,
            param_rewrites={},
            convert_types=True,
        ),
        allow_substs=True,
    )
    mvibot_seri_arg=DeclareLaunchArgument(
        'mvibot_seri',
        default_value='mvibot'
    )
    declare_autostart_arg = DeclareLaunchArgument(
        'autostart',
        default_value='true',
        description='Automatically startup the nav2 stack',
    )
    amcl_param_file_arg=DeclareLaunchArgument(
        'amcl_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param','amcl.yaml')
    )
 
    amcl_node=Node(
        package='nav2_amcl',
        executable='amcl',
        namespace=[TextSubstitution(text="/"),mvibot_seri],
        name='amcl',
        output='screen',
        respawn=True,
        respawn_delay=2.0,
        parameters=[configured_params],
    )

    amcl_lifecycle_manager_node=Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        namespace=[TextSubstitution(text="/"),mvibot_seri],
        name='lifecycle_manager_amcl',
        output='screen',
        parameters=[{'autostart': autostart}, {'node_names': lifecycle_nodes}],
    )
    ld = LaunchDescription()

    # Declare the launch options
    ld.add_action(mvibot_seri_arg)
    ld.add_action(declare_autostart_arg)
    ld.add_action(amcl_param_file_arg)

    # Add the actions to launch all of the localiztion nodes
    ld.add_action(amcl_node)
    ld.add_action(amcl_lifecycle_manager_node)

    return ld
