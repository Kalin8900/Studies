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
include test/CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/demo.dir/flags.make

test/CMakeFiles/demo.dir/demo.cxx.obj: test/CMakeFiles/demo.dir/flags.make
test/CMakeFiles/demo.dir/demo.cxx.obj: test/CMakeFiles/demo.dir/includes_CXX.rsp
test/CMakeFiles/demo.dir/demo.cxx.obj: ../test/demo.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/demo.dir/demo.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\demo.dir\demo.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\demo.cxx

test/CMakeFiles/demo.dir/demo.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/demo.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\demo.cxx > CMakeFiles\demo.dir\demo.cxx.i

test/CMakeFiles/demo.dir/demo.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/demo.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\demo.cxx -o CMakeFiles\demo.dir\demo.cxx.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/demo.cxx.obj"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

bin/examples/demo.exe: test/CMakeFiles/demo.dir/demo.cxx.obj
bin/examples/demo.exe: test/CMakeFiles/demo.dir/build.make
bin/examples/demo.exe: lib/libfltk.a
bin/examples/demo.exe: test/CMakeFiles/demo.dir/linklibs.rsp
bin/examples/demo.exe: test/CMakeFiles/demo.dir/objects1.rsp
bin/examples/demo.exe: test/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\demo.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/demo.dir/build: bin/examples/demo.exe

.PHONY : test/CMakeFiles/demo.dir/build

test/CMakeFiles/demo.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\demo.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/demo.dir/clean

test/CMakeFiles/demo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\demo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/demo.dir/depend

