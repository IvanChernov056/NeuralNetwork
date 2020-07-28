include(${SCRIPTS_DIRECTORY}/CMakeScripts.cmake)

set(SUB_PROJECT_NAME NeuralNetworksCollection)
init_sub_project(${SUB_PROJECT_NAME})

set(REFERENCE_PROJECTS_LIST
        Json
    )

build_sub_project_shared_lib(${SUB_PROJECT_NAME} ${REFERENCE_PROJECTS_LIST})