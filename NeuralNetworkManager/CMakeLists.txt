project(NeuralNetworkManager)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC
        "*.h"
        "*.cpp"
        )

set(SUB_PROJECT_NAME NeuralNetworkManager)
include_directories(${PROJECT_BASE_DIRECTORY})

set(REFERENCE_PROJECTS_LIST
        Json
        NeuralNetworksCollection
    )

add_library(${SUB_PROJECT_NAME} SHARED ${SRC})

set_target_properties(${SUB_PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIRECTORY})

foreach(REF_PROJECT ${REFERENCE_PROJECTS_LIST})
    target_link_libraries(${SUB_PROJECT_NAME} ${REF_PROJECT})
endforeach()