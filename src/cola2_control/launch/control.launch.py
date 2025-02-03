from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    captain_yaml_arg = DeclareLaunchArgument(
        'captain_path',
        default_value=os.path.join(
            FindPackageShare('cola2_control').find('cola2_control'), 
            'config', 
            'captain.yaml'
        ),
        description='Captain yaml parameters'
    )

    pilot_yaml_arg = DeclareLaunchArgument(
        'pilot_path',
        default_value=os.path.join(
            FindPackageShare('cola2_control').find('cola2_control'), 
            'config', 
            'pilot.yaml'
        ),
        description='Pilot yaml parameters'
    )

    controller_yaml_arg = DeclareLaunchArgument(
        'controller_path',
        default_value=os.path.join(
            FindPackageShare('cola2_control').find('cola2_control'), 
            'config', 
            'controller.yaml'
        ),
        description='Controller yaml parameters'
    )

    logitech_yaml_arg = DeclareLaunchArgument(
        'logitech_path',
        default_value=os.path.join(
            FindPackageShare('cola2_control').find('cola2_control'), 
            'config', 
            'logitech_fx10_to_teleoperation.yaml'
        ),
        description='Logitech yaml parameters'
    )

    teleoperation_yaml_arg = DeclareLaunchArgument(
        'teleoperation_path',
        default_value=os.path.join(
            FindPackageShare('cola2_control').find('cola2_control'), 
            'config', 
            'teleoperation.yaml'
        ),
        description='Teleoperation yaml parameters'
    )

    captain_node = Node(
        package='cola2_control',
        executable='captain_node',
        name='captain',
        output='screen',
        parameters=[LaunchConfiguration('captain_path')],
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

    logitech_node = Node(
        package='cola2_control',
        executable='logitech_fx10_to_teleoperation_node.py',
        name='logitech_fx10_to_teleoperation',
        output='screen',
        parameters=[LaunchConfiguration('logitech_path')],
    )

    teleoperation_node = Node(
        package='cola2_control',
        executable='teleoperation_node',
        name='teleoperation',
        output='screen',
        parameters=[LaunchConfiguration('teleoperation_path')],
    )


    return LaunchDescription([
        captain_yaml_arg,
        pilot_yaml_arg,
        controller_yaml_arg,
        logitech_yaml_arg,
        teleoperation_yaml_arg,

        # Load ROS parameters of the nodes
        captain_node,
        pilot_node,
        controller_node,
        logitech_node,
        teleoperation_node,
    ])
