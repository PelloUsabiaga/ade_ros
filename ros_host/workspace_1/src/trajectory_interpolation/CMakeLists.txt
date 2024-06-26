cmake_minimum_required(VERSION 3.8)
project(trajectory_interpolation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)

add_executable(trajectory_interpolation_server src/main.cpp src/interpolate_trajectory_server.cpp src/interpolate_trajectory_server.h src/trajectory_interpolator.cpp src/trajectory_interpolator.h)
ament_target_dependencies(trajectory_interpolation_server rclcpp custom_interfaces)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()  
endif()

install(TARGETS trajectory_interpolation_server DESTINATION lib/${PROJECT_NAME})

ament_package()
