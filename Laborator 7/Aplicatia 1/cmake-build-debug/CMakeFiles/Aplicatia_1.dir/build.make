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
CMAKE_COMMAND = /home/auras/Documents/CLion/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/auras/Documents/CLion/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/auras/Documents/POO/Laborator 7/Aplicatia 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Aplicatia_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Aplicatia_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aplicatia_1.dir/flags.make

CMakeFiles/Aplicatia_1.dir/main.cpp.o: CMakeFiles/Aplicatia_1.dir/flags.make
CMakeFiles/Aplicatia_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aplicatia_1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Aplicatia_1.dir/main.cpp.o -c "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/main.cpp"

CMakeFiles/Aplicatia_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aplicatia_1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/main.cpp" > CMakeFiles/Aplicatia_1.dir/main.cpp.i

CMakeFiles/Aplicatia_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aplicatia_1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/main.cpp" -o CMakeFiles/Aplicatia_1.dir/main.cpp.s

CMakeFiles/Aplicatia_1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Aplicatia_1.dir/main.cpp.o.requires

CMakeFiles/Aplicatia_1.dir/main.cpp.o.provides: CMakeFiles/Aplicatia_1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Aplicatia_1.dir/build.make CMakeFiles/Aplicatia_1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Aplicatia_1.dir/main.cpp.o.provides

CMakeFiles/Aplicatia_1.dir/main.cpp.o.provides.build: CMakeFiles/Aplicatia_1.dir/main.cpp.o


# Object files for target Aplicatia_1
Aplicatia_1_OBJECTS = \
"CMakeFiles/Aplicatia_1.dir/main.cpp.o"

# External object files for target Aplicatia_1
Aplicatia_1_EXTERNAL_OBJECTS =

Aplicatia_1: CMakeFiles/Aplicatia_1.dir/main.cpp.o
Aplicatia_1: CMakeFiles/Aplicatia_1.dir/build.make
Aplicatia_1: CMakeFiles/Aplicatia_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Aplicatia_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Aplicatia_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Aplicatia_1.dir/build: Aplicatia_1

.PHONY : CMakeFiles/Aplicatia_1.dir/build

CMakeFiles/Aplicatia_1.dir/requires: CMakeFiles/Aplicatia_1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Aplicatia_1.dir/requires

CMakeFiles/Aplicatia_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Aplicatia_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Aplicatia_1.dir/clean

CMakeFiles/Aplicatia_1.dir/depend:
	cd "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/auras/Documents/POO/Laborator 7/Aplicatia 1" "/home/auras/Documents/POO/Laborator 7/Aplicatia 1" "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug" "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug" "/home/auras/Documents/POO/Laborator 7/Aplicatia 1/cmake-build-debug/CMakeFiles/Aplicatia_1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Aplicatia_1.dir/depend

