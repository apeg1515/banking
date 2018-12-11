cmake_minimum_required(VERSION 3.0)

project(bank)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wpedantic")

set(LIBRARIES_INLCUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries)

add_subdirectory(libraries)

include_directories(${LIBRARIES_INCLUDE_DIR})
add_executable(bank main.cpp)

target_link_libraries(bank libraries)
ADD_DEPENDENCIES(bank libraries)
