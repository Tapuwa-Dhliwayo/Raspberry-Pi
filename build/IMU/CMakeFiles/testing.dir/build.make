# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/pi/TestingSensors/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/TestingSensors/build

# Include any dependencies generated for this target.
include IMU/CMakeFiles/testing.dir/depend.make

# Include the progress variables for this target.
include IMU/CMakeFiles/testing.dir/progress.make

# Include the compile flags for this target's objects.
include IMU/CMakeFiles/testing.dir/flags.make

IMU/CMakeFiles/testing.dir/testing.cpp.o: IMU/CMakeFiles/testing.dir/flags.make
IMU/CMakeFiles/testing.dir/testing.cpp.o: /home/pi/TestingSensors/src/IMU/testing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/TestingSensors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object IMU/CMakeFiles/testing.dir/testing.cpp.o"
	cd /home/pi/TestingSensors/build/IMU && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testing.dir/testing.cpp.o -c /home/pi/TestingSensors/src/IMU/testing.cpp

IMU/CMakeFiles/testing.dir/testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testing.dir/testing.cpp.i"
	cd /home/pi/TestingSensors/build/IMU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/TestingSensors/src/IMU/testing.cpp > CMakeFiles/testing.dir/testing.cpp.i

IMU/CMakeFiles/testing.dir/testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testing.dir/testing.cpp.s"
	cd /home/pi/TestingSensors/build/IMU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/TestingSensors/src/IMU/testing.cpp -o CMakeFiles/testing.dir/testing.cpp.s

# Object files for target testing
testing_OBJECTS = \
"CMakeFiles/testing.dir/testing.cpp.o"

# External object files for target testing
testing_EXTERNAL_OBJECTS =

IMU/testing: IMU/CMakeFiles/testing.dir/testing.cpp.o
IMU/testing: IMU/CMakeFiles/testing.dir/build.make
IMU/testing: IMU/CMakeFiles/testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/TestingSensors/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testing"
	cd /home/pi/TestingSensors/build/IMU && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
IMU/CMakeFiles/testing.dir/build: IMU/testing

.PHONY : IMU/CMakeFiles/testing.dir/build

IMU/CMakeFiles/testing.dir/clean:
	cd /home/pi/TestingSensors/build/IMU && $(CMAKE_COMMAND) -P CMakeFiles/testing.dir/cmake_clean.cmake
.PHONY : IMU/CMakeFiles/testing.dir/clean

IMU/CMakeFiles/testing.dir/depend:
	cd /home/pi/TestingSensors/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/TestingSensors/src /home/pi/TestingSensors/src/IMU /home/pi/TestingSensors/build /home/pi/TestingSensors/build/IMU /home/pi/TestingSensors/build/IMU/CMakeFiles/testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : IMU/CMakeFiles/testing.dir/depend

