from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, TextSubstitution

def generate_launch_description():
	#declare mvibot_seri argument for launch file
	name_seri_arg=DeclareLaunchArgument(
		"mvibot_seri",
		default_value="mvibot"
	)
	#Init node to merge 2 lidar data with base_link frame
	LidarScan_Merge_BaseLink_node=Node(
		# namespace=[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri")],
		namespace=LaunchConfiguration("mvibot_seri"),
		name="laserscan_multi_merge1",
		package="ira_laser_tools",
		executable="laserscan_multi_merger",
		output="screen",
		respawn=True,
		parameters=[{
			"destination_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
			"scan_destination_topic": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scanf")],
			# "laserscan_topics": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan1 /"),LaunchConfiguration("mvibot_seri"),TextSubstitution(text="/laser/scan2")],
			"laserscan_topics":[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan1")],
			"angle_min": -3.1415927410125732,
			"angle_max": 3.1415927410125732,
			"angle_increment": 0.01745329251,
			"scan_time": 0.0333333,
			"range_min": 0.0,
			"range_max": 5.0,
		}],
	)
	#Init node to merge 2 camera data with base_link frame
	CameraScan_Merge_BaseLink_node=Node(
		# namespace=[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri")],
		namespace=LaunchConfiguration("mvibot_seri"),
		name="laserscan_multi_merge2",
		package="ira_laser_tools",
		executable="laserscan_multi_merger",
		output="screen",
		respawn=True,
		parameters=[{
				"destination_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
				"scan_destination_topic": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera/scanf")],
				"laserscan_topics": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera1/scan /"),LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera2/scan")],
					"angle_min": -0.58,
					"angle_max": 0.58,
					"angle_increment": 0.01745329251,
					"scan_time": 0.0333333,
					"range_min": 0.0,
					"range_max": 5.0,
			}],
	)
	#Init node to change lidar1's frame from lidar frame to base_link frame
	Lidar1_BaseLink_node=Node(
		namespace=LaunchConfiguration("mvibot_seri"),
		name="laserscan_multi_merge3",
		package="ira_laser_tools",
		executable="laserscan_multi_merger",
		output="screen",
		respawn=True,
		parameters=[{
				"destination_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
				"scan_destination_topic": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/base_link/scan1")],
				"laserscan_topics":[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan1")],
				"angle_min": -3.1415927410125732,
				"angle_max": 3.1415927410125732,
				"angle_increment": 0.005454154219478369,
				"scan_time": 0.0333333,
				"range_min": 0.0,
				"range_max": 5.0,
		}],
        )
	#Init node to change lidar2's frame from lidar frame to base_link frame
	# Lidar2_BaseLink_node=Node(
	# 	namespace=LaunchConfiguration("mvibot_seri"),
	# 	name="laserscan_multi_merge4",
	# 	package="ira_laser_tools",
	# 	executable="laserscan_multi_merger",
	# 	output="screen",
	# 	respawn=True,
	# 	parameters=[{
	# 			"destination_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")],
	# 			"scan_destination_topic": [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/base_link/scan2")],
	# 			"laserscan_topics":[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan2")],
	# 			"angle_min": -3.1415927410125732,
	# 			"angle_max": 3.1415927410125732,
	# 			"angle_increment": 0.005454154219478369,
	# 			"scan_time": 0.0333333,
	# 			"range_min": 0.0,
	# 			"range_max": 5.0,
	# 	}],
    #     )
	ld = LaunchDescription()
	
	ld.add_action(name_seri_arg)
	ld.add_action(LidarScan_Merge_BaseLink_node)
	ld.add_action(CameraScan_Merge_BaseLink_node)
	ld.add_action(Lidar1_BaseLink_node)
	# ld.add_action(Lidar2_BaseLink_node)

	return ld
