project(RunCommand)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC
        "*.h"
        "*.cpp"
        )

set(SUB_PROJECT_NAME RunCommand)
include_directories(${PROJECT_BASE_DIRECTORY})

set(REFERENCE_PROJECTS_LIST
        NeuralNetworkManager
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIRECTORY})
add_executable(${SUB_PROJECT_NAME}  ${SRC} )

#set_target_properties(${SUB_PROJECT_NAME} PROPERTIES CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIRECTORY})


foreach(REF_PROJECT ${REFERENCE_PROJECTS_LIST})
    target_link_libraries(${SUB_PROJECT_NAME} ${REF_PROJECT})
endforeach()