# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitclone-lastrun.txt" AND EXISTS "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitinfo.txt" AND
  "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/Fields2Cover/steering_functions.git" "steering_functions-src"
    WORKING_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/Fields2Cover/steering_functions.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "33fc010017efa1ef2c8a2d4779fcda94b4b30d20" --
  WORKING_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '33fc010017efa1ef2c8a2d4779fcda94b4b30d20'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitinfo.txt" "/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/mvibot/floorCleaningRobot_ws/build/fields2cover/_deps/steering_functions-subbuild/steering_functions-populate-prefix/src/steering_functions-populate-stamp/steering_functions-populate-gitclone-lastrun.txt'")
endif()
