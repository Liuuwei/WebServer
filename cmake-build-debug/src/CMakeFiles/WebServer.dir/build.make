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
CMAKE_SOURCE_DIR = /home/parallels/clion/WebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/clion/WebServer/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/WebServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/WebServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/WebServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/WebServer.dir/flags.make

src/CMakeFiles/WebServer.dir/Thread.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Thread.cc.o: ../src/Thread.cc
src/CMakeFiles/WebServer.dir/Thread.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/WebServer.dir/Thread.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Thread.cc.o -MF CMakeFiles/WebServer.dir/Thread.cc.o.d -o CMakeFiles/WebServer.dir/Thread.cc.o -c /home/parallels/clion/WebServer/src/Thread.cc

src/CMakeFiles/WebServer.dir/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Thread.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Thread.cc > CMakeFiles/WebServer.dir/Thread.cc.i

src/CMakeFiles/WebServer.dir/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Thread.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Thread.cc -o CMakeFiles/WebServer.dir/Thread.cc.s

src/CMakeFiles/WebServer.dir/Acceptor.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Acceptor.cc.o: ../src/Acceptor.cc
src/CMakeFiles/WebServer.dir/Acceptor.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/WebServer.dir/Acceptor.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Acceptor.cc.o -MF CMakeFiles/WebServer.dir/Acceptor.cc.o.d -o CMakeFiles/WebServer.dir/Acceptor.cc.o -c /home/parallels/clion/WebServer/src/Acceptor.cc

src/CMakeFiles/WebServer.dir/Acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Acceptor.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Acceptor.cc > CMakeFiles/WebServer.dir/Acceptor.cc.i

src/CMakeFiles/WebServer.dir/Acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Acceptor.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Acceptor.cc -o CMakeFiles/WebServer.dir/Acceptor.cc.s

src/CMakeFiles/WebServer.dir/Buffer.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Buffer.cc.o: ../src/Buffer.cc
src/CMakeFiles/WebServer.dir/Buffer.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/WebServer.dir/Buffer.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Buffer.cc.o -MF CMakeFiles/WebServer.dir/Buffer.cc.o.d -o CMakeFiles/WebServer.dir/Buffer.cc.o -c /home/parallels/clion/WebServer/src/Buffer.cc

src/CMakeFiles/WebServer.dir/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Buffer.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Buffer.cc > CMakeFiles/WebServer.dir/Buffer.cc.i

src/CMakeFiles/WebServer.dir/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Buffer.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Buffer.cc -o CMakeFiles/WebServer.dir/Buffer.cc.s

src/CMakeFiles/WebServer.dir/Channel.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Channel.cc.o: ../src/Channel.cc
src/CMakeFiles/WebServer.dir/Channel.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/WebServer.dir/Channel.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Channel.cc.o -MF CMakeFiles/WebServer.dir/Channel.cc.o.d -o CMakeFiles/WebServer.dir/Channel.cc.o -c /home/parallels/clion/WebServer/src/Channel.cc

src/CMakeFiles/WebServer.dir/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Channel.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Channel.cc > CMakeFiles/WebServer.dir/Channel.cc.i

src/CMakeFiles/WebServer.dir/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Channel.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Channel.cc -o CMakeFiles/WebServer.dir/Channel.cc.s

src/CMakeFiles/WebServer.dir/EventLoop.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/EventLoop.cc.o: ../src/EventLoop.cc
src/CMakeFiles/WebServer.dir/EventLoop.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/WebServer.dir/EventLoop.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/EventLoop.cc.o -MF CMakeFiles/WebServer.dir/EventLoop.cc.o.d -o CMakeFiles/WebServer.dir/EventLoop.cc.o -c /home/parallels/clion/WebServer/src/EventLoop.cc

src/CMakeFiles/WebServer.dir/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/EventLoop.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/EventLoop.cc > CMakeFiles/WebServer.dir/EventLoop.cc.i

