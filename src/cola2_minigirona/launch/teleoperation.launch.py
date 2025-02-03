import launch
from launch import LaunchDescription
from launch_ros.actions import Node, PushRosNamespace
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    robot_name_arg = DeclareLaunchArgument(
        'robot_name',
        default_value='minigirona',
        description='Name of the robot'
    )

    joystick_device_arg = DeclareLaunchArgument(
        'joystick_device',
        default_value='/dev/input/js0',
        description='Serial of the joystick'
    )

    logitech_path_arg = DeclareLaunchArgument(
        'logitech_path',
        default_value=os.path.join(
            FindPackageShare('cola2_minigirona').find('cola2_minigirona'), 
            'config', 
            'logitech_fx10_to_teleoperation.yaml'
        ),
        description='Path to the logitech yaml'
    )

    teleoperation_node = GroupAction([
        # Launch the joy node with parameters
        Node(
            package='joy',
            executable='joy_node',
            name='joystick',
            respawn=True, 
            parameters=[{
                'dev': LaunchConfiguration('joystick_device'),
                'dev_ff': '',
                'deadzone': 0.05
            }],
            output='screen'
        ),

        # Launch the logitech_fx10_to_teleoperation node with parameters
        Node(
            package='cola2_control',
            executable='logitech_fx10_to_teleoperation_node.py',
            name='logitech_fx10_to_teleoperation',
            output='screen',
            parameters=[LaunchConfiguration('logitech_path')],
        ),
    ])

    return LaunchDescription([
        robot_name_arg,
        joystick_device_arg,
        logitech_path_arg,
        
        GroupAction([
            PushRosNamespace(LaunchConfiguration('robot_name')),
            teleoperation_node,
        ]),
    ])