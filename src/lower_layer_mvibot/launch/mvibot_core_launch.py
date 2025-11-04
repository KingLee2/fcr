from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
        # name_seri_arg=DeclareLaunchArgument(
        #         'mvibot_seri',
        #         default_value='mvibot'
        # )
        core_node=Node(
                # namespace=LaunchConfiguration('mvibot_seri'),
                # name='mvibot_core',
                package='lower_layer_mvibot',
                executable='mvibot_core',
        )
        return LaunchDescription([core_node])
