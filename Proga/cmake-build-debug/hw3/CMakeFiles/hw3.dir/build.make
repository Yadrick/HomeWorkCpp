# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\CLion 2021.2.1\polytech"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\CLion 2021.2.1\polytech\cmake-build-debug"

# Include any dependencies generated for this target.
include hw3/CMakeFiles/hw3.dir/depend.make
# Include the progress variables for this target.
include hw3/CMakeFiles/hw3.dir/progress.make

# Include the compile flags for this target's objects.
include hw3/CMakeFiles/hw3.dir/flags.make

hw3/CMakeFiles/hw3.dir/main.cpp.obj: hw3/CMakeFiles/hw3.dir/flags.make
hw3/CMakeFiles/hw3.dir/main.cpp.obj: ../hw3/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\CLion 2021.2.1\polytech\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hw3/CMakeFiles/hw3.dir/main.cpp.obj"
	cd /d "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" && E:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hw3.dir\main.cpp.obj -c "E:\CLion 2021.2.1\polytech\hw3\main.cpp"

hw3/CMakeFiles/hw3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3.dir/main.cpp.i"
	cd /d "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" && E:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\CLion 2021.2.1\polytech\hw3\main.cpp" > CMakeFiles\hw3.dir\main.cpp.i

hw3/CMakeFiles/hw3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3.dir/main.cpp.s"
	cd /d "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" && E:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\CLion 2021.2.1\polytech\hw3\main.cpp" -o CMakeFiles\hw3.dir\main.cpp.s

# Object files for target hw3
hw3_OBJECTS = \
"CMakeFiles/hw3.dir/main.cpp.obj"

# External object files for target hw3
hw3_EXTERNAL_OBJECTS =

hw3/hw3.exe: hw3/CMakeFiles/hw3.dir/main.cpp.obj
hw3/hw3.exe: hw3/CMakeFiles/hw3.dir/build.make
hw3/hw3.exe: hw3/CMakeFiles/hw3.dir/linklibs.rsp
hw3/hw3.exe: hw3/CMakeFiles/hw3.dir/objects1.rsp
hw3/hw3.exe: hw3/CMakeFiles/hw3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\CLion 2021.2.1\polytech\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw3.exe"
	cd /d "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hw3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hw3/CMakeFiles/hw3.dir/build: hw3/hw3.exe
.PHONY : hw3/CMakeFiles/hw3.dir/build

hw3/CMakeFiles/hw3.dir/clean:
	cd /d "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" && $(CMAKE_COMMAND) -P CMakeFiles\hw3.dir\cmake_clean.cmake
.PHONY : hw3/CMakeFiles/hw3.dir/clean

hw3/CMakeFiles/hw3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\CLion 2021.2.1\polytech" "E:\CLion 2021.2.1\polytech\hw3" "E:\CLion 2021.2.1\polytech\cmake-build-debug" "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3" "E:\CLion 2021.2.1\polytech\cmake-build-debug\hw3\CMakeFiles\hw3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : hw3/CMakeFiles/hw3.dir/depend

