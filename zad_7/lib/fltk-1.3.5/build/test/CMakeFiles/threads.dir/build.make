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
include test/CMakeFiles/threads.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/threads.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/threads.dir/flags.make

test/CMakeFiles/threads.dir/threads.cxx.obj: test/CMakeFiles/threads.dir/flags.make
test/CMakeFiles/threads.dir/threads.cxx.obj: test/CMakeFiles/threads.dir/includes_CXX.rsp
test/CMakeFiles/threads.dir/threads.cxx.obj: ../test/threads.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/threads.dir/threads.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\threads.dir\threads.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\threads.cxx

test/CMakeFiles/threads.dir/threads.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threads.dir/threads.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\threads.cxx > CMakeFiles\threads.dir\threads.cxx.i

test/CMakeFiles/threads.dir/threads.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threads.dir/threads.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\threads.cxx -o CMakeFiles\threads.dir\threads.cxx.s

# Object files for target threads
threads_OBJECTS = \
"CMakeFiles/threads.dir/threads.cxx.obj"

# External object files for target threads
threads_EXTERNAL_OBJECTS =

bin/examples/threads.exe: test/CMakeFiles/threads.dir/threads.cxx.obj
bin/examples/threads.exe: test/CMakeFiles/threads.dir/build.make
bin/examples/threads.exe: lib/libfltk.a
bin/examples/threads.exe: test/CMakeFiles/threads.dir/linklibs.rsp
bin/examples/threads.exe: test/CMakeFiles/threads.dir/objects1.rsp
bin/examples/threads.exe: test/CMakeFiles/threads.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\threads.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\threads.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/threads.dir/build: bin/examples/threads.exe

.PHONY : test/CMakeFiles/threads.dir/build

test/CMakeFiles/threads.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\threads.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/threads.dir/clean

test/CMakeFiles/threads.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\threads.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/threads.dir/depend

