# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cola2_minigirona_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cola2_minigirona_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cola2_minigirona_FOUND FALSE)
  elseif(NOT cola2_minigirona_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cola2_minigirona_FOUND FALSE)
  endif()
  return()
endif()
set(_cola2_minigirona_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cola2_minigirona_FIND_QUIETLY)
  message(STATUS "Found cola2_minigirona: 24.1.0 (${cola2_minigirona_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cola2_minigirona' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cola2_minigirona_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cola2_minigirona_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${cola2_minigirona_DIR}/${_extra}")
endforeach()
