# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.28.3)

# Reject any attempt to use a toolchain file. We must not use one because
# we could be downloading it here. If the CMAKE_TOOLCHAIN_FILE environment
# variable is set, the cache variable will have been initialized from it.
unset(CMAKE_TOOLCHAIN_FILE CACHE)
unset(ENV{CMAKE_TOOLCHAIN_FILE})

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(matplotlib_cpp-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.43.0]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.43.0]==]
)


include(ExternalProject)
ExternalProject_Add(matplotlib_cpp-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/Fields2Cover/matplotlib-cpp.git" "EXTERNALPROJECT_INTERNAL_ARGUMENT_SEPARATOR" "FETCHCONTENT_UPDATES_DISCONNECTED" "GIT_TAG" "75c15d0c907a4b68bca5ef97032302bd14ccab8e"
                    SOURCE_DIR          "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-src"
                    BINARY_DIR          "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/matplotlib_cpp-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


