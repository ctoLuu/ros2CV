# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stoair/ros2CV/cv_ws/src/topic2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stoair/ros2CV/cv_ws/build/topic2

# Include any dependencies generated for this target.
include CMakeFiles/image_sub.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_sub.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_sub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_sub.dir/flags.make

CMakeFiles/image_sub.dir/src/image_sub.cpp.o: CMakeFiles/image_sub.dir/flags.make
CMakeFiles/image_sub.dir/src/image_sub.cpp.o: /home/stoair/ros2CV/cv_ws/src/topic2/src/image_sub.cpp
CMakeFiles/image_sub.dir/src/image_sub.cpp.o: CMakeFiles/image_sub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stoair/ros2CV/cv_ws/build/topic2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_sub.dir/src/image_sub.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_sub.dir/src/image_sub.cpp.o -MF CMakeFiles/image_sub.dir/src/image_sub.cpp.o.d -o CMakeFiles/image_sub.dir/src/image_sub.cpp.o -c /home/stoair/ros2CV/cv_ws/src/topic2/src/image_sub.cpp

CMakeFiles/image_sub.dir/src/image_sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_sub.dir/src/image_sub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stoair/ros2CV/cv_ws/src/topic2/src/image_sub.cpp > CMakeFiles/image_sub.dir/src/image_sub.cpp.i

CMakeFiles/image_sub.dir/src/image_sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_sub.dir/src/image_sub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stoair/ros2CV/cv_ws/src/topic2/src/image_sub.cpp -o CMakeFiles/image_sub.dir/src/image_sub.cpp.s

CMakeFiles/image_sub.dir/src/yolo.cpp.o: CMakeFiles/image_sub.dir/flags.make
CMakeFiles/image_sub.dir/src/yolo.cpp.o: /home/stoair/ros2CV/cv_ws/src/topic2/src/yolo.cpp
CMakeFiles/image_sub.dir/src/yolo.cpp.o: CMakeFiles/image_sub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stoair/ros2CV/cv_ws/build/topic2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_sub.dir/src/yolo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_sub.dir/src/yolo.cpp.o -MF CMakeFiles/image_sub.dir/src/yolo.cpp.o.d -o CMakeFiles/image_sub.dir/src/yolo.cpp.o -c /home/stoair/ros2CV/cv_ws/src/topic2/src/yolo.cpp

CMakeFiles/image_sub.dir/src/yolo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_sub.dir/src/yolo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stoair/ros2CV/cv_ws/src/topic2/src/yolo.cpp > CMakeFiles/image_sub.dir/src/yolo.cpp.i

CMakeFiles/image_sub.dir/src/yolo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_sub.dir/src/yolo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stoair/ros2CV/cv_ws/src/topic2/src/yolo.cpp -o CMakeFiles/image_sub.dir/src/yolo.cpp.s

CMakeFiles/image_sub.dir/src/image_base64.cpp.o: CMakeFiles/image_sub.dir/flags.make
CMakeFiles/image_sub.dir/src/image_base64.cpp.o: /home/stoair/ros2CV/cv_ws/src/topic2/src/image_base64.cpp
CMakeFiles/image_sub.dir/src/image_base64.cpp.o: CMakeFiles/image_sub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stoair/ros2CV/cv_ws/build/topic2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_sub.dir/src/image_base64.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_sub.dir/src/image_base64.cpp.o -MF CMakeFiles/image_sub.dir/src/image_base64.cpp.o.d -o CMakeFiles/image_sub.dir/src/image_base64.cpp.o -c /home/stoair/ros2CV/cv_ws/src/topic2/src/image_base64.cpp

CMakeFiles/image_sub.dir/src/image_base64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_sub.dir/src/image_base64.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stoair/ros2CV/cv_ws/src/topic2/src/image_base64.cpp > CMakeFiles/image_sub.dir/src/image_base64.cpp.i

CMakeFiles/image_sub.dir/src/image_base64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_sub.dir/src/image_base64.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stoair/ros2CV/cv_ws/src/topic2/src/image_base64.cpp -o CMakeFiles/image_sub.dir/src/image_base64.cpp.s

# Object files for target image_sub
image_sub_OBJECTS = \
"CMakeFiles/image_sub.dir/src/image_sub.cpp.o" \
"CMakeFiles/image_sub.dir/src/yolo.cpp.o" \
"CMakeFiles/image_sub.dir/src/image_base64.cpp.o"

# External object files for target image_sub
image_sub_EXTERNAL_OBJECTS =

image_sub: CMakeFiles/image_sub.dir/src/image_sub.cpp.o
image_sub: CMakeFiles/image_sub.dir/src/yolo.cpp.o
image_sub: CMakeFiles/image_sub.dir/src/image_base64.cpp.o
image_sub: CMakeFiles/image_sub.dir/build.make
image_sub: /opt/ros/humble/lib/librclcpp.so
image_sub: /opt/ros/humble/lib/libcv_bridge.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_fastrtps_c.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_introspection_c.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_fastrtps_cpp.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_introspection_cpp.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_cpp.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_py.so
image_sub: /usr/local/lib/libopencv_gapi.so.4.9.0
image_sub: /usr/local/lib/libopencv_stitching.so.4.9.0
image_sub: /usr/local/lib/libopencv_aruco.so.4.9.0
image_sub: /usr/local/lib/libopencv_bgsegm.so.4.9.0
image_sub: /usr/local/lib/libopencv_bioinspired.so.4.9.0
image_sub: /usr/local/lib/libopencv_ccalib.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudabgsegm.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudafeatures2d.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudaobjdetect.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudastereo.so.4.9.0
image_sub: /usr/local/lib/libopencv_dnn_objdetect.so.4.9.0
image_sub: /usr/local/lib/libopencv_dnn_superres.so.4.9.0
image_sub: /usr/local/lib/libopencv_dpm.so.4.9.0
image_sub: /usr/local/lib/libopencv_face.so.4.9.0
image_sub: /usr/local/lib/libopencv_freetype.so.4.9.0
image_sub: /usr/local/lib/libopencv_fuzzy.so.4.9.0
image_sub: /usr/local/lib/libopencv_hfs.so.4.9.0
image_sub: /usr/local/lib/libopencv_img_hash.so.4.9.0
image_sub: /usr/local/lib/libopencv_intensity_transform.so.4.9.0
image_sub: /usr/local/lib/libopencv_line_descriptor.so.4.9.0
image_sub: /usr/local/lib/libopencv_mcc.so.4.9.0
image_sub: /usr/local/lib/libopencv_quality.so.4.9.0
image_sub: /usr/local/lib/libopencv_rapid.so.4.9.0
image_sub: /usr/local/lib/libopencv_reg.so.4.9.0
image_sub: /usr/local/lib/libopencv_rgbd.so.4.9.0
image_sub: /usr/local/lib/libopencv_saliency.so.4.9.0
image_sub: /usr/local/lib/libopencv_signal.so.4.9.0
image_sub: /usr/local/lib/libopencv_stereo.so.4.9.0
image_sub: /usr/local/lib/libopencv_structured_light.so.4.9.0
image_sub: /usr/local/lib/libopencv_superres.so.4.9.0
image_sub: /usr/local/lib/libopencv_surface_matching.so.4.9.0
image_sub: /usr/local/lib/libopencv_tracking.so.4.9.0
image_sub: /usr/local/lib/libopencv_videostab.so.4.9.0
image_sub: /usr/local/lib/libopencv_wechat_qrcode.so.4.9.0
image_sub: /usr/local/lib/libopencv_xfeatures2d.so.4.9.0
image_sub: /usr/local/lib/libopencv_xobjdetect.so.4.9.0
image_sub: /usr/local/lib/libopencv_xphoto.so.4.9.0
image_sub: /opt/ros/humble/lib/liblibstatistics_collector.so
image_sub: /opt/ros/humble/lib/librcl.so
image_sub: /opt/ros/humble/lib/librmw_implementation.so
image_sub: /opt/ros/humble/lib/libament_index_cpp.so
image_sub: /opt/ros/humble/lib/librcl_logging_spdlog.so
image_sub: /opt/ros/humble/lib/librcl_logging_interface.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/librcl_yaml_param_parser.so
image_sub: /opt/ros/humble/lib/libyaml.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libtracetools.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/libsensor_msgs__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
image_sub: /opt/ros/humble/lib/libfastcdr.so.1.0.24
image_sub: /opt/ros/humble/lib/librmw.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_typesupport_c.so
image_sub: /home/stoair/ros2CV/cv_ws/install/ros2_interfaces/lib/libros2_interfaces__rosidl_generator_c.so
image_sub: /opt/ros/humble/lib/librosidl_typesupport_c.so
image_sub: /opt/ros/humble/lib/librcpputils.so
image_sub: /opt/ros/humble/lib/librosidl_runtime_c.so
image_sub: /opt/ros/humble/lib/librcutils.so
image_sub: /usr/lib/x86_64-linux-gnu/libpython3.10.so
image_sub: /usr/local/lib/libopencv_shape.so.4.9.0
image_sub: /usr/local/lib/libopencv_highgui.so.4.9.0
image_sub: /usr/local/lib/libopencv_datasets.so.4.9.0
image_sub: /usr/local/lib/libopencv_plot.so.4.9.0
image_sub: /usr/local/lib/libopencv_text.so.4.9.0
image_sub: /usr/local/lib/libopencv_ml.so.4.9.0
image_sub: /usr/local/lib/libopencv_phase_unwrapping.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudacodec.so.4.9.0
image_sub: /usr/local/lib/libopencv_videoio.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudaoptflow.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudalegacy.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudawarping.so.4.9.0
image_sub: /usr/local/lib/libopencv_optflow.so.4.9.0
image_sub: /usr/local/lib/libopencv_ximgproc.so.4.9.0
image_sub: /usr/local/lib/libopencv_video.so.4.9.0
image_sub: /usr/local/lib/libopencv_imgcodecs.so.4.9.0
image_sub: /usr/local/lib/libopencv_objdetect.so.4.9.0
image_sub: /usr/local/lib/libopencv_calib3d.so.4.9.0
image_sub: /usr/local/lib/libopencv_dnn.so.4.9.0
image_sub: /usr/local/lib/libopencv_features2d.so.4.9.0
image_sub: /usr/local/lib/libopencv_flann.so.4.9.0
image_sub: /usr/local/lib/libopencv_photo.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudaimgproc.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudafilters.so.4.9.0
image_sub: /usr/local/lib/libopencv_imgproc.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudaarithm.so.4.9.0
image_sub: /usr/local/lib/libopencv_core.so.4.9.0
image_sub: /usr/local/lib/libopencv_cudev.so.4.9.0
image_sub: CMakeFiles/image_sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stoair/ros2CV/cv_ws/build/topic2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable image_sub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_sub.dir/build: image_sub
.PHONY : CMakeFiles/image_sub.dir/build

CMakeFiles/image_sub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_sub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_sub.dir/clean

CMakeFiles/image_sub.dir/depend:
	cd /home/stoair/ros2CV/cv_ws/build/topic2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stoair/ros2CV/cv_ws/src/topic2 /home/stoair/ros2CV/cv_ws/src/topic2 /home/stoair/ros2CV/cv_ws/build/topic2 /home/stoair/ros2CV/cv_ws/build/topic2 /home/stoair/ros2CV/cv_ws/build/topic2/CMakeFiles/image_sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_sub.dir/depend

