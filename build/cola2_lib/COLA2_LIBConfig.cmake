# - Config file for the COLA2_LIB package
# It defines the following variables
#  COLA2_LIB_FOUND        - the library has been found
#  COLA2_LIB_INCLUDE_DIRS - include directories for COLA2_LIB library
#  COLA2_LIB_LIBRARIES    - libraries to link against

# Set found
set(COLA2_LIB_FOUND ON)
 
# Compute paths
get_filename_component(COLA2_LIB_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(COLA2_LIB_INCLUDE_DIRS "/home/adel/ros2_ws/src/cola2_lib/include;/usr/include;/usr/include/eigen3")
set(COLA2_LIB_LIBRARY_DIRS "")
set(COLA2_LIB_EXECUTABLE_DIRS "")
list(APPEND CMAKE_MODULE_PATH "/home/adel/ros2_ws/build/cola2_lib")
 
# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET COLA2_LIB_version AND NOT COLA2_LIB_BINARY_DIR)
  include("${COLA2_LIB_CMAKE_DIR}/COLA2_LIBTargets.cmake")
endif()
 
# These are IMPORTED targets created by COLA2_LIBTargets.cmake
set(COLA2_LIB_LIBRARIES "cola2_io;cola2_utils;cola2_mission;cola2_comms;cola2_wmmc;cola2_wmm")

# Display
if (COLA2_LIB_FOUND)
    message(STATUS "COLA2_LIB found version ${COLA2_LIB_VERSION}")
    message(STATUS "COLA2_LIB include directories: ${COLA2_LIB_INCLUDE_DIRS}")
    message(STATUS "COLA2_LIB libraries: ${COLA2_LIB_LIBRARIES}")
    message(STATUS "Including COLA2_LIB include directories")
    include_directories(${COLA2_LIB_INCLUDE_DIRS})
endif()

################################################
# Add dependencies
################################################
include("${COLA2_LIB_CMAKE_DIR}/COLA2_LIBDependencies.cmake")
