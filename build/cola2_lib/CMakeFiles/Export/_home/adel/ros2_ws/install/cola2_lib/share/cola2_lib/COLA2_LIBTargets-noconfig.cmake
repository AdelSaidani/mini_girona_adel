#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cola2_io" for configuration ""
set_property(TARGET cola2_io APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_io PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "Boost::thread;Boost::date_time;Boost::filesystem"
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_io.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_io )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_io "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_io.so" )

# Import target "cola2_utils" for configuration ""
set_property(TARGET cola2_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_utils PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "Boost::thread;Boost::date_time;Boost::filesystem"
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_utils.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_utils )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_utils "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_utils.so" )

# Import target "cola2_mission" for configuration ""
set_property(TARGET cola2_mission APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_mission PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "/usr/lib/x86_64-linux-gnu/libtinyxml.so"
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_mission.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_mission )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_mission "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_mission.so" )

# Import target "cola2_comms" for configuration ""
set_property(TARGET cola2_comms APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_comms PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_comms.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_comms )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_comms "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_comms.so" )

# Import target "cola2_wmmc" for configuration ""
set_property(TARGET cola2_wmmc APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_wmmc PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_wmmc.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_wmmc )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_wmmc "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmmc.so" )

# Import target "cola2_wmm" for configuration ""
set_property(TARGET cola2_wmm APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cola2_wmm PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "cola2_wmmc"
  IMPORTED_LOCATION_NOCONFIG "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so"
  IMPORTED_SONAME_NOCONFIG "libcola2_wmm.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cola2_wmm )
list(APPEND _IMPORT_CHECK_FILES_FOR_cola2_wmm "/home/adel/ros2_ws/install/cola2_lib/lib/libcola2_wmm.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
