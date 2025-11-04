import os
import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
import launch_ros.actions

def generate_launch_description():
    # path to URDF file
    urdf_path = os.path.join(
        '/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/urdf',
        'fcr.urdf'
        # 'mvibot3.urdf'
    )
    mvibot_seri_arg = DeclareLaunchArgument(
        name='mvibot_seri',
        default_value='mvibot',
        description='Robot namespace'
    )
    urdf_path_arg = DeclareLaunchArgument(
            name='model', 
            default_value=urdf_path,
            description='Absolute path to robot URDF file'
        )
    # Node robot_state_publisher
    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': launch_ros.descriptions.ParameterValue( launch.substitutions.Command(['xacro ',urdf_path, ' mvibot_seri:=', LaunchConfiguration('mvibot_seri')]), value_type=str)},
                    {'use_sim_time': False}]
    )

    # Declare LaunchDescription
    return LaunchDescription([
        mvibot_seri_arg,
        urdf_path_arg,
        robot_state_publisher_node
    ])
