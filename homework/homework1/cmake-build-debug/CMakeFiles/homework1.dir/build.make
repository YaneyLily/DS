# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yaney/Documents/DS/homework/homework1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yaney/Documents/DS/homework/homework1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/homework1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework1.dir/flags.make

CMakeFiles/homework1.dir/main.cpp.o: CMakeFiles/homework1.dir/flags.make
CMakeFiles/homework1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yaney/Documents/DS/homework/homework1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/homework1.dir/main.cpp.o -c /Users/yaney/Documents/DS/homework/homework1/main.cpp

CMakeFiles/homework1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yaney/Documents/DS/homework/homework1/main.cpp > CMakeFiles/homework1.dir/main.cpp.i

CMakeFiles/homework1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yaney/Documents/DS/homework/homework1/main.cpp -o CMakeFiles/homework1.dir/main.cpp.s

# Object files for target homework1
homework1_OBJECTS = \
"CMakeFiles/homework1.dir/main.cpp.o"

# External object files for target homework1
homework1_EXTERNAL_OBJECTS =

homework1: CMakeFiles/homework1.dir/main.cpp.o
homework1: CMakeFiles/homework1.dir/build.make
homework1: CMakeFiles/homework1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yaney/Documents/DS/homework/homework1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable homework1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework1.dir/build: homework1

.PHONY : CMakeFiles/homework1.dir/build

CMakeFiles/homework1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework1.dir/clean

CMakeFiles/homework1.dir/depend:
	cd /Users/yaney/Documents/DS/homework/homework1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yaney/Documents/DS/homework/homework1 /Users/yaney/Documents/DS/homework/homework1 /Users/yaney/Documents/DS/homework/homework1/cmake-build-debug /Users/yaney/Documents/DS/homework/homework1/cmake-build-debug /Users/yaney/Documents/DS/homework/homework1/cmake-build-debug/CMakeFiles/homework1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework1.dir/depend
