# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build"

# Include any dependencies generated for this target.
include CMakeFiles/GOL-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GOL-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GOL-test.dir/flags.make

CMakeFiles/GOL-test.dir/test_Logic.c.o: CMakeFiles/GOL-test.dir/flags.make
CMakeFiles/GOL-test.dir/test_Logic.c.o: ../test_Logic.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GOL-test.dir/test_Logic.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GOL-test.dir/test_Logic.c.o   -c "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/test_Logic.c"

CMakeFiles/GOL-test.dir/test_Logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL-test.dir/test_Logic.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/test_Logic.c" > CMakeFiles/GOL-test.dir/test_Logic.c.i

CMakeFiles/GOL-test.dir/test_Logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL-test.dir/test_Logic.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/test_Logic.c" -o CMakeFiles/GOL-test.dir/test_Logic.c.s

CMakeFiles/GOL-test.dir/test_Logic.c.o.requires:
.PHONY : CMakeFiles/GOL-test.dir/test_Logic.c.o.requires

CMakeFiles/GOL-test.dir/test_Logic.c.o.provides: CMakeFiles/GOL-test.dir/test_Logic.c.o.requires
	$(MAKE) -f CMakeFiles/GOL-test.dir/build.make CMakeFiles/GOL-test.dir/test_Logic.c.o.provides.build
.PHONY : CMakeFiles/GOL-test.dir/test_Logic.c.o.provides

CMakeFiles/GOL-test.dir/test_Logic.c.o.provides.build: CMakeFiles/GOL-test.dir/test_Logic.c.o

CMakeFiles/GOL-test.dir/Game_logic.c.o: CMakeFiles/GOL-test.dir/flags.make
CMakeFiles/GOL-test.dir/Game_logic.c.o: ../Game_logic.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GOL-test.dir/Game_logic.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GOL-test.dir/Game_logic.c.o   -c "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_logic.c"

CMakeFiles/GOL-test.dir/Game_logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL-test.dir/Game_logic.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_logic.c" > CMakeFiles/GOL-test.dir/Game_logic.c.i

CMakeFiles/GOL-test.dir/Game_logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL-test.dir/Game_logic.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_logic.c" -o CMakeFiles/GOL-test.dir/Game_logic.c.s

CMakeFiles/GOL-test.dir/Game_logic.c.o.requires:
.PHONY : CMakeFiles/GOL-test.dir/Game_logic.c.o.requires

CMakeFiles/GOL-test.dir/Game_logic.c.o.provides: CMakeFiles/GOL-test.dir/Game_logic.c.o.requires
	$(MAKE) -f CMakeFiles/GOL-test.dir/build.make CMakeFiles/GOL-test.dir/Game_logic.c.o.provides.build
.PHONY : CMakeFiles/GOL-test.dir/Game_logic.c.o.provides

CMakeFiles/GOL-test.dir/Game_logic.c.o.provides.build: CMakeFiles/GOL-test.dir/Game_logic.c.o

CMakeFiles/GOL-test.dir/Game_interface.c.o: CMakeFiles/GOL-test.dir/flags.make
CMakeFiles/GOL-test.dir/Game_interface.c.o: ../Game_interface.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build/CMakeFiles" $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GOL-test.dir/Game_interface.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GOL-test.dir/Game_interface.c.o   -c "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_interface.c"

CMakeFiles/GOL-test.dir/Game_interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL-test.dir/Game_interface.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_interface.c" > CMakeFiles/GOL-test.dir/Game_interface.c.i

CMakeFiles/GOL-test.dir/Game_interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL-test.dir/Game_interface.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Game_interface.c" -o CMakeFiles/GOL-test.dir/Game_interface.c.s

CMakeFiles/GOL-test.dir/Game_interface.c.o.requires:
.PHONY : CMakeFiles/GOL-test.dir/Game_interface.c.o.requires

CMakeFiles/GOL-test.dir/Game_interface.c.o.provides: CMakeFiles/GOL-test.dir/Game_interface.c.o.requires
	$(MAKE) -f CMakeFiles/GOL-test.dir/build.make CMakeFiles/GOL-test.dir/Game_interface.c.o.provides.build
.PHONY : CMakeFiles/GOL-test.dir/Game_interface.c.o.provides

CMakeFiles/GOL-test.dir/Game_interface.c.o.provides.build: CMakeFiles/GOL-test.dir/Game_interface.c.o

CMakeFiles/GOL-test.dir/Unity/src/unity.c.o: CMakeFiles/GOL-test.dir/flags.make
CMakeFiles/GOL-test.dir/Unity/src/unity.c.o: ../Unity/src/unity.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build/CMakeFiles" $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GOL-test.dir/Unity/src/unity.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/GOL-test.dir/Unity/src/unity.c.o   -c "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Unity/src/unity.c"

CMakeFiles/GOL-test.dir/Unity/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GOL-test.dir/Unity/src/unity.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Unity/src/unity.c" > CMakeFiles/GOL-test.dir/Unity/src/unity.c.i

CMakeFiles/GOL-test.dir/Unity/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GOL-test.dir/Unity/src/unity.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/Unity/src/unity.c" -o CMakeFiles/GOL-test.dir/Unity/src/unity.c.s

CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.requires:
.PHONY : CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.requires

CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.provides: CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.requires
	$(MAKE) -f CMakeFiles/GOL-test.dir/build.make CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.provides.build
.PHONY : CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.provides

CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.provides.build: CMakeFiles/GOL-test.dir/Unity/src/unity.c.o

# Object files for target GOL-test
GOL__test_OBJECTS = \
"CMakeFiles/GOL-test.dir/test_Logic.c.o" \
"CMakeFiles/GOL-test.dir/Game_logic.c.o" \
"CMakeFiles/GOL-test.dir/Game_interface.c.o" \
"CMakeFiles/GOL-test.dir/Unity/src/unity.c.o"

# External object files for target GOL-test
GOL__test_EXTERNAL_OBJECTS =

GOL-test: CMakeFiles/GOL-test.dir/test_Logic.c.o
GOL-test: CMakeFiles/GOL-test.dir/Game_logic.c.o
GOL-test: CMakeFiles/GOL-test.dir/Game_interface.c.o
GOL-test: CMakeFiles/GOL-test.dir/Unity/src/unity.c.o
GOL-test: CMakeFiles/GOL-test.dir/build.make
GOL-test: CMakeFiles/GOL-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable GOL-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GOL-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GOL-test.dir/build: GOL-test
.PHONY : CMakeFiles/GOL-test.dir/build

CMakeFiles/GOL-test.dir/requires: CMakeFiles/GOL-test.dir/test_Logic.c.o.requires
CMakeFiles/GOL-test.dir/requires: CMakeFiles/GOL-test.dir/Game_logic.c.o.requires
CMakeFiles/GOL-test.dir/requires: CMakeFiles/GOL-test.dir/Game_interface.c.o.requires
CMakeFiles/GOL-test.dir/requires: CMakeFiles/GOL-test.dir/Unity/src/unity.c.o.requires
.PHONY : CMakeFiles/GOL-test.dir/requires

CMakeFiles/GOL-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GOL-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GOL-test.dir/clean

CMakeFiles/GOL-test.dir/depend:
	cd "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2" "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2" "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build" "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build" "/home/cserv1_a/elec_msc/el20ss/CODE/el20ss/Coursework 2/build/CMakeFiles/GOL-test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GOL-test.dir/depend

