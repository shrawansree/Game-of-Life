# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\_Achu documents\UNI\COMP1921\Coursework 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\_Achu documents\UNI\COMP1921\Coursework 2\build"

# Include any dependencies generated for this target.
include CMakeFiles/GOL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GOL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GOL.dir/flags.make

CMakeFiles/GOL.dir/main.obj: CMakeFiles/GOL.dir/flags.make
CMakeFiles/GOL.dir/main.obj: CMakeFiles/GOL.dir/includes_C.rsp
CMakeFiles/GOL.dir/main.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\_Achu documents\UNI\COMP1921\Coursework 2\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GOL.dir/main.obj"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GOL.dir\main.obj -c "E:\_Achu documents\UNI\COMP1921\Coursework 2\main.c"

CMakeFiles/GOL.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL.dir/main.i"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\_Achu documents\UNI\COMP1921\Coursework 2\main.c" > CMakeFiles\GOL.dir\main.i

CMakeFiles/GOL.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL.dir/main.s"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\_Achu documents\UNI\COMP1921\Coursework 2\main.c" -o CMakeFiles\GOL.dir\main.s

CMakeFiles/GOL.dir/Game_logic.obj: CMakeFiles/GOL.dir/flags.make
CMakeFiles/GOL.dir/Game_logic.obj: CMakeFiles/GOL.dir/includes_C.rsp
CMakeFiles/GOL.dir/Game_logic.obj: ../Game_logic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\_Achu documents\UNI\COMP1921\Coursework 2\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GOL.dir/Game_logic.obj"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GOL.dir\Game_logic.obj -c "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_logic.c"

CMakeFiles/GOL.dir/Game_logic.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL.dir/Game_logic.i"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_logic.c" > CMakeFiles\GOL.dir\Game_logic.i

CMakeFiles/GOL.dir/Game_logic.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL.dir/Game_logic.s"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_logic.c" -o CMakeFiles\GOL.dir\Game_logic.s

CMakeFiles/GOL.dir/Game_interface.obj: CMakeFiles/GOL.dir/flags.make
CMakeFiles/GOL.dir/Game_interface.obj: CMakeFiles/GOL.dir/includes_C.rsp
CMakeFiles/GOL.dir/Game_interface.obj: ../Game_interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\_Achu documents\UNI\COMP1921\Coursework 2\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GOL.dir/Game_interface.obj"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GOL.dir\Game_interface.obj -c "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_interface.c"

CMakeFiles/GOL.dir/Game_interface.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL.dir/Game_interface.i"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_interface.c" > CMakeFiles\GOL.dir\Game_interface.i

CMakeFiles/GOL.dir/Game_interface.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL.dir/Game_interface.s"
	C:\DevTools\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\_Achu documents\UNI\COMP1921\Coursework 2\Game_interface.c" -o CMakeFiles\GOL.dir\Game_interface.s

# Object files for target GOL
GOL_OBJECTS = \
"CMakeFiles/GOL.dir/main.obj" \
"CMakeFiles/GOL.dir/Game_logic.obj" \
"CMakeFiles/GOL.dir/Game_interface.obj"

# External object files for target GOL
GOL_EXTERNAL_OBJECTS =

GOL.exe: CMakeFiles/GOL.dir/main.obj
GOL.exe: CMakeFiles/GOL.dir/Game_logic.obj
GOL.exe: CMakeFiles/GOL.dir/Game_interface.obj
GOL.exe: CMakeFiles/GOL.dir/build.make
GOL.exe: CMakeFiles/GOL.dir/linklibs.rsp
GOL.exe: CMakeFiles/GOL.dir/objects1.rsp
GOL.exe: CMakeFiles/GOL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\_Achu documents\UNI\COMP1921\Coursework 2\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable GOL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GOL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GOL.dir/build: GOL.exe

.PHONY : CMakeFiles/GOL.dir/build

CMakeFiles/GOL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GOL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GOL.dir/clean

CMakeFiles/GOL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\_Achu documents\UNI\COMP1921\Coursework 2" "E:\_Achu documents\UNI\COMP1921\Coursework 2" "E:\_Achu documents\UNI\COMP1921\Coursework 2\build" "E:\_Achu documents\UNI\COMP1921\Coursework 2\build" "E:\_Achu documents\UNI\COMP1921\Coursework 2\build\CMakeFiles\GOL.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GOL.dir/depend

