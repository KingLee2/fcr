# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_opennav_row_coverage_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED opennav_row_coverage_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(opennav_row_coverage_FOUND FALSE)
  elseif(NOT opennav_row_coverage_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(opennav_row_coverage_FOUND FALSE)
  endif()
  return()
endif()
set(_opennav_row_coverage_CONFIG_INCLUDED TRUE)

# output package information
if(NOT opennav_row_coverage_FIND_QUIETLY)
  message(STATUS "Found opennav_row_coverage: 0.0.1 (${opennav_row_coverage_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'opennav_row_coverage' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT opennav_row_coverage_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(opennav_row_coverage_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${opennav_row_coverage_DIR}/${_extra}")
endforeach()
