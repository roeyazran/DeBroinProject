project(DeBroinProject)
include_directories( ${MY_SOURCE_DIR}/src )
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)  # enable C++11 standard
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")
add_executable (DeBroin main.cpp PrimitiveAlgo.cc GeneralClasses.cc)