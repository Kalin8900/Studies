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
include test/CMakeFiles/radio.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/radio.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/radio.dir/flags.make

test/radio.cxx: ../test/radio.fl
test/radio.cxx: ../test/radio.fl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating radio.cxx, radio.h"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && ..\bin\fluid.exe -c E:/Projekty/CLion/lib/fltk-1.3.5/test/radio.fl

test/radio.h: test/radio.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate test\radio.h

test/CMakeFiles/radio.dir/radio.cxx.obj: test/CMakeFiles/radio.dir/flags.make
test/CMakeFiles/radio.dir/radio.cxx.obj: test/CMakeFiles/radio.dir/includes_CXX.rsp
test/CMakeFiles/radio.dir/radio.cxx.obj: test/radio.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/radio.dir/radio.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\radio.dir\radio.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\build\test\radio.cxx

test/CMakeFiles/radio.dir/radio.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radio.dir/radio.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\build\test\radio.cxx > CMakeFiles\radio.dir\radio.cxx.i

test/CMakeFiles/radio.dir/radio.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radio.dir/radio.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\build\test\radio.cxx -o CMakeFiles\radio.dir\radio.cxx.s

# Object files for target radio
radio_OBJECTS = \
"CMakeFiles/radio.dir/radio.cxx.obj"

# External object files for target radio
radio_EXTERNAL_OBJECTS =

bin/examples/radio.exe: test/CMakeFiles/radio.dir/radio.cxx.obj
bin/examples/radio.exe: test/CMakeFiles/radio.dir/build.make
bin/examples/radio.exe: lib/libfltk.a
bin/examples/radio.exe: test/CMakeFiles/radio.dir/linklibs.rsp
bin/examples/radio.exe: test/CMakeFiles/radio.dir/objects1.rsp
bin/examples/radio.exe: test/CMakeFiles/radio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\examples\radio.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\radio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/radio.dir/build: bin/examples/radio.exe

.PHONY : test/CMakeFiles/radio.dir/build

test/CMakeFiles/radio.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\radio.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/radio.dir/clean

test/CMakeFiles/radio.dir/depend: test/radio.cxx
test/CMakeFiles/radio.dir/depend: test/radio.h
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\radio.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/radio.dir/depend
