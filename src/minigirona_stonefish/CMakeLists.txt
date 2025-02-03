cmake_minimum_required(VERSION 3.5)
project(minigirona_stonefish)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

# Find ament and other dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cola2_msgs REQUIRED)
find_package(stonefish_ros2 REQUIRED)

# Declare the executable
add_executable(minigirona_stonefish_node src/minigirona_stonefish_node.cpp)

# Specify the dependencies for the executable
ament_target_dependencies(minigirona_stonefish_node
  rclcpp
  std_msgs
  cola2_msgs
  stonefish_ros2
)

# Install the executable
install(TARGETS minigirona_stonefish_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY data launch scenarios
  DESTINATION share/${PROJECT_NAME}
)

# Export the package
ament_package()
