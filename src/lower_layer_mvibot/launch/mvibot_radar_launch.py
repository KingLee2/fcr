from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
        name_seri_arg=DeclareLaunchArgument(
                'mvibot_seri',
                default_value='mvibot'
        )
        rplidar1_node=Node(
                namespace=LaunchConfiguration('mvibot_seri'),
                name='rplidarNode1',
                package='sllidar_ros2',
                executable='sllidar_node',
                output='screen',
                respawn=True,
                remappings=[
                        ('scan',[TextSubstitution(text='/'),LaunchConfiguration('mvibot_seri'),TextSubstitution(text='/laser/scan1')])
                ],
                parameters=[{
                        'serial_port': '/dev/rplidar1',
                        'serial_baudrate': 115200, #256000,
                        'frame_id': [LaunchConfiguration('mvibot_seri'),TextSubstitution(text='/base_lidar_1')],
                        'inverted': False,
                        'angle_compensate': True,
                }],
        )
        # rplidar2_node=Node(
        #         namespace=LaunchConfiguration('mvibot_seri'),
        #         name='rplidarNode2',
        #         package='sllidar_ros2',
        #         executable='sllidar_node',
        #         output='screen',
        #         respawn=True,
        #         remappings=[
        #                 ('scan',[TextSubstitution(text='/'),LaunchConfiguration('mvibot_seri'),TextSubstitution(text='/laser/scan2')])
        #         ],
        #         parameters=[{
        #                 'serial_port': '/dev/rplidar2',
        #                 'serial_baudrate': 115200,
        #                 'frame_id': [LaunchConfiguration('mvibot_seri'),TextSubstitution(text='/base_lidar_2')],
        #                 'inverted': False,
        #                 'angle_compensate': True,
        #         }],
        # )
        # return LaunchDescription([name_seri_arg, rplidar1_node, rplidar2_node])
        return LaunchDescription([name_seri_arg, rplidar1_node])
