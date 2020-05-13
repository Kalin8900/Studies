cmake_minimum_required(VERSION 3.16)
project(graph)

set(CMAKE_CXX_STANDARD 11)

set(FLTK_DIR ../lib/fltk-1.3.5/build)

find_package(FLTK REQUIRED NO_MODULE)

include_directories(${FLTK_INCLUDE_DIRS})

set(SOURCE_CODE Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

add_library(graph fltk fltk.h Graph.h GUI.h Simple_window.h
        Window.h std_lib_facilities.h ${SOURCE_CODE})

target_link_libraries(graph fltk)