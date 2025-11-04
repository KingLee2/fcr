# Install script for directory: /home/mvibot/floorCleaningRobot_ws/src/Fields2Cover

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/mvibot/floorCleaningRobot_ws/install/fields2cover")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/json-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/tinyxml2-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/spline-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib" TYPE SHARED_LIBRARY FILES "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/lib/libFields2Cover.so")
  if(EXISTS "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so"
         OLD_RPATH "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/tinyxml2-build:/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-build:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libFields2Cover.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/include/fields2cover.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/include" TYPE FILE FILES "/home/mvibot/floorCleaningRobot_ws/src/Fields2Cover/include/fields2cover.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9.0.0"
      "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9.0.0;/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib" TYPE SHARED_LIBRARY FILES
    "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/tinyxml2-build/libtinyxml2.so.9.0.0"
    "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/tinyxml2-build/libtinyxml2.so.9"
    )
  foreach(file
      "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9.0.0"
      "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so.9"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libtinyxml2.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib" TYPE SHARED_LIBRARY FILES "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/tinyxml2-build/libtinyxml2.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib" TYPE SHARED_LIBRARY FILES "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-build/libsteering_functions.so")
  if(EXISTS "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/lib/libsteering_functions.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets.cmake"
         "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/CMakeFiles/Export/d5bff52e0a8331490ce9be2f2f43eaf3/Fields2Cover-shared-Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover" TYPE FILE FILES "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/CMakeFiles/Export/d5bff52e0a8331490ce9be2f2f43eaf3/Fields2Cover-shared-Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2Cover-shared-Targets-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover" TYPE FILE FILES "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/CMakeFiles/Export/d5bff52e0a8331490ce9be2f2f43eaf3/Fields2Cover-shared-Targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2CoverConfig.cmake;/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover/Fields2CoverConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover" TYPE FILE FILES
    "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/Fields2CoverConfig.cmake"
    "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/Fields2CoverConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Fields2Cover" TYPE FILE FILES "/home/mvibot/floorCleaningRobot_ws/src/Fields2Cover/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/mvibot/floorCleaningRobot_ws/src/Fields2Cover/include/")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/tutorials/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/mvibot/floorCleaningRobot_ws/build/fields2cover/tests/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
