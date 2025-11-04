set(F2C_CMAKE_INSTALL_DIR /home/mvibot/floorCleaningRobot_ws/install/fields2cover/cmake/fields2cover)

include(CMakeFindDependencyMacro)
find_dependency(GDAL 3.0 REQUIRED)

if(EXISTS "${F2C_CMAKE_INSTALL_DIR}/Fields2Cover-shared-Targets.cmake")
  include("${F2C_CMAKE_INSTALL_DIR}/Fields2Cover-shared-Targets.cmake")
else()
  include("${F2C_CMAKE_INSTALL_DIR}/Fields2Cover-static-Targets.cmake")
endif()