src/CMakeFiles/WebServer.dir/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/EventLoop.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/EventLoop.cc -o CMakeFiles/WebServer.dir/EventLoop.cc.s

src/CMakeFiles/WebServer.dir/InetAddr.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/InetAddr.cc.o: ../src/InetAddr.cc
src/CMakeFiles/WebServer.dir/InetAddr.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/WebServer.dir/InetAddr.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/InetAddr.cc.o -MF CMakeFiles/WebServer.dir/InetAddr.cc.o.d -o CMakeFiles/WebServer.dir/InetAddr.cc.o -c /home/parallels/clion/WebServer/src/InetAddr.cc

src/CMakeFiles/WebServer.dir/InetAddr.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/InetAddr.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/InetAddr.cc > CMakeFiles/WebServer.dir/InetAddr.cc.i

src/CMakeFiles/WebServer.dir/InetAddr.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/InetAddr.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/InetAddr.cc -o CMakeFiles/WebServer.dir/InetAddr.cc.s

src/CMakeFiles/WebServer.dir/Poll.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Poll.cc.o: ../src/Poll.cc
src/CMakeFiles/WebServer.dir/Poll.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/WebServer.dir/Poll.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Poll.cc.o -MF CMakeFiles/WebServer.dir/Poll.cc.o.d -o CMakeFiles/WebServer.dir/Poll.cc.o -c /home/parallels/clion/WebServer/src/Poll.cc

src/CMakeFiles/WebServer.dir/Poll.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Poll.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Poll.cc > CMakeFiles/WebServer.dir/Poll.cc.i

src/CMakeFiles/WebServer.dir/Poll.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Poll.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Poll.cc -o CMakeFiles/WebServer.dir/Poll.cc.s

src/CMakeFiles/WebServer.dir/TcpConnection.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/TcpConnection.cc.o: ../src/TcpConnection.cc
src/CMakeFiles/WebServer.dir/TcpConnection.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/WebServer.dir/TcpConnection.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/TcpConnection.cc.o -MF CMakeFiles/WebServer.dir/TcpConnection.cc.o.d -o CMakeFiles/WebServer.dir/TcpConnection.cc.o -c /home/parallels/clion/WebServer/src/TcpConnection.cc

src/CMakeFiles/WebServer.dir/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/TcpConnection.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/TcpConnection.cc > CMakeFiles/WebServer.dir/TcpConnection.cc.i

src/CMakeFiles/WebServer.dir/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/TcpConnection.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/TcpConnection.cc -o CMakeFiles/WebServer.dir/TcpConnection.cc.s

src/CMakeFiles/WebServer.dir/TcpServer.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/TcpServer.cc.o: ../src/TcpServer.cc
src/CMakeFiles/WebServer.dir/TcpServer.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/WebServer.dir/TcpServer.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/TcpServer.cc.o -MF CMakeFiles/WebServer.dir/TcpServer.cc.o.d -o CMakeFiles/WebServer.dir/TcpServer.cc.o -c /home/parallels/clion/WebServer/src/TcpServer.cc

src/CMakeFiles/WebServer.dir/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/TcpServer.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/TcpServer.cc > CMakeFiles/WebServer.dir/TcpServer.cc.i

src/CMakeFiles/WebServer.dir/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/TcpServer.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/TcpServer.cc -o CMakeFiles/WebServer.dir/TcpServer.cc.s

src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o: ../src/ThreadPoll.cc
src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o -MF CMakeFiles/WebServer.dir/ThreadPoll.cc.o.d -o CMakeFiles/WebServer.dir/ThreadPoll.cc.o -c /home/parallels/clion/WebServer/src/ThreadPoll.cc

src/CMakeFiles/WebServer.dir/ThreadPoll.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/ThreadPoll.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/ThreadPoll.cc > CMakeFiles/WebServer.dir/ThreadPoll.cc.i

