cmake_minimum_required(VERSION 3.12)
project(runSofa LANGUAGES CXX)

set(SOFAAPPLICATIONSRUNSOFA_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")
set(SOFAAPPLICATIONS_SOURCE_DIR "${SOFA_SOURCE_DIR}/applications")

set(RUNSOFA_SOURCE_DIR "${SOFAAPPLICATIONS_SOURCE_DIR}/projects/runSofa")

set(HEADER_FILES
    ${RUNSOFA_SOURCE_DIR}/runSofaValidation.h
    )
set(SOURCE_FILES
    ${RUNSOFA_SOURCE_DIR}/Main.cpp
    ${RUNSOFA_SOURCE_DIR}/runSofaNoValidation.cpp
    )

set(WRAPPER_FILES
    wrapper/SofaGui/initSofaGui.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})
	
sofa_find_package(SofaFramework REQUIRED)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationGraph)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.GUI.Core)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Utils)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.IO.Mesh)

target_include_directories(${PROJECT_NAME} PUBLIC "${RUNSOFA_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
