cmake_minimum_required(VERSION 3.16)
project(Json)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES *.cpp)

add_library(libJson ${SOURCE_FILES})