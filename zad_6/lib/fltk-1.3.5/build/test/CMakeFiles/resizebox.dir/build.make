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
include test/CMakeFiles/resizebox.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/resizebox.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/resizebox.dir/flags.make

test/CMakeFiles/resizebox.dir/resizebox.cxx.obj: test/CMakeFiles/resizebox.dir/flags.make
test/CMakeFiles/resizebox.dir/resizebox.cxx.obj: test/CMakeFiles/resizebox.dir/includes_CXX.rsp
test/CMakeFiles/resizebox.dir/resizebox.cxx.obj: ../test/resizebox.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/resizebox.dir/resizebox.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\resizebox.dir\resizebox.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\resizebox.cxx

test/CMakeFiles/resizebox.dir/resizebox.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/resizebox.dir/resizebox.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\resizebox.cxx > CMakeFiles\resizebox.dir\resizebox.cxx.i

test/CMakeFiles/resizebox.dir/resizebox.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/resizebox.dir/resizebox.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\resizebox.cxx -o CMakeFiles\resizebox.dir\resizebox.cxx.s

# Object files for target resizebox
resizebox_OBJECTS = \
"CMakeFiles/resizebox.dir/resizebox.cxx.obj"

# External object files for target resizebox
resizebox_EXTERNAL_OBJECTS =

bin/examples/resizebox.exe: test/CMakeFiles/resizebox.dir/resizebox.cxx.obj
bin/examples/resizebox.exe: test/CMakeFiles/resizebox.dir/build.make
bin/examples/resizebox.exe: lib/libfltk.a
bin/examples/resizebox.exe: test/CMakeFiles/resizebox.dir/linklibs.rsp
bin/examples/resizebox.exe: test/CMakeFiles/resizebox.dir/objects1.rsp
bin/examples/resizebox.exe: test/CMakeFiles/resizebox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\resizebox.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\resizebox.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/resizebox.dir/build: bin/examples/resizebox.exe

.PHONY : test/CMakeFiles/resizebox.dir/build

test/CMakeFiles/resizebox.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\resizebox.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/resizebox.dir/clean

test/CMakeFiles/resizebox.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\resizebox.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/resizebox.dir/depend

