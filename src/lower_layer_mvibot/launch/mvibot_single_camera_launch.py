from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
import os

def generate_launch_description():
    name_seri_arg = DeclareLaunchArgument("mvibot_seri", default_value=TextSubstitution(text="mvibot"))
    seri_camera1_arg= DeclareLaunchArgument("serial_no_1", default_value=TextSubstitution(text="_109622074579"))
    # seri_camera1_arg= DeclareLaunchArgument("serial_no_1", default_value=TextSubstitution(text="_336222075697"))
    seri_camera2_arg= DeclareLaunchArgument("serial_no_2", default_value=TextSubstitution(text="_317622072985"))
    # seri_camera2_arg= DeclareLaunchArgument("serial_no_2", default_value=TextSubstitution(text="_243222076688"))
    camera_D435_param_file_arg=DeclareLaunchArgument(
        'camera_D435_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param','camera_D435_param_file.yaml')
    )
    camera_D435i_param_file_arg=DeclareLaunchArgument(
        'camera_D435i_param_file',
        default_value=os.path.join('/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param','camera_D435i_param_file.yaml')
    )
    camera_D435_node = Node(
        namespace = LaunchConfiguration('mvibot_seri'),
        name = 'camera1',
        package='realsense2_camera',
        executable='realsense2_camera_node',
        parameters = [
            LaunchConfiguration('camera_D435_param_file'),
            {"serial_no": [LaunchConfiguration("serial_no_1")],
            "base_frame_id": LaunchConfiguration("mvibot_seri"),
            #"diagnostics_period": "1.0",
            "respawn": "true"}],
        output = "screen",
    )
    camera_D435i_node = Node(
        namespace = LaunchConfiguration('mvibot_seri'),
        name = 'camera2',
        package='realsense2_camera',
        executable='realsense2_camera_node',
        parameters = [
            LaunchConfiguration('camera_D435i_param_file'),
            {"serial_no": [LaunchConfiguration("serial_no_2")],
            "base_frame_id": LaunchConfiguration("mvibot_seri"),
            #"diagnostics_period": "1.0",
            "respawn": "true"}],
        output = "screen",
    )
    ld = LaunchDescription()
    ld.add_action(name_seri_arg)
    ld.add_action(seri_camera1_arg)
    ld.add_action(seri_camera2_arg)
    ld.add_action(camera_D435_param_file_arg)
    ld.add_action(camera_D435i_param_file_arg)
    ld.add_action(camera_D435_node)
    ld.add_action(camera_D435i_node)
    return ld