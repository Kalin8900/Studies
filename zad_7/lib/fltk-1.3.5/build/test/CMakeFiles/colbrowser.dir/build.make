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
include test/CMakeFiles/colbrowser.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/colbrowser.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/colbrowser.dir/flags.make

test/CMakeFiles/colbrowser.dir/colbrowser.cxx.obj: test/CMakeFiles/colbrowser.dir/flags.make
test/CMakeFiles/colbrowser.dir/colbrowser.cxx.obj: test/CMakeFiles/colbrowser.dir/includes_CXX.rsp
test/CMakeFiles/colbrowser.dir/colbrowser.cxx.obj: ../test/colbrowser.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/colbrowser.dir/colbrowser.cxx.obj"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\colbrowser.dir\colbrowser.cxx.obj -c E:\Projekty\CLion\lib\fltk-1.3.5\test\colbrowser.cxx

test/CMakeFiles/colbrowser.dir/colbrowser.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colbrowser.dir/colbrowser.cxx.i"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Projekty\CLion\lib\fltk-1.3.5\test\colbrowser.cxx > CMakeFiles\colbrowser.dir\colbrowser.cxx.i

test/CMakeFiles/colbrowser.dir/colbrowser.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colbrowser.dir/colbrowser.cxx.s"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && E:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Projekty\CLion\lib\fltk-1.3.5\test\colbrowser.cxx -o CMakeFiles\colbrowser.dir\colbrowser.cxx.s

# Object files for target colbrowser
colbrowser_OBJECTS = \
"CMakeFiles/colbrowser.dir/colbrowser.cxx.obj"

# External object files for target colbrowser
colbrowser_EXTERNAL_OBJECTS =

bin/examples/colbrowser.exe: test/CMakeFiles/colbrowser.dir/colbrowser.cxx.obj
bin/examples/colbrowser.exe: test/CMakeFiles/colbrowser.dir/build.make
bin/examples/colbrowser.exe: lib/libfltk.a
bin/examples/colbrowser.exe: lib/libfltk_forms.a
bin/examples/colbrowser.exe: lib/libfltk.a
bin/examples/colbrowser.exe: test/CMakeFiles/colbrowser.dir/linklibs.rsp
bin/examples/colbrowser.exe: test/CMakeFiles/colbrowser.dir/objects1.rsp
bin/examples/colbrowser.exe: test/CMakeFiles/colbrowser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Projekty\CLion\lib\fltk-1.3.5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\bin\examples\colbrowser.exe"
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\colbrowser.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/colbrowser.dir/build: bin/examples/colbrowser.exe

.PHONY : test/CMakeFiles/colbrowser.dir/build

test/CMakeFiles/colbrowser.dir/clean:
	cd /d E:\Projekty\CLion\lib\fltk-1.3.5\build\test && $(CMAKE_COMMAND) -P CMakeFiles\colbrowser.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/colbrowser.dir/clean

test/CMakeFiles/colbrowser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Projekty\CLion\lib\fltk-1.3.5 E:\Projekty\CLion\lib\fltk-1.3.5\test E:\Projekty\CLion\lib\fltk-1.3.5\build E:\Projekty\CLion\lib\fltk-1.3.5\build\test E:\Projekty\CLion\lib\fltk-1.3.5\build\test\CMakeFiles\colbrowser.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/colbrowser.dir/depend

