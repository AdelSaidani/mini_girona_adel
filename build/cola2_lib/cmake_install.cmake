# Install script for directory: /home/adel/ros2_ws/src/cola2_lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/adel/ros2_ws/install/cola2_lib")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/adel/ros2_ws/build/cola2_lib/ament_cmake_symlink_install/ament_cmake_symlink_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_io.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io/io_base.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io/serial_port.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io/tcp_socket.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io/udp_socket.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io/nmea_parser.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/io" TYPE FILE FILES
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/io/io_base.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/io/serial_port.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/io/tcp_socket.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/io/udp_socket.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/io/nmea_parser.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_utils.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/angles.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/error_macro.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/filesystem.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/ned.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/pressure.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/saturate.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/thread_safe_flag.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/thread_pool.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils/tdm.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/utils" TYPE FILE FILES
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/angles.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/error_macro.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/filesystem.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/ned.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/pressure.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/saturate.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/thread_safe_flag.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/thread_pool.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/utils/tdm.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_mission.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_step.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_action.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_maneuver.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_goto.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_section.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission/mission_park.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/mission" TYPE FILE FILES
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_step.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_action.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_maneuver.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_goto.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_section.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/mission/mission_park.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_comms.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/comms/altitude.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/comms/elapsed_time.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/comms" TYPE FILE FILES
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/comms/altitude.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/comms/elapsed_time.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_wmmc.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so"
         OLD_RPATH "::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/wmmc/GeomagnetismHeader.h;/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/wmmc/wmm.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/wmmc" TYPE FILE FILES
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/wmmc/GeomagnetismHeader.h"
    "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/wmmc/wmm.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so"
         RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/lib" TYPE SHARED_LIBRARY FILES "/home/adel/ros2_ws/build/cola2_lib/libcola2_wmm.so")
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so"
         OLD_RPATH "/home/adel/ros2_ws/build/cola2_lib::::::"
         NEW_RPATH "/home/adel/ros2_ws/install/cola2_lib/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/wmm/wmm.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib/wmm" TYPE FILE FILES "/home/adel/ros2_ws/src/cola2_lib/include/cola2_lib/wmm/wmm.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND /usr/bin/python3 -m pip install /home/adel/ros2_ws/build/cola2_lib)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBConfig.cmake;/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBConfigVersion.cmake;/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBDependencies.cmake;/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/FindTinyXML.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib" TYPE FILE FILES
    "/home/adel/ros2_ws/build/cola2_lib/CMakeFiles/COLA2_LIBConfig.cmake"
    "/home/adel/ros2_ws/build/cola2_lib/COLA2_LIBConfigVersion.cmake"
    "/home/adel/ros2_ws/src/cola2_lib/cmake/COLA2_LIBDependencies.cmake"
    "/home/adel/ros2_ws/src/cola2_lib/cmake/FindTinyXML.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/data/WMM.COF")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/data" TYPE FILE FILES "/home/adel/ros2_ws/src/cola2_lib/data/WMM.COF")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake"
         "/home/adel/ros2_ws/build/cola2_lib/CMakeFiles/Export/_home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib" TYPE FILE FILES "/home/adel/ros2_ws/build/cola2_lib/CMakeFiles/Export/_home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets-noconfig.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib" TYPE FILE FILES "/home/adel/ros2_ws/build/cola2_lib/CMakeFiles/Export/_home/adel/ros2_ws/install/cola2_lib/share/cola2_lib/COLA2_LIBTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/adel/ros2_ws/install/cola2_lib/include/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/adel/ros2_ws/install/cola2_lib/include" TYPE DIRECTORY FILES "/home/adel/ros2_ws/src/cola2_lib/include/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cola2_lib" TYPE DIRECTORY FILES "/home/adel/ros2_ws/src/cola2_lib/cmake" FILES_MATCHING REGEX "/[^/]*\\.cmake$")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/adel/ros2_ws/build/cola2_lib/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
