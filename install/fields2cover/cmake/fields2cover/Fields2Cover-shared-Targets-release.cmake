#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Fields2Cover" for configuration "Release"
set_property(TARGET Fields2Cover APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Fields2Cover PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "tinyxml2;steering_functions"
  IMPORTED_LOCATION_RELEASE "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so"
  IMPORTED_SONAME_RELEASE "libFields2Cover.so"
  )

list(APPEND _cmake_import_check_targets Fields2Cover )
list(APPEND _cmake_import_check_files_for_Fields2Cover "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so" )

# Import target "tinyxml2" for configuration "Release"
set_property(TARGET tinyxml2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(tinyxml2 PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9.0.0"
  IMPORTED_SONAME_RELEASE "libtinyxml2.so.9"
  )

list(APPEND _cmake_import_check_targets tinyxml2 )
list(APPEND _cmake_import_check_files_for_tinyxml2 "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9.0.0" )

# Import target "steering_functions" for configuration "Release"
set_property(TARGET steering_functions APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(steering_functions PROPERTIES
  IMPORTED_LOCATION_RELEASE "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so"
  IMPORTED_SONAME_RELEASE "libsteering_functions.so"
  )

list(APPEND _cmake_import_check_targets steering_functions )
list(APPEND _cmake_import_check_files_for_steering_functions "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
