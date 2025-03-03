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
CMAKE_SOURCE_DIR = /home/adel/ros2_ws/src/cola2_lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adel/ros2_ws/build/cola2_lib

# Include any dependencies generated for this target.
include CMakeFiles/cola2_wmm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cola2_wmm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cola2_wmm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cola2_wmm.dir/flags.make

CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o: CMakeFiles/cola2_wmm.dir/flags.make
CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o: /home/adel/ros2_ws/src/cola2_lib/src/cola2_lib/wmm/wmm.cpp
CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o: CMakeFiles/cola2_wmm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adel/ros2_ws/build/cola2_lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o -MF CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o.d -o CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o -c /home/adel/ros2_ws/src/cola2_lib/src/cola2_lib/wmm/wmm.cpp

CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adel/ros2_ws/src/cola2_lib/src/cola2_lib/wmm/wmm.cpp > CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.i

CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adel/ros2_ws/src/cola2_lib/src/cola2_lib/wmm/wmm.cpp -o CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.s

# Object files for target cola2_wmm
cola2_wmm_OBJECTS = \
"CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o"

# External object files for target cola2_wmm
cola2_wmm_EXTERNAL_OBJECTS =

libcola2_wmm.so: CMakeFiles/cola2_wmm.dir/src/cola2_lib/wmm/wmm.cpp.o
libcola2_wmm.so: CMakeFiles/cola2_wmm.dir/build.make
libcola2_wmm.so: libcola2_wmmc.so
libcola2_wmm.so: CMakeFiles/cola2_wmm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adel/ros2_ws/build/cola2_lib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libcola2_wmm.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cola2_wmm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cola2_wmm.dir/build: libcola2_wmm.so
.PHONY : CMakeFiles/cola2_wmm.dir/build

CMakeFiles/cola2_wmm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cola2_wmm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cola2_wmm.dir/clean

CMakeFiles/cola2_wmm.dir/depend:
	cd /home/adel/ros2_ws/build/cola2_lib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adel/ros2_ws/src/cola2_lib /home/adel/ros2_ws/src/cola2_lib /home/adel/ros2_ws/build/cola2_lib /home/adel/ros2_ws/build/cola2_lib /home/adel/ros2_ws/build/cola2_lib/CMakeFiles/cola2_wmm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cola2_wmm.dir/depend

