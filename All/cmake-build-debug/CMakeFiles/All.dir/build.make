# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/ealvarenga/Downloads/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ealvarenga/Downloads/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ealvarenga/Projetos/FEI/EstruturaDados/All

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/All.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/All.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/All.dir/flags.make

CMakeFiles/All.dir/main.cpp.o: CMakeFiles/All.dir/flags.make
CMakeFiles/All.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/All.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/All.dir/main.cpp.o -c /home/ealvarenga/Projetos/FEI/EstruturaDados/All/main.cpp

CMakeFiles/All.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/All.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ealvarenga/Projetos/FEI/EstruturaDados/All/main.cpp > CMakeFiles/All.dir/main.cpp.i

CMakeFiles/All.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/All.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ealvarenga/Projetos/FEI/EstruturaDados/All/main.cpp -o CMakeFiles/All.dir/main.cpp.s

CMakeFiles/All.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/All.dir/main.cpp.o.requires

CMakeFiles/All.dir/main.cpp.o.provides: CMakeFiles/All.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/All.dir/build.make CMakeFiles/All.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/All.dir/main.cpp.o.provides

CMakeFiles/All.dir/main.cpp.o.provides.build: CMakeFiles/All.dir/main.cpp.o


CMakeFiles/All.dir/LES/les.cpp.o: CMakeFiles/All.dir/flags.make
CMakeFiles/All.dir/LES/les.cpp.o: ../LES/les.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/All.dir/LES/les.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/All.dir/LES/les.cpp.o -c /home/ealvarenga/Projetos/FEI/EstruturaDados/All/LES/les.cpp

CMakeFiles/All.dir/LES/les.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/All.dir/LES/les.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ealvarenga/Projetos/FEI/EstruturaDados/All/LES/les.cpp > CMakeFiles/All.dir/LES/les.cpp.i

CMakeFiles/All.dir/LES/les.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/All.dir/LES/les.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ealvarenga/Projetos/FEI/EstruturaDados/All/LES/les.cpp -o CMakeFiles/All.dir/LES/les.cpp.s

CMakeFiles/All.dir/LES/les.cpp.o.requires:

.PHONY : CMakeFiles/All.dir/LES/les.cpp.o.requires

CMakeFiles/All.dir/LES/les.cpp.o.provides: CMakeFiles/All.dir/LES/les.cpp.o.requires
	$(MAKE) -f CMakeFiles/All.dir/build.make CMakeFiles/All.dir/LES/les.cpp.o.provides.build
.PHONY : CMakeFiles/All.dir/LES/les.cpp.o.provides

CMakeFiles/All.dir/LES/les.cpp.o.provides.build: CMakeFiles/All.dir/LES/les.cpp.o


# Object files for target All
All_OBJECTS = \
"CMakeFiles/All.dir/main.cpp.o" \
"CMakeFiles/All.dir/LES/les.cpp.o"

# External object files for target All
All_EXTERNAL_OBJECTS =

All: CMakeFiles/All.dir/main.cpp.o
All: CMakeFiles/All.dir/LES/les.cpp.o
All: CMakeFiles/All.dir/build.make
All: CMakeFiles/All.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable All"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/All.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/All.dir/build: All

.PHONY : CMakeFiles/All.dir/build

CMakeFiles/All.dir/requires: CMakeFiles/All.dir/main.cpp.o.requires
CMakeFiles/All.dir/requires: CMakeFiles/All.dir/LES/les.cpp.o.requires

.PHONY : CMakeFiles/All.dir/requires

CMakeFiles/All.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/All.dir/cmake_clean.cmake
.PHONY : CMakeFiles/All.dir/clean

CMakeFiles/All.dir/depend:
	cd /home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ealvarenga/Projetos/FEI/EstruturaDados/All /home/ealvarenga/Projetos/FEI/EstruturaDados/All /home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug /home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug /home/ealvarenga/Projetos/FEI/EstruturaDados/All/cmake-build-debug/CMakeFiles/All.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/All.dir/depend

