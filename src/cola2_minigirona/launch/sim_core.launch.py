import launch
from launch import LaunchDescription
from launch_ros.actions import Node, PushRosNamespace
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    robot_name_arg = DeclareLaunchArgument(
        'robot_name',
        default_value='minigirona',
        description='Name of the robot'
    )

    config_folder_arg = DeclareLaunchArgument(
        'config_folder',
        default_value=os.path.join(
            FindPackageShare('cola2_minigirona').find('cola2_minigirona'), 'sim_config'
        ),
        description='Path to the config folder'
    )

    diagnostic_node = Node(package='cola2_stonefish', executable='cola2_stonefish_node', name='translator',
        remappings=[
            # ('/diagnostics', f'/{LaunchConfiguration("robot_name")}/diagnostics'), TODO
            # ('/diagnostics_agg', f'/{LaunchConfiguration("robot_name")}/diagnostics_agg'),
            # ('/diagnostics_toplevel_state', f'/{LaunchConfiguration("robot_name")}/diagnostics_toplevel_state')
            ('/diagnostics', '/minigirona/diagnostics'),
            ('/diagnostics_agg', '/minigirona/diagnostics_agg'),
            ('/diagnostics_toplevel_state', '/minigirona/diagnostics_toplevel_state')
    ])

    captain_arg = DeclareLaunchArgument(
        'captain_path',
        default_value=[LaunchConfiguration('config_folder'), '/', 'captain.yaml'],
        description='Path to the captain yaml'
    )

    pilot_arg = DeclareLaunchArgument(
        'pilot_path',
        default_value=[LaunchConfiguration('config_folder'), '/', 'pilot.yaml'],
        description='Path to the pilot yaml'
    )

    controller_arg = DeclareLaunchArgument(
        'controller_path',
        default_value=[LaunchConfiguration('config_folder'), '/', 'controller.yaml'],
        description='Path to the controller yaml'
    )

    teleoperation_arg = DeclareLaunchArgument(
        'teleoperation_path',
        default_value=[LaunchConfiguration('config_folder'), '/', 'teleoperation.yaml'],
        description='Path to the teleoperation yaml'
    )

    captain_node = Node(
        package='cola2_control',
        executable='captain_node',
        name='captain',
        output='screen',
        parameters=[LaunchConfiguration('captain_path')],#, {'vehicle_config_launch_mission_package': ['cola2_', LaunchConfiguration('robot_name')]}], TODO
    )

    pilot_node = Node(
        package='cola2_control',
        executable='pilot_node',
        name='pilot',
        output='screen',
        parameters=[LaunchConfiguration('pilot_path')],
    )

    controller_node = Node(
        package='cola2_control',
        executable='controller_node',
        name='controller',
        output='screen',
        parameters=[LaunchConfiguration('controller_path')],
    )

    teleoperation_node = Node(
        package='cola2_control',
        executable='teleoperation_node',
        name='teleoperation',
        output='screen',
        parameters=[LaunchConfiguration('teleoperation_path')],
    )


    return LaunchDescription([
        robot_name_arg,
        config_folder_arg,
        captain_arg,
        pilot_arg,
        controller_arg,
        teleoperation_arg,
        diagnostic_node,
        captain_node,
        controller_node,
        pilot_node,
        teleoperation_node,
    ])