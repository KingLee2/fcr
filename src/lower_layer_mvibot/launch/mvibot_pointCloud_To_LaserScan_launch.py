from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
	name_seri_arg=DeclareLaunchArgument(
		"mvibot_seri",
		default_value="mvibot"
	)
	pointcloud_to_laserscan1_node=Node(
		# namespace=[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri")],
		namespace=LaunchConfiguration("mvibot_seri"),
		name="PointCloud_To_LaserScan1",
		package="pointcloud_to_laserscan",
		executable="pointcloud_to_laserscan_node",
		respawn=True,
		remappings=[
			("cloud_in", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera1/depth/color/points")]),
			("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera1/scan")])
		],
		parameters=[{
			"target_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
			"transform_tolerance": 0.01,
			"min_height": 0.05,
			"max_height": 2.0,
			"angle_min": -3.1400001049,
			"angle_max": 3.1400001049,
			"angle_increment": 0.0174532923847,
			"scan_time": 0.3333,   #0.3333
			"range_min": 0.0,
			"range_max": 3.0,   #3.0
			"use_inf": True,
			# "queue_size": 50
			# "inf_epsilon": 1.0
		}],
	)
	pointcloud_to_laserscan2_node=Node(
		# namespace=[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri")],
		namespace=LaunchConfiguration("mvibot_seri"),
		name="PointCloud_To_LaserScan2",
		package="pointcloud_to_laserscan",
		executable="pointcloud_to_laserscan_node",
		respawn=True,
		remappings=[
			("cloud_in", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera2/depth/color/points")]),
			("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera2/scan")])
		],
		parameters=[{
			"target_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
			"transform_tolerance": 0.01,
			"min_height": 0.05,
			"max_height": 2.0,
			"angle_min": -3.1400001049,
			"angle_max": 3.1400001049,
			"angle_increment": 0.0174532923847,
			"scan_time": 0.3333,  #0.3333
			"range_min": 0.0,
			"range_max": 3.0,     #3.0
			"use_inf": True,
			# "queue_size": 50
			# "inf_epsilon": 1.0
		}],
	)
	return LaunchDescription([name_seri_arg, pointcloud_to_laserscan1_node, pointcloud_to_laserscan2_node])
