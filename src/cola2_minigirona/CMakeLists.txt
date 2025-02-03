cmake_minimum_required(VERSION 3.5)
project(cola2_minigirona)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosbridge_server REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(joy REQUIRED)
find_package(rviz2 REQUIRED)
find_package(diagnostic_msgs REQUIRED)
find_package(topic_tools REQUIRED)
find_package(minigirona_description REQUIRED)


install(
  DIRECTORY config launch missions sim_config
  DESTINATION share/${PROJECT_NAME}
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/scene)
  install(DIRECTORY scene DESTINATION share/${PROJECT_NAME})
endif()


# # Declare things to be passed to dependent projects
ament_package()
