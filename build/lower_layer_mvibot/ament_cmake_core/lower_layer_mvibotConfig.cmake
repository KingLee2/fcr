# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lower_layer_mvibot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lower_layer_mvibot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lower_layer_mvibot_FOUND FALSE)
  elseif(NOT lower_layer_mvibot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lower_layer_mvibot_FOUND FALSE)
  endif()
  return()
endif()
set(_lower_layer_mvibot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lower_layer_mvibot_FIND_QUIETLY)
  message(STATUS "Found lower_layer_mvibot: 0.0.0 (${lower_layer_mvibot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lower_layer_mvibot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT lower_layer_mvibot_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lower_layer_mvibot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lower_layer_mvibot_DIR}/${_extra}")
endforeach()
