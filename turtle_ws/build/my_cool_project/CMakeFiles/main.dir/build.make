# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/robat/.localgit/PROLab/turtle_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robat/.localgit/PROLab/turtle_ws/build

# Include any dependencies generated for this target.
include my_cool_project/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include my_cool_project/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include my_cool_project/CMakeFiles/main.dir/flags.make

my_cool_project/CMakeFiles/main.dir/src/main.cpp.o: my_cool_project/CMakeFiles/main.dir/flags.make
my_cool_project/CMakeFiles/main.dir/src/main.cpp.o: /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object my_cool_project/CMakeFiles/main.dir/src/main.cpp.o"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/src/main.cpp

my_cool_project/CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

my_cool_project/CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.o: my_cool_project/CMakeFiles/main.dir/flags.make
my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.o: /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.o"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/include/Controller.cpp.o -c /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Controller.cpp

my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/include/Controller.cpp.i"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Controller.cpp > CMakeFiles/main.dir/include/Controller.cpp.i

my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/include/Controller.cpp.s"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Controller.cpp -o CMakeFiles/main.dir/include/Controller.cpp.s

my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.o: my_cool_project/CMakeFiles/main.dir/flags.make
my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.o: /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/KalmannFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.o"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/include/KalmannFilter.cpp.o -c /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/KalmannFilter.cpp

my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/include/KalmannFilter.cpp.i"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/KalmannFilter.cpp > CMakeFiles/main.dir/include/KalmannFilter.cpp.i

my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/include/KalmannFilter.cpp.s"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/KalmannFilter.cpp -o CMakeFiles/main.dir/include/KalmannFilter.cpp.s

my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.o: my_cool_project/CMakeFiles/main.dir/flags.make
my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.o: /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Evaluation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.o"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/include/Evaluation.cpp.o -c /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Evaluation.cpp

my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/include/Evaluation.cpp.i"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Evaluation.cpp > CMakeFiles/main.dir/include/Evaluation.cpp.i

my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/include/Evaluation.cpp.s"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Evaluation.cpp -o CMakeFiles/main.dir/include/Evaluation.cpp.s

my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.o: my_cool_project/CMakeFiles/main.dir/flags.make
my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.o: /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Storage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.o"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/include/Storage.cpp.o -c /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Storage.cpp

my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/include/Storage.cpp.i"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Storage.cpp > CMakeFiles/main.dir/include/Storage.cpp.i

my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/include/Storage.cpp.s"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project/include/Storage.cpp -o CMakeFiles/main.dir/include/Storage.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/include/Controller.cpp.o" \
"CMakeFiles/main.dir/include/KalmannFilter.cpp.o" \
"CMakeFiles/main.dir/include/Evaluation.cpp.o" \
"CMakeFiles/main.dir/include/Storage.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/src/main.cpp.o
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/include/Controller.cpp.o
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/include/KalmannFilter.cpp.o
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/include/Evaluation.cpp.o
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/include/Storage.cpp.o
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/build.make
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libdynamic_reconfigure_config_init_mutex.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libactionlib.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libroscpp.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/librosconsole.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/librostime.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /opt/ros/noetic/lib/libcpp_common.so
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main: my_cool_project/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robat/.localgit/PROLab/turtle_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable /home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main"
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
my_cool_project/CMakeFiles/main.dir/build: /home/robat/.localgit/PROLab/turtle_ws/devel/lib/my_cool_project/main

.PHONY : my_cool_project/CMakeFiles/main.dir/build

my_cool_project/CMakeFiles/main.dir/clean:
	cd /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : my_cool_project/CMakeFiles/main.dir/clean

my_cool_project/CMakeFiles/main.dir/depend:
	cd /home/robat/.localgit/PROLab/turtle_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robat/.localgit/PROLab/turtle_ws/src /home/robat/.localgit/PROLab/turtle_ws/src/my_cool_project /home/robat/.localgit/PROLab/turtle_ws/build /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project /home/robat/.localgit/PROLab/turtle_ws/build/my_cool_project/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : my_cool_project/CMakeFiles/main.dir/depend

