cmake_minimum_required(VERSION 3.8)
project(Control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONTROL_SOURCES
  src/algorithms/mpc.cpp
  src/algorithms/pid.cpp
  src/algorithms/pure_pursuit.cpp
  src/algorithms/stanley.cpp
  src/interfaces/base_controller.cpp
  src/interfaces/mobile_robot.cpp
  src/interfaces/robot_state.cpp
  src/robots/husky/husky_controller.cpp
  src/robots/husky/husky_parameters.cpp
  src/utils/conversions.cpp
  src/utils/math.cpp
)

add_library(control_core ${CONTROL_SOURCES})
ament_target_dependencies(control_core
  geometry_msgs
  nav_msgs
  rclcpp
)
target_include_directories(control_core PUBLIC
  $<INSTALL_INTERFACE:include>
)

add_executable(control_node src/main.cpp)
target_link_libraries(control_node PRIVATE control_core)
ament_target_dependencies(control_node rclcpp)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS control_core control_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/control
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
