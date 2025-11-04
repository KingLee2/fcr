# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-src"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-build"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/tmp"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/src/matplotlib_cpp-populate-stamp"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/src"
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/src/matplotlib_cpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/src/matplotlib_cpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-subbuild/matplotlib_cpp-populate-prefix/src/matplotlib_cpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
