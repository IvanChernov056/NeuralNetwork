
macro(init_sub_project SUB_PROJECT_NAME)
    project(${SUB_PROJECT_NAME})
    cmake_minimum_required(VERSION 3.16)
    set(CMAKE_CXX_STANDARD 20)
    file(GLOB SRC
            "*.h"
            "*.cpp"
            )
    include_directories(${PROJECT_BASE_DIRECTORY})
endmacro()

function(build_sub_project_shared_lib SUB_PROJECT_NAME REFERENCE_PROJECTS_LIST)
    add_library(${SUB_PROJECT_NAME} SHARED ${SRC})

    set_target_properties(${SUB_PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIRECTORY})

    foreach(REF_PROJECT ${REFERENCE_PROJECTS_LIST})
        target_link_libraries(${SUB_PROJECT_NAME} ${REF_PROJECT})
    endforeach()
endfunction()