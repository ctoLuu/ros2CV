cmake_minimum_required(VERSION 3.8)
project(topic)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


set(OpenCV_DIR /usr/local/include/opencv4/opencv2)

function(set_up_dependencies target)
    find_package(rclcpp REQUIRED)
    find_package(OpenCV REQUIRED)
    find_package(cv_bridge REQUIRED)
    find_package(topic_interfaces REQUIRED)
    find_package(sensor_msgs REQUIRED)
    ament_target_dependencies(${target} rclcpp sensor_msgs cv_bridge OpenCV topic_interfaces)
    target_include_directories(${target} PUBLIC
        include  # Add your include directory here
    )
endfunction()

include_directories( "/usr/include/eigen3" )

# Declare executables and set dependencies
add_executable(image_pub src/image_pub.cpp src/yolo.cpp)
set_up_dependencies(image_pub)

add_executable(image_sub src/image_sub.cpp src/yolo.cpp)
set_up_dependencies(image_sub)

install(TARGETS
  image_pub
  image_sub
  DESTINATION lib/${PROJECT_NAME}
)

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

ament_package()

# find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(OpenCV REQUIRED)
# find_package(cv_bridge REQUIRED)

# add_executable(image_pub src/image_pub.cpp)
# ament_target_dependencies(image_pub rclcpp sensor_msgs cv_bridge OpenCV)
# add_executable(image_sub src/image_sub.cpp)
# ament_target_dependencies(image_sub rclcpp sensor_msgs cv_bridge OpenCV)

# set(OpenCV_DIR /usr/local/include/opencv4/opencv2)

# find_package(sensor_msgs REQUIRED)
# include_directories(${sensor_msgs_INCLUDE_DIRS})

# function(set_up_dependencies target)
#     find_package(rclcpp REQUIRED)
#     find_package(OpenCV REQUIRED)
#     find_package(cv_bridge REQUIRED)
#     find_package(topic_interfaces REQUIRED)
#     find_package(sensor_msgs REQUIRED)
#     ament_target_dependencies(${target} rclcpp sensor_msgs cv_bridge OpenCV topic_interfaces)
#     target_include_directories(${target} PUBLIC
#         include  # Add your include directory here
#     )
# endfunction()

# include_directories( "/usr/include/eigen3" )
# include_directories("./include")

# # Add yolo.cpp as a library
# add_library(yolo_lib src/yolo.cpp)
# target_link_libraries(yolo_lib
#     rclcpp
#     sensor_msgs
#     cv_bridge
#     OpenCV
# )

# # Declare executables and set dependencies
# add_executable(image_pub src/image_pub.cpp)
# set_up_dependencies(image_pub)
# target_link_libraries(image_pub yolo_lib)

# add_executable(image_sub src/image_sub.cpp)
# set_up_dependencies(image_sub)
# target_link_libraries(image_sub yolo_lib)

# install(TARGETS
#   image_pub
#   image_sub
#   DESTINATION lib/${PROJECT_NAME}
# )
