cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.PhysicalModel.SolidMechanics.Elasticity.FEM LANGUAGES CXX)

set(SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR "src/sofa/components/physicalmodel/solidmechanics/elasticity/fem")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFASIMPLEFEM_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaSimpleFem/")
set(SOFASIMPLEFEM_SRC "${SOFASIMPLEFEM_DIR}/src/SofaSimpleFem")

set(SOFAGENERALSIMPLEFEM_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralSimpleFem/")
set(SOFAGENERALSIMPLEFEM_SRC "${SOFAGENERALSIMPLEFEM_DIR}/src/SofaGeneralSimpleFem")
set(SOFAMISCFEM_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscFem/")
set(SOFAMISCFEM_SRC "${SOFAMISCFEM_DIR}/src/SofaMiscFem")

set(HEADER_FILES
    ${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/config.h.in
    ${SOFASIMPLEFEM_SRC}/HexahedronFEMForceField.h
    ${SOFASIMPLEFEM_SRC}/HexahedronFEMForceField.inl
    ${SOFASIMPLEFEM_SRC}/TetrahedronFEMForceField.h
    ${SOFASIMPLEFEM_SRC}/TetrahedronFEMForceField.inl
    ${SOFASIMPLEFEM_SRC}/TetrahedronDiffusionFEMForceField.h
    ${SOFASIMPLEFEM_SRC}/TetrahedronDiffusionFEMForceField.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/BeamFEMForceField.h
    ${SOFAGENERALSIMPLEFEM_SRC}/BeamFEMForceField.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceField.h
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceField.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceFieldAndMass.h
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceFieldAndMass.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedronFEMForceFieldAndMass.h
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedronFEMForceFieldAndMass.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/TetrahedralCorotationalFEMForceField.h
    ${SOFAGENERALSIMPLEFEM_SRC}/TetrahedralCorotationalFEMForceField.inl
    ${SOFAGENERALSIMPLEFEM_SRC}/TriangularFEMForceFieldOptim.h
    ${SOFAGENERALSIMPLEFEM_SRC}/TriangularFEMForceFieldOptim.inl
    ${SOFAMISCFEM_SRC}/FastTetrahedralCorotationalForceField.h
    ${SOFAMISCFEM_SRC}/FastTetrahedralCorotationalForceField.inl
    ${SOFAMISCFEM_SRC}/TriangleFEMForceField.h
    ${SOFAMISCFEM_SRC}/TriangleFEMForceField.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/init.cpp
    ${SOFASIMPLEFEM_SRC}/HexahedronFEMForceField.cpp
    ${SOFASIMPLEFEM_SRC}/TetrahedronFEMForceField.cpp
    ${SOFASIMPLEFEM_SRC}/TetrahedronDiffusionFEMForceField.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/BeamFEMForceField.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceField.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedralFEMForceFieldAndMass.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/HexahedronFEMForceFieldAndMass.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/TetrahedralCorotationalFEMForceField.cpp
    ${SOFAGENERALSIMPLEFEM_SRC}/TriangularFEMForceFieldOptim.cpp
    ${SOFAMISCFEM_SRC}/FastTetrahedralCorotationalForceField.cpp
    ${SOFAMISCFEM_SRC}/TriangleFEMForceField.cpp
)
set(WRAPPER_FILES
    wrapper/SofaSimpleFem/config.h
    wrapper/SofaGeneralSimpleFem/config.h
    wrapper/SofaMiscFem/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/components/physicalmodel/solidmechanics/elasticity/fem/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.LinearSolver)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Topology)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFASIMPLEFEM_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALSIMPLEFEM_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMISCFEM_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFASIMPLEFEM)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALSIMPLEFEM)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMISCFEM)
