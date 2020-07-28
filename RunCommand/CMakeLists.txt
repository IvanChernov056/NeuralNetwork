include(${SCRIPTS_DIRECTORY}/CMakeScripts.cmake)

set(SUB_PROJECT_NAME RunCommand)
init_sub_project(${SUB_PROJECT_NAME})

set(REFERENCE_PROJECTS_LIST
        NeuralNetworkManager
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIRECTORY})
add_executable(${SUB_PROJECT_NAME}  ${SRC} )

#set_target_properties(${SUB_PROJECT_NAME} PROPERTIES CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIRECTORY})


foreach(REF_PROJECT ${REFERENCE_PROJECTS_LIST})
    target_link_libraries(${SUB_PROJECT_NAME} ${REF_PROJECT})
endforeach()