src/CMakeFiles/WebServer.dir/ThreadPoll.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/ThreadPoll.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/ThreadPoll.cc -o CMakeFiles/WebServer.dir/ThreadPoll.cc.s

src/CMakeFiles/WebServer.dir/HTTP.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/HTTP.cc.o: ../src/HTTP.cc
src/CMakeFiles/WebServer.dir/HTTP.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/WebServer.dir/HTTP.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/HTTP.cc.o -MF CMakeFiles/WebServer.dir/HTTP.cc.o.d -o CMakeFiles/WebServer.dir/HTTP.cc.o -c /home/parallels/clion/WebServer/src/HTTP.cc

src/CMakeFiles/WebServer.dir/HTTP.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/HTTP.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/HTTP.cc > CMakeFiles/WebServer.dir/HTTP.cc.i

src/CMakeFiles/WebServer.dir/HTTP.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/HTTP.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/HTTP.cc -o CMakeFiles/WebServer.dir/HTTP.cc.s

src/CMakeFiles/WebServer.dir/Mutex.cc.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Mutex.cc.o: ../src/Mutex.cc
src/CMakeFiles/WebServer.dir/Mutex.cc.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/WebServer.dir/Mutex.cc.o"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Mutex.cc.o -MF CMakeFiles/WebServer.dir/Mutex.cc.o.d -o CMakeFiles/WebServer.dir/Mutex.cc.o -c /home/parallels/clion/WebServer/src/Mutex.cc

src/CMakeFiles/WebServer.dir/Mutex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Mutex.cc.i"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/clion/WebServer/src/Mutex.cc > CMakeFiles/WebServer.dir/Mutex.cc.i

src/CMakeFiles/WebServer.dir/Mutex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Mutex.cc.s"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/clion/WebServer/src/Mutex.cc -o CMakeFiles/WebServer.dir/Mutex.cc.s

# Object files for target WebServer
WebServer_OBJECTS = \
"CMakeFiles/WebServer.dir/Thread.cc.o" \
"CMakeFiles/WebServer.dir/Acceptor.cc.o" \
"CMakeFiles/WebServer.dir/Buffer.cc.o" \
"CMakeFiles/WebServer.dir/Channel.cc.o" \
"CMakeFiles/WebServer.dir/EventLoop.cc.o" \
"CMakeFiles/WebServer.dir/InetAddr.cc.o" \
"CMakeFiles/WebServer.dir/Poll.cc.o" \
"CMakeFiles/WebServer.dir/TcpConnection.cc.o" \
"CMakeFiles/WebServer.dir/TcpServer.cc.o" \
"CMakeFiles/WebServer.dir/ThreadPoll.cc.o" \
"CMakeFiles/WebServer.dir/HTTP.cc.o" \
"CMakeFiles/WebServer.dir/Mutex.cc.o"

# External object files for target WebServer
WebServer_EXTERNAL_OBJECTS =

../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Thread.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Acceptor.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Buffer.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Channel.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/EventLoop.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/InetAddr.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Poll.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/TcpConnection.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/TcpServer.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/ThreadPoll.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/HTTP.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/Mutex.cc.o
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/build.make
../lib/libWebServer.a: src/CMakeFiles/WebServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/clion/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library ../../lib/libWebServer.a"
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/WebServer.dir/cmake_clean_target.cmake
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WebServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/WebServer.dir/build: ../lib/libWebServer.a
.PHONY : src/CMakeFiles/WebServer.dir/build

src/CMakeFiles/WebServer.dir/clean:
	cd /home/parallels/clion/WebServer/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/WebServer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/WebServer.dir/clean

src/CMakeFiles/WebServer.dir/depend:
	cd /home/parallels/clion/WebServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/clion/WebServer /home/parallels/clion/WebServer/src /home/parallels/clion/WebServer/cmake-build-debug /home/parallels/clion/WebServer/cmake-build-debug/src /home/parallels/clion/WebServer/cmake-build-debug/src/CMakeFiles/WebServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/WebServer.dir/depend

