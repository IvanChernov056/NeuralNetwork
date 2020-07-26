project(Json)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC
        "*.h"
        "*.cpp"
        )

set(SUB_PROJECT_NAME Json)
include_directories(${PROJECT_BASE_DIRECTORY})

add_library(${SUB_PROJECT_NAME} SHARED ${SRC})

set_target_properties(${SUB_PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIRECTORY})