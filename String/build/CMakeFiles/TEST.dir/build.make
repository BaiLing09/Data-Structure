# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/hp/System1/Programs/Data_Structure/String

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/hp/System1/Programs/Data_Structure/String/build

# Include any dependencies generated for this target.
include CMakeFiles/TEST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST.dir/flags.make

CMakeFiles/TEST.dir/main.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/hp/System1/Programs/Data_Structure/String/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TEST.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST.dir/main.cpp.o -c /media/hp/System1/Programs/Data_Structure/String/main.cpp

CMakeFiles/TEST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/hp/System1/Programs/Data_Structure/String/main.cpp > CMakeFiles/TEST.dir/main.cpp.i

CMakeFiles/TEST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/hp/System1/Programs/Data_Structure/String/main.cpp -o CMakeFiles/TEST.dir/main.cpp.s

CMakeFiles/TEST.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TEST.dir/main.cpp.o.requires

CMakeFiles/TEST.dir/main.cpp.o.provides: CMakeFiles/TEST.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST.dir/build.make CMakeFiles/TEST.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TEST.dir/main.cpp.o.provides

CMakeFiles/TEST.dir/main.cpp.o.provides.build: CMakeFiles/TEST.dir/main.cpp.o


CMakeFiles/TEST.dir/test.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/hp/System1/Programs/Data_Structure/String/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TEST.dir/test.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST.dir/test.cpp.o -c /media/hp/System1/Programs/Data_Structure/String/test.cpp

CMakeFiles/TEST.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/test.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/hp/System1/Programs/Data_Structure/String/test.cpp > CMakeFiles/TEST.dir/test.cpp.i

CMakeFiles/TEST.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/test.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/hp/System1/Programs/Data_Structure/String/test.cpp -o CMakeFiles/TEST.dir/test.cpp.s

CMakeFiles/TEST.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/TEST.dir/test.cpp.o.requires

CMakeFiles/TEST.dir/test.cpp.o.provides: CMakeFiles/TEST.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST.dir/build.make CMakeFiles/TEST.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/TEST.dir/test.cpp.o.provides

CMakeFiles/TEST.dir/test.cpp.o.provides.build: CMakeFiles/TEST.dir/test.cpp.o


CMakeFiles/TEST.dir/String.cpp.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/String.cpp.o: ../String.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/hp/System1/Programs/Data_Structure/String/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TEST.dir/String.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST.dir/String.cpp.o -c /media/hp/System1/Programs/Data_Structure/String/String.cpp

CMakeFiles/TEST.dir/String.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST.dir/String.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/hp/System1/Programs/Data_Structure/String/String.cpp > CMakeFiles/TEST.dir/String.cpp.i

CMakeFiles/TEST.dir/String.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST.dir/String.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/hp/System1/Programs/Data_Structure/String/String.cpp -o CMakeFiles/TEST.dir/String.cpp.s

CMakeFiles/TEST.dir/String.cpp.o.requires:

.PHONY : CMakeFiles/TEST.dir/String.cpp.o.requires

CMakeFiles/TEST.dir/String.cpp.o.provides: CMakeFiles/TEST.dir/String.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST.dir/build.make CMakeFiles/TEST.dir/String.cpp.o.provides.build
.PHONY : CMakeFiles/TEST.dir/String.cpp.o.provides

CMakeFiles/TEST.dir/String.cpp.o.provides.build: CMakeFiles/TEST.dir/String.cpp.o


# Object files for target TEST
TEST_OBJECTS = \
"CMakeFiles/TEST.dir/main.cpp.o" \
"CMakeFiles/TEST.dir/test.cpp.o" \
"CMakeFiles/TEST.dir/String.cpp.o"

# External object files for target TEST
TEST_EXTERNAL_OBJECTS =

TEST: CMakeFiles/TEST.dir/main.cpp.o
TEST: CMakeFiles/TEST.dir/test.cpp.o
TEST: CMakeFiles/TEST.dir/String.cpp.o
TEST: CMakeFiles/TEST.dir/build.make
TEST: /media/hp/System1/SoftWare/JH/ubuntu_x64/JHCap2/libJHCap.so
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_gapi.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_highgui.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_ml.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_objdetect.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_photo.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_stitching.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_video.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_videoio.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_dnn.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_imgcodecs.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_calib3d.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_features2d.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_flann.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_imgproc.so.4.5.2
TEST: /media/hp/System1/SoftWare/Opencv4/opencv/lib/libopencv_core.so.4.5.2
TEST: CMakeFiles/TEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/hp/System1/Programs/Data_Structure/String/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TEST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST.dir/build: TEST

.PHONY : CMakeFiles/TEST.dir/build

CMakeFiles/TEST.dir/requires: CMakeFiles/TEST.dir/main.cpp.o.requires
CMakeFiles/TEST.dir/requires: CMakeFiles/TEST.dir/test.cpp.o.requires
CMakeFiles/TEST.dir/requires: CMakeFiles/TEST.dir/String.cpp.o.requires

.PHONY : CMakeFiles/TEST.dir/requires

CMakeFiles/TEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TEST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TEST.dir/clean

CMakeFiles/TEST.dir/depend:
	cd /media/hp/System1/Programs/Data_Structure/String/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/hp/System1/Programs/Data_Structure/String /media/hp/System1/Programs/Data_Structure/String /media/hp/System1/Programs/Data_Structure/String/build /media/hp/System1/Programs/Data_Structure/String/build /media/hp/System1/Programs/Data_Structure/String/build/CMakeFiles/TEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEST.dir/depend
