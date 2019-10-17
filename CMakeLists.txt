cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})

project(GasAutomaton)

add_executable(GasAutomaton src/main.cpp src/lattice.h src/GasAutomaton.cpp src/cellular.h)
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})