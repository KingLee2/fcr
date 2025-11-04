from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import GroupAction
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import PushROSNamespace
import os
from ament_index_python import get_package_share_directory
def generate_launch_description():
	name_seri_arg = DeclareLaunchArgument("mvibot_seri", default_value=TextSubstitution(text="mvibot"))
	seri_camera1_arg= DeclareLaunchArgument("serial_no_1", default_value=TextSubstitution(text="_109622074579"))
	seri_camera2_arg= DeclareLaunchArgument("serial_no_2", default_value=TextSubstitution(text="_317622072985"))
	group_camera1 = GroupAction(
		actions = [
			PushROSNamespace(LaunchConfiguration("mvibot_seri")),
			IncludeLaunchDescription(
				PythonLaunchDescriptionSource(
					os.path.join(
						get_package_share_directory("realsense2_camera"),
						"launch/rs_launch.py")),
				launch_arguments={
					"serial_no": [LaunchConfiguration("serial_no_1")],
					"camera_namespace": "",
					"camera_name": "camera1",
					"publish_tf": "true",
					"tf_publish_rate": "2.0",
                    "base_frame_id": LaunchConfiguration("mvibot_seri"),
					"initial_reset": "true",
					"clip_distance": "4.0",
					#"diagnostics_period": "1.0",
					"pointcloud.enable": "true",
					"respawn": "true",
				}.items()
			),
		]
	)
	group_camera2 = GroupAction(
        actions = [
            PushROSNamespace(LaunchConfiguration("mvibot_seri")),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    os.path.join(
                        get_package_share_directory("realsense2_camera"),
                        "launch/rs_launch.py")),
                launch_arguments={
                    "serial_no": [LaunchConfiguration("serial_no_2")],
                    "camera_namespace":"",
                    "camera_name": "camera2",
                    "publish_tf": "true",
                    "tf_publish_rate": "2.0",
                    "base_frame_id": LaunchConfiguration("mvibot_seri"),
                    "initial_reset": "true",
                    "clip_distance": "4.0",
                    #"diagnostics_period": "1.0",
                    "pointcloud.enable": "true",
                    "enable_gyro": "true",
                    "enable_accel": "true",
                    "unite_imu_method": "2",
                    "hold_back_imu_for_frames": "true",
                    "respawn": "true",
                }.items()
            ),
        ]
	)
	return LaunchDescription([name_seri_arg, seri_camera1_arg, seri_camera2_arg, group_camera1, group_camera2])
