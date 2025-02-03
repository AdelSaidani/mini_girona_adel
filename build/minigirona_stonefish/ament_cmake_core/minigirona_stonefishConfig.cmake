# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_minigirona_stonefish_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED minigirona_stonefish_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(minigirona_stonefish_FOUND FALSE)
  elseif(NOT minigirona_stonefish_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(minigirona_stonefish_FOUND FALSE)
  endif()
  return()
endif()
set(_minigirona_stonefish_CONFIG_INCLUDED TRUE)

# output package information
if(NOT minigirona_stonefish_FIND_QUIETLY)
  message(STATUS "Found minigirona_stonefish: 1.3.0 (${minigirona_stonefish_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'minigirona_stonefish' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${minigirona_stonefish_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(minigirona_stonefish_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${minigirona_stonefish_DIR}/${_extra}")
endforeach()
