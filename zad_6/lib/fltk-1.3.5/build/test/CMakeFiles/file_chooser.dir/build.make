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
include test/CMakeFiles/file_chooser.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/file_chooser.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/file_chooser.dir/flags.make

test/CMakeFiles/file_chooser.dir/file_chooser.cxx.obj: test/CMakeFiles/file_chooser.dir/flags.make
test/CMakeFiles/file_chooser.dir/file_chooser.cxx.obj: test/CMakeFiles/file_chooser.dir/includes_CXX.rsp
test/CMakeFiles/file_chooser.dir/file_chooser.cxx.obj: ../test/file_chooser.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/file_chooser.dir/file_chooser.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\file_chooser.dir\file_chooser.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\file_chooser.cxx

test/CMakeFiles/file_chooser.dir/file_chooser.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/file_chooser.dir/file_chooser.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\file_chooser.cxx > CMakeFiles\file_chooser.dir\file_chooser.cxx.i

test/CMakeFiles/file_chooser.dir/file_chooser.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/file_chooser.dir/file_chooser.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\file_chooser.cxx -o CMakeFiles\file_chooser.dir\file_chooser.cxx.s

# Object files for target file_chooser
file_chooser_OBJECTS = \
"CMakeFiles/file_chooser.dir/file_chooser.cxx.obj"

# External object files for target file_chooser
file_chooser_EXTERNAL_OBJECTS =

bin/examples/file_chooser.exe: test/CMakeFiles/file_chooser.dir/file_chooser.cxx.obj
bin/examples/file_chooser.exe: test/CMakeFiles/file_chooser.dir/build.make
bin/examples/file_chooser.exe: lib/libfltk.a
bin/examples/file_chooser.exe: lib/libfltk_images.a
bin/examples/file_chooser.exe: lib/libfltk.a
bin/examples/file_chooser.exe: lib/libfltk_jpeg.a
bin/examples/file_chooser.exe: lib/libfltk_png.a
bin/examples/file_chooser.exe: lib/libfltk_z.a
bin/examples/file_chooser.exe: test/CMakeFiles/file_chooser.dir/linklibs.rsp
bin/examples/file_chooser.exe: test/CMakeFiles/file_chooser.dir/objects1.rsp
bin/examples/file_chooser.exe: test/CMakeFiles/file_chooser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\file_chooser.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\file_chooser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/file_chooser.dir/build: bin/examples/file_chooser.exe

.PHONY : test/CMakeFiles/file_chooser.dir/build

test/CMakeFiles/file_chooser.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\file_chooser.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/file_chooser.dir/clean

test/CMakeFiles/file_chooser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\file_chooser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/file_chooser.dir/depend

