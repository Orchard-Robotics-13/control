cmake_minimum_required(VERSION 3.8)
project(control)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic   -Wconversion
    -Wsign-conversion -Wshadow -Wformat=2 -Wunused-parameter)
else()
  add_compile_options(-Wunused-parameter)
endif()

## List all packges required
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CONTROL_SOURCES

  ## control algos
  src/algorithms/mpc.cpp
  src/algorithms/pid.cpp
  src/algorithms/pure_pursuit.cpp
  src/algorithms/stanley.cpp

  ## interface classes and controllers
  src/interfaces/base_controller.cpp
  src/interfaces/mobile_robot.cpp
  src/interfaces/robot_state.cpp
  src/robots/husky/husky_controller.cpp

  ## misc conversion files
  src/utils/conversions.cpp
  src/utils/math.cpp

  ## planner
  # src/planner/planner.cpp
)
add_library(control_core ${CONTROL_SOURCES})
ament_target_dependencies(control_core
  geometry_msgs
  nav_msgs
  rclcpp
)
target_include_directories(control_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(control_node src/main.cpp)
target_link_libraries(control_node PRIVATE control_core)
ament_target_dependencies(control_node PUBLIC rclcpp)

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
