# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\Projekty\CLion\lib\cmake\bin\cmake.exe

# The command to remove a file.
RM = E:\Projekty\CLion\lib\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Projekty\CLion\lib\fltk-1.3.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Projekty\CLion\lib\fltk-1.3.5\build

# Include any dependencies generated for this target.
include test/CMakeFiles/preferences.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/preferences.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/preferences.dir/flags.make

test/preferences.cxx: ../test/preferences.fl
test/preferences.cxx: ../test/preferences.fl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating preferences.cxx, preferences.h"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && ..\bin\fluid.exe -c E:/Projekty/CLion/lib/fltk-1.3.5/test/preferences.fl

test/preferences.h: test/preferences.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate test\preferences.h

test/CMakeFiles/preferences.dir/preferences.cxx.obj: test/CMakeFiles/preferences.dir/flags.make
test/CMakeFiles/preferences.dir/preferences.cxx.obj: test/CMakeFiles/preferences.dir/includes_CXX.rsp
test/CMakeFiles/preferences.dir/preferences.cxx.obj: test/preferences.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/preferences.dir/preferences.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\preferences.dir\preferences.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\build\test\preferences.cxx

test/CMakeFiles/preferences.dir/preferences.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preferences.dir/preferences.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\build\test\preferences.cxx > CMakeFiles\preferences.dir\preferences.cxx.i

test/CMakeFiles/preferences.dir/preferences.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preferences.dir/preferences.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\build\test\preferences.cxx -o CMakeFiles\preferences.dir\preferences.cxx.s

# Object files for target preferences
preferences_OBJECTS = \
"CMakeFiles/preferences.dir/preferences.cxx.obj"

# External object files for target preferences
preferences_EXTERNAL_OBJECTS =

bin/examples/preferences.exe: test/CMakeFiles/preferences.dir/preferences.cxx.obj
bin/examples/preferences.exe: test/CMakeFiles/preferences.dir/build.make
bin/examples/preferences.exe: lib/libfltk.a
bin/examples/preferences.exe: test/CMakeFiles/preferences.dir/linklibs.rsp
bin/examples/preferences.exe: test/CMakeFiles/preferences.dir/objects1.rsp
bin/examples/preferences.exe: test/CMakeFiles/preferences.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\examples\preferences.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\preferences.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/preferences.dir/build: bin/examples/preferences.exe

.PHONY : test/CMakeFiles/preferences.dir/build

test/CMakeFiles/preferences.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\preferences.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/preferences.dir/clean

test/CMakeFiles/preferences.dir/depend: test/preferences.cxx
test/CMakeFiles/preferences.dir/depend: test/preferences.h
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\preferences.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/preferences.dir/depend

