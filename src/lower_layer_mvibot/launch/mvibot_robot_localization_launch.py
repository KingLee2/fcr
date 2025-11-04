import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, EmitEvent, LogInfo, RegisterEventHandler
from launch_ros.actions import LifecycleNode, Node
from launch.substitutions import LaunchConfiguration, TextSubstitution, NotSubstitution, AndSubstitution
from launch.events import matches_action
from launch_ros.event_handlers import OnStateTransition
from launch_ros.events.lifecycle import ChangeState
from lifecycle_msgs.msg import Transition
from launch.conditions import IfCondition

def generate_launch_description():
	name_seri_arg=DeclareLaunchArgument(
		"mvibot_seri",
		default_value="mvibot"
	)
	config_param_arg=DeclareLaunchArgument(
		"param_file",
		default_value=os.path.join(
			"/home/mvibot/floorCleaningRobot_ws/src/lower_layer_mvibot/param",
			"ukf.yaml",
		)
	)
	# autostart_arg=DeclareLaunchArgument(
	#	"autostart",
	#	default_value="true",
	#	description='Automatically startup the slamtoolbox. '
        #           	 'Ignored when use_lifecycle_manager is true.'
	# )
	# use_lifecycle_manager_arg=DeclareLaunchArgument(
	#	"use_lifecycle_manager",
	#	default_value="false",
	#	description="enable bond connection during node activation"
	# )

	mvibot_seri=LaunchConfiguration("mvibot_seri")
	param_file=LaunchConfiguration("param_file")
	robot_localization_node=Node(
#	 	namespace=[TextSubstitution(text="/"),mvibot_seri],
		# namespace=mvibot_seri,
		name='robot_localization',
		package='robot_localization',
		executable='ukf_node',
		output='screen',
		respawn=True,
		# parameters=[param_file],
		parameters=[param_file,
			{'odom_frame':[LaunchConfiguration("mvibot_seri"), "/odom"],
	  		'base_link_frame':[LaunchConfiguration("mvibot_seri"), "/base_footprint"],
			'world_frame': [LaunchConfiguration("mvibot_seri"), "/odom"],
			'odom0': ["/",LaunchConfiguration("mvibot_seri"), "/odom_wheel"],
			'imu0': ["/",LaunchConfiguration("mvibot_seri"), "/imu"]}]
	)
#	autostart=LaunchConfiguration("autostart")
#	use_lifecycle_manager=LaunchConfiguration("use_lifecycle_manager")

#	robot_localization_node=LifecycleNode(
#		namespace=[TextSubstitution(text="/"),mvibot_seri],
#		name="robot_localization",
#		package="robot_localization",
#		executable="ukf_node",
#		output="screen",
#		respawn=True,
#		parameters=[param_file],
#	)
#	configure_event=EmitEvent(
#		event=ChangeState(
#			lifecycle_node_matcher=matches_action(robot_localization_node),
#			transition_id=Transition.TRANSITION_CONFIGURE
#		),
#		condition=IfCondition(AndSubstitution(autostart,NotSubstitution(use_lifecycle_manager)))
#	)
#
#	activate_event=RegisterEventHandler(
#		OnStateTransition(
#			target_lifecycle_node=robot_localization_node,
#			start_state="configuring",
#			goal_state="inactive",
#			entities=[
#				LogInfo(msg="robot localization node is activing."),
#				EmitEvent(event=ChangeState(
#					lifecycle_node_matcher=matches_action(robot_localization_node),
#					transition_id=Transition.TRANSITION_ACTIVATE
#				))
#			]
#		),
#		condition=IfCondition(AndSubstitution(autostart,NotSubstitution(use_lifecycle_manager)))
#	)
	ld=LaunchDescription()
	ld.add_action(name_seri_arg)
	ld.add_action(config_param_arg)
#	ld.add_action(autostart_arg)
#	ld.add_action(use_lifecycle_manager_arg)
	ld.add_action(robot_localization_node)
#	ld.add_action(configure_event)
#	ld.add_action(activate_event)
	return ld
