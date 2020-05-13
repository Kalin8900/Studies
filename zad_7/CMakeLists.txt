cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(zad_7)

set(FLTK_DIR ./lib/fltk-1.3.5/build)

find_package(FLTK REQUIRED NO_MODULE)

include_directories(${FLTK_INCLUDE_DIRS})

include_directories(./lib/graph_lib)

aux_source_directory(./lib/graph_lib GRAPH_LIB)

set(SOURCE_CODE main.cpp myWindow.cpp myWindow.h ./lib/graph_lib/Graph.h)

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE_CODE} ${GRAPH_LIB})

target_link_libraries(${CMAKE_PROJECT_NAME} fltk fltk_images)