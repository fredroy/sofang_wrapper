cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.PhysicalModel.SolidMechanics.Elasticity.FEM LANGUAGES CXX)

set(SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR "src/sofa/components/physicalmodels/solidmechanics/elasticity/fem")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEMECHANICS_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseMechanics/")
set(SOFABASEMECHANICS_SRC "${SOFABASEMECHANICS_DIR}/src/SofaBaseMechanics")

set(SOFAMISCFORCEFIELD_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscForceField/")
set(SOFAMISCFORCEFIELD_SRC "${SOFAMISCFORCEFIELD_DIR}/src/SofaMiscForceField")

set(HEADER_FILES
    ${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/init.cpp
)

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/components/physicalmodels/solidmechanics/elasticity/fem/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Topology)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASEMECHANICS_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMISCFORCEFIELD_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASEMECHANICS)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMISCFORCEFIELD)
