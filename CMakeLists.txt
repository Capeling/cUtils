cmake_minimum_required(VERSION 3.29)
project(cUtils)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CUTILS_SOURCES "src/*.cpp")
add_library(cUtils STATIC ${CUTILS_SOURCES})
target_include_directories(cUtils PUBLIC include)

option(CUTILS_BUILD_TESTS "Build tests" off)
if(NOT CUTILS_BUILD_TESTS)
    return()
endif()

add_executable(cutils_test test/main.cpp)
target_link_libraries(cutils_test cUtils)