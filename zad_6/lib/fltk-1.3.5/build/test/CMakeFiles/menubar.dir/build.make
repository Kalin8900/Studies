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
include test/CMakeFiles/menubar.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/menubar.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/menubar.dir/flags.make

test/CMakeFiles/menubar.dir/menubar.cxx.obj: test/CMakeFiles/menubar.dir/flags.make
test/CMakeFiles/menubar.dir/menubar.cxx.obj: test/CMakeFiles/menubar.dir/includes_CXX.rsp
test/CMakeFiles/menubar.dir/menubar.cxx.obj: ../test/menubar.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/menubar.dir/menubar.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\menubar.dir\menubar.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\menubar.cxx

test/CMakeFiles/menubar.dir/menubar.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/menubar.dir/menubar.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\menubar.cxx > CMakeFiles\menubar.dir\menubar.cxx.i

test/CMakeFiles/menubar.dir/menubar.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/menubar.dir/menubar.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\menubar.cxx -o CMakeFiles\menubar.dir\menubar.cxx.s

# Object files for target menubar
menubar_OBJECTS = \
"CMakeFiles/menubar.dir/menubar.cxx.obj"

# External object files for target menubar
menubar_EXTERNAL_OBJECTS =

bin/examples/menubar.exe: test/CMakeFiles/menubar.dir/menubar.cxx.obj
bin/examples/menubar.exe: test/CMakeFiles/menubar.dir/build.make
bin/examples/menubar.exe: lib/libfltk.a
bin/examples/menubar.exe: test/CMakeFiles/menubar.dir/linklibs.rsp
bin/examples/menubar.exe: test/CMakeFiles/menubar.dir/objects1.rsp
bin/examples/menubar.exe: test/CMakeFiles/menubar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\menubar.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\menubar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/menubar.dir/build: bin/examples/menubar.exe

.PHONY : test/CMakeFiles/menubar.dir/build

test/CMakeFiles/menubar.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\menubar.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/menubar.dir/clean

test/CMakeFiles/menubar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\menubar.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/menubar.dir/depend

