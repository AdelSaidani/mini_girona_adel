import launch
from launch import LaunchDescription
from launch_ros.actions import Node, PushRosNamespace
from launch.actions import DeclareLaunchArgument, GroupAction, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory
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

    robot_xacro_arg = DeclareLaunchArgument(
        'robot_xacro',
        default_value=os.path.join(
            FindPackageShare('minigirona_description').find('minigirona_description'), 
            'urdf', 
            'payload.urdf.xacro'
        ),
        description='Path to the robot Xacro file'
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

    static_transform_publisher_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='world2ned',
        arguments=['--x', '0', '--y', '0', '--z', '0', '--roll', '0', '--pitch', '0', '--yaw', '3.1415', '--frame-id', 'world', '--child-frame-id', 'world_ned'],
        output='screen'
    )

    sim_core_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('cola2_minigirona'), 'launch', 'sim_core.launch.py')]),
        launch_arguments={
            'robot_name': LaunchConfiguration('robot_name')
        }.items()
    )

    teleoperation_node = GroupAction([
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

        Node(
            package='cola2_control',
            executable='logitech_fx10_to_teleoperation_node.py',
            name='logitech_fx10_to_teleoperation',
            output='screen',
            parameters=[LaunchConfiguration('logitech_path')],
        ),
    ])

    messages_node = GroupAction([
        Node(package='topic_tools', executable='throttle', name='navigation_throttle', arguments=['messages', 'navigator/navigation', '4.0']),
        Node(package='topic_tools', executable='throttle', name='odometry_throttle', arguments=['messages', 'navigator/odometry', '4.0']),
        Node(package='topic_tools', executable='throttle', name='merged_world_waypoint_req_throttle', arguments=['messages', 'controller/merged_world_waypoint_req', '2.0']),
        Node(package='topic_tools', executable='throttle', name='merged_body_velocity_req_throttle', arguments=['messages', 'controller/merged_body_velocity_req', '2.0']),
        Node(package='topic_tools', executable='throttle', name='merged_body_force_req_throttle', arguments=['messages', 'controller/merged_body_force_req', '2.0']),
        Node(package='topic_tools', executable='throttle', name='thruster_setpoints_throttle', arguments=['messages', 'setpoints_selector/thruster_setpoints', '4.0']),
    ])

    gui_server_node = Node(
        package='rosbridge_server',
        executable='rosbridge_websocket',
        name='rosbridge_websocket',
        output='screen'
    )

    return LaunchDescription([
        robot_name_arg,
        joystick_device_arg,
        robot_xacro_arg,
        logitech_path_arg,
        static_transform_publisher_node,
        
        GroupAction([
            PushRosNamespace(LaunchConfiguration('robot_name')),
            sim_core_node,
            teleoperation_node,
            messages_node,
            gui_server_node,
        ]),
    ])