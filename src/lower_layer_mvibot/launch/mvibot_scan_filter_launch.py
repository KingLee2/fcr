import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, TextSubstitution, PathJoinSubstitution
#from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
	#declare name-seri argument
	name_seri_arg=DeclareLaunchArgument(
		"mvibot_seri",
		default_value="mvibot"
	)
	#declare path to config file 1
	laser_filter1_arg=DeclareLaunchArgument(
		"param_file_1",
		default_value=os.path.join(
			"/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param",
			"my_laser_config.yaml",
		),
		description="Path to param config of laser filter 1",
	)
	laser_filter2_arg=DeclareLaunchArgument(
		"param_file_2",
		default_value=os.path.join(
			"/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param",
			"my_laser_config1.yaml",
		),
		description="Path to param config of laser filter 2",
	)
	laser_filter3_arg=DeclareLaunchArgument(
		"param_file_3",
		default_value=os.path.join(
			"/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param",
			"my_laser_config3.yaml",
		),
		description="Path to param config of laser filter 3",
	)
	laser_filter4_arg=DeclareLaunchArgument(
		"param_file_4",
		default_value=os.path.join(
			"/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param",
			"my_laser_config2.yaml",
		),
		description="Path to param config of laser filter 4",
        )
	laser_filter1_node=Node(
		# namespace=[TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri")],
		namespace = LaunchConfiguration("mvibot_seri"),
		name="laser_filter1",
		package="laser_filters",
		executable="scan_to_scan_filter_chain",
		respawn=True,
		remappings=[
                	("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scanf")]),
                	("scan_filtered", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan")])
					],
		parameters=[LaunchConfiguration("param_file_1"),
					{
						"filter2.params.box_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")]
					}],
	)
	laser_filter2_node=Node(
		namespace = LaunchConfiguration("mvibot_seri"),
		name ="laser_filter2",
		package ="laser_filters",
		executable ="scan_to_scan_filter_chain",
		respawn = True,
		remappings=[
					("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera/scanf")]),
					("scan_filtered", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera/scan")])
					],
		parameters=[LaunchConfiguration("param_file_2"),
					{
						"filter2.params.box_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")]
					}],
	)
	laser_filter3_node=Node(
		namespace = LaunchConfiguration("mvibot_seri"),
		name="laser_filter3",
		package="laser_filters",
		executable="scan_to_scan_filter_chain",
		respawn=True,
		remappings=[
					("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera/scan")]),
					("scan_filtered", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/camera/scan_m5")])
					],
		parameters=[LaunchConfiguration("param_file_3"),
					{
						"filter3.params.box_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")]
					}],
        )
	laser_filter4_node=Node(
		namespace = LaunchConfiguration("mvibot_seri"),
		name="laser_filter4",
		package="laser_filters",
		executable="scan_to_scan_filter_chain",
		respawn=True,
		remappings=[
					("scan", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan")]),
					("scan_filtered", [TextSubstitution(text="/"), LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/laser/scan_m5")])
					],
		parameters=[LaunchConfiguration("param_file_4"),
					{
						"filter1.params.box_frame": [LaunchConfiguration("mvibot_seri"), TextSubstitution(text="/base_link")]
					}],
        )
	ld = LaunchDescription()
	ld.add_action(name_seri_arg)
	ld.add_action(laser_filter1_arg)
	ld.add_action(laser_filter2_arg)
	ld.add_action(laser_filter3_arg)
	ld.add_action(laser_filter4_arg)
	ld.add_action(laser_filter1_node)
	ld.add_action(laser_filter2_node)
	ld.add_action(laser_filter3_node)
	ld.add_action(laser_filter4_node)
	return ld
