cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Container LANGUAGES CXX)

set(SOFACOMPONENTCONTAINER_SOURCE_DIR "src/sofa/component/container")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEMECHANICS_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseMechanics/")
set(SOFABASEMECHANICS_SRC "${SOFABASEMECHANICS_DIR}/src/SofaBaseMechanics")

set(HEADER_FILES
	${SOFACOMPONENTCONTAINER_SOURCE_DIR}/config.h.in
    ${SOFABASEMECHANICS_SRC}/MechanicalObject.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTCONTAINER_SOURCE_DIR}/init.cpp
    ${SOFABASEMECHANICS_SRC}/MechanicalObject.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseMechanics/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCONTAINER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/container/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASEMECHANICS_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASEMECHANICS)