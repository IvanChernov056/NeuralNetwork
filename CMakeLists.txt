cmake_minimum_required(VERSION 3.16)
project(NeuralNetworks)

set(CMAKE_CXX_STANDARD 20)
option(USE_CLANG "build application with clang" ON)

set(PROJECT_NAME NeuralNetworks)
set(PROJECT_BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(BIN_OUTPUT_DIRECTORY ${PROJECT_BASE_DIRECTORY}/../${PROJECT_NAME}_Output/bin)
set(LIB_OUTPUT_DIRECTORY ${PROJECT_BASE_DIRECTORY}/../${PROJECT_NAME}_Output/lib)


set(SUB_PROJECTS_LIST
        RunCommand
        NeuralNetworkManager
        NeuralNetworksCollection
        Json
    )

foreach(SUB_PROJECT ${SUB_PROJECTS_LIST})
    add_subdirectory(${SUB_PROJECT})
endforeach()
