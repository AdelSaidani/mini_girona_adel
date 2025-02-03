cmake_minimum_required(VERSION 3.5)
project(minigirona_description)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(cola2_lib_ros REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)


# add_executable(odom_to_world_ned src/odom_to_world_ned.cpp)  # Adjust the path as necessary
# ament_target_dependencies(odom_to_world_ned
#   rclcpp
#   nav_msgs
#   tf2_ros
#   geometry_msgs
# )

# install(TARGETS
#   odom_to_world_ned
#   DESTINATION lib/${PROJECT_NAME}
# )

install(DIRECTORY launch meshes urdf resources DESTINATION share/${PROJECT_NAME})

# Declare ament package
ament_package()
