# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/C_String_Algorithms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C_String_Algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C_String_Algorithms.dir/flags.make

CMakeFiles/C_String_Algorithms.dir/main.c.obj: CMakeFiles/C_String_Algorithms.dir/flags.make
CMakeFiles/C_String_Algorithms.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C_String_Algorithms.dir/main.c.obj"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C_String_Algorithms.dir\main.c.obj   -c "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\main.c"

CMakeFiles/C_String_Algorithms.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_String_Algorithms.dir/main.c.i"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\main.c" > CMakeFiles\C_String_Algorithms.dir\main.c.i

CMakeFiles/C_String_Algorithms.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_String_Algorithms.dir/main.c.s"
	C:\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\main.c" -o CMakeFiles\C_String_Algorithms.dir\main.c.s

# Object files for target C_String_Algorithms
C_String_Algorithms_OBJECTS = \
"CMakeFiles/C_String_Algorithms.dir/main.c.obj"

# External object files for target C_String_Algorithms
C_String_Algorithms_EXTERNAL_OBJECTS =

C_String_Algorithms.exe: CMakeFiles/C_String_Algorithms.dir/main.c.obj
C_String_Algorithms.exe: CMakeFiles/C_String_Algorithms.dir/build.make
C_String_Algorithms.exe: CMakeFiles/C_String_Algorithms.dir/linklibs.rsp
C_String_Algorithms.exe: CMakeFiles/C_String_Algorithms.dir/objects1.rsp
C_String_Algorithms.exe: CMakeFiles/C_String_Algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C_String_Algorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C_String_Algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C_String_Algorithms.dir/build: C_String_Algorithms.exe

.PHONY : CMakeFiles/C_String_Algorithms.dir/build

CMakeFiles/C_String_Algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C_String_Algorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C_String_Algorithms.dir/clean

CMakeFiles/C_String_Algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms" "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms" "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug" "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug" "C:\Users\crist\Documents\UPTC\4 SEMESTRE\Programacion III\C String Algorithms\cmake-build-debug\CMakeFiles\C_String_Algorithms.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C_String_Algorithms.dir/depend
