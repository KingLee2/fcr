# CMake generated Testfile for 
# Source directory: /home/mvibot/floorCleaningRobot_ws/src/tf2_web_republisher/tf2_web_republisher/test
# Build directory: /home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_tf_web_republisher]=] "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test_results/tf2_web_republisher/test_tf_web_republisher.gtest.xml" "--package-name" "tf2_web_republisher" "--output-file" "/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/ament_cmake_gmock/test_tf_web_republisher.txt" "--command" "/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test/test_tf_web_republisher" "--gtest_output=xml:/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test_results/tf2_web_republisher/test_tf_web_republisher.gtest.xml")
set_tests_properties([=[test_tf_web_republisher]=] PROPERTIES  LABELS "gmock" REQUIRED_FILES "/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test/test_tf_web_republisher" TIMEOUT "60" WORKING_DIRECTORY "/home/mvibot/floorCleaningRobot_ws/build/tf2_web_republisher/test" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock_test.cmake;98;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gmock/cmake/ament_add_gmock.cmake;90;ament_add_gmock_test;/home/mvibot/floorCleaningRobot_ws/src/tf2_web_republisher/tf2_web_republisher/test/CMakeLists.txt;3;ament_add_gmock;/home/mvibot/floorCleaningRobot_ws/src/tf2_web_republisher/tf2_web_republisher/test/CMakeLists.txt;0;")
subdirs("../gmock")
subdirs("../gtest")
