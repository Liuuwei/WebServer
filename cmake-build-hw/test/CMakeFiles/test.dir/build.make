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
CMAKE_SOURCE_DIR = /clion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /clion/cmake-build-hw

# Include any dependencies generated for this target.
include test/CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test.dir/flags.make

test/CMakeFiles/test.dir/test.cc.o: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/test.cc.o: ../test/test.cc
test/CMakeFiles/test.dir/test.cc.o: test/CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/clion/cmake-build-hw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test.dir/test.cc.o"
	cd /clion/cmake-build-hw/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test.dir/test.cc.o -MF CMakeFiles/test.dir/test.cc.o.d -o CMakeFiles/test.dir/test.cc.o -c /clion/test/test.cc

test/CMakeFiles/test.dir/test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cc.i"
	cd /clion/cmake-build-hw/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /clion/test/test.cc > CMakeFiles/test.dir/test.cc.i

test/CMakeFiles/test.dir/test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cc.s"
	cd /clion/cmake-build-hw/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /clion/test/test.cc -o CMakeFiles/test.dir/test.cc.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cc.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

../bin/test: test/CMakeFiles/test.dir/test.cc.o
../bin/test: test/CMakeFiles/test.dir/build.make
../bin/test: ../lib/libWebServer.a
../bin/test: test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/clion/cmake-build-hw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/test"
	cd /clion/cmake-build-hw/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test.dir/build: ../bin/test
.PHONY : test/CMakeFiles/test.dir/build

test/CMakeFiles/test.dir/clean:
	cd /clion/cmake-build-hw/test && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test.dir/clean

test/CMakeFiles/test.dir/depend:
	cd /clion/cmake-build-hw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /clion /clion/test /clion/cmake-build-hw /clion/cmake-build-hw/test /clion/cmake-build-hw/test/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test.dir/depend

