#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tf2_web_republisher::tf2_web_republisher" for configuration ""
set_property(TARGET tf2_web_republisher::tf2_web_republisher APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(tf2_web_republisher::tf2_web_republisher PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtf2_web_republisher.so"
  IMPORTED_SONAME_NOCONFIG "libtf2_web_republisher.so"
  )

list(APPEND _cmake_import_check_targets tf2_web_republisher::tf2_web_republisher )
list(APPEND _cmake_import_check_files_for_tf2_web_republisher::tf2_web_republisher "${_IMPORT_PREFIX}/lib/libtf2_web_republisher.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
