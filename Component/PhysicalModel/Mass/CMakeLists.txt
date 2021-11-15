cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.PhysicalModel.Mass LANGUAGES CXX)

set(SOFACOMPONENTPHYSICALMODELMASS_SOURCE_DIR "src/sofa/component/physicalmodel/mass")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEMECHANICS_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseMechanics/")
set(SOFABASEMECHANICS_SRC "${SOFABASEMECHANICS_DIR}/src/SofaBaseMechanics")

set(SOFAMISCFORCEFIELD_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscForceField/")
set(SOFAMISCFORCEFIELD_SRC "${SOFAMISCFORCEFIELD_DIR}/src/SofaMiscForceField")

set(HEADER_FILES
	${SOFACOMPONENTPHYSICALMODELMASS_SOURCE_DIR}/config.h.in
    ${SOFABASEMECHANICS_SRC}/AddMToMatrixFunctor.h
    ${SOFABASEMECHANICS_SRC}/DiagonalMass.h
    ${SOFABASEMECHANICS_SRC}/DiagonalMass.inl
    ${SOFABASEMECHANICS_SRC}/UniformMass.h
    ${SOFABASEMECHANICS_SRC}/UniformMass.inl
    ${SOFAMISCFORCEFIELD_SRC}/MeshMatrixMass.h
    ${SOFAMISCFORCEFIELD_SRC}/MeshMatrixMass.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTPHYSICALMODELMASS_SOURCE_DIR}/init.cpp
    ${SOFABASEMECHANICS_SRC}/DiagonalMass.cpp
    ${SOFABASEMECHANICS_SRC}/UniformMass.cpp
    ${SOFAMISCFORCEFIELD_SRC}/MeshMatrixMass.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseMechanics/config.h
    wrapper/SofaMiscForceField/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Topology.Grid)
sofang_check_dependencies(Sofa.Component.Topology.DynamicContainer) #TODO: replace once #2436 is merged

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTPHYSICALMODELMASS_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/physicalmodel/mass/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Topology.Grid)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Topology.DynamicContainer)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASEMECHANICS_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMISCFORCEFIELD_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASEMECHANICS)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMISCFORCEFIELD)
