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
include test/CMakeFiles/gl_overlay.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/gl_overlay.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/gl_overlay.dir/flags.make

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj: test/CMakeFiles/gl_overlay.dir/flags.make
test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj: test/CMakeFiles/gl_overlay.dir/includes_CXX.rsp
test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj: ../test/gl_overlay.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gl_overlay.dir\gl_overlay.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\gl_overlay.cxx

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl_overlay.dir/gl_overlay.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\gl_overlay.cxx > CMakeFiles\gl_overlay.dir\gl_overlay.cxx.i

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl_overlay.dir/gl_overlay.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\gl_overlay.cxx -o CMakeFiles\gl_overlay.dir\gl_overlay.cxx.s

# Object files for target gl_overlay
gl_overlay_OBJECTS = \
"CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj"

# External object files for target gl_overlay
gl_overlay_EXTERNAL_OBJECTS =

bin/examples/gl_overlay.exe: test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.obj
bin/examples/gl_overlay.exe: test/CMakeFiles/gl_overlay.dir/build.make
bin/examples/gl_overlay.exe: lib/libfltk.a
bin/examples/gl_overlay.exe: lib/libfltk_gl.a
bin/examples/gl_overlay.exe: lib/libfltk.a
bin/examples/gl_overlay.exe: test/CMakeFiles/gl_overlay.dir/linklibs.rsp
bin/examples/gl_overlay.exe: test/CMakeFiles/gl_overlay.dir/objects1.rsp
bin/examples/gl_overlay.exe: test/CMakeFiles/gl_overlay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\gl_overlay.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gl_overlay.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/gl_overlay.dir/build: bin/examples/gl_overlay.exe

.PHONY : test/CMakeFiles/gl_overlay.dir/build

test/CMakeFiles/gl_overlay.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\gl_overlay.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/gl_overlay.dir/clean

test/CMakeFiles/gl_overlay.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\gl_overlay.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/gl_overlay.dir/depend

