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
include test/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/hello.dir/flags.make

test/CMakeFiles/hello.dir/hello.cxx.obj: test/CMakeFiles/hello.dir/flags.make
test/CMakeFiles/hello.dir/hello.cxx.obj: test/CMakeFiles/hello.dir/includes_CXX.rsp
test/CMakeFiles/hello.dir/hello.cxx.obj: ../test/hello.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/hello.dir/hello.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hello.dir\hello.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\hello.cxx

test/CMakeFiles/hello.dir/hello.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/hello.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\hello.cxx > CMakeFiles\hello.dir\hello.cxx.i

test/CMakeFiles/hello.dir/hello.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/hello.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\hello.cxx -o CMakeFiles\hello.dir\hello.cxx.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/hello.cxx.obj"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

bin/examples/hello.exe: test/CMakeFiles/hello.dir/hello.cxx.obj
bin/examples/hello.exe: test/CMakeFiles/hello.dir/build.make
bin/examples/hello.exe: lib/libfltk.a
bin/examples/hello.exe: test/CMakeFiles/hello.dir/linklibs.rsp
bin/examples/hello.exe: test/CMakeFiles/hello.dir/objects1.rsp
bin/examples/hello.exe: test/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\hello.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hello.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/hello.dir/build: bin/examples/hello.exe

.PHONY : test/CMakeFiles/hello.dir/build

test/CMakeFiles/hello.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\hello.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/hello.dir/clean

test/CMakeFiles/hello.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\hello.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/hello.dir/depend

