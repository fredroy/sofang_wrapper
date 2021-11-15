cmake_minimum_required(VERSION 3.12)
project(SCPSES LANGUAGES CXX)

set(TOO_LONG_TARGET_NAME Sofa.Component.PhysicalModel.SolidMechanics.Elasticity.Springs)

set(SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_SOURCE_DIR "src/sofa/component/physicalmodel/solidmechanics/elasticity/springs")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFADEFORMABLE_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaDeformable/")
set(SOFADEFORMABLE_SRC "${SOFADEFORMABLE_DIR}/src/SofaDeformable")
set(SOFAOBJECTINTERACTION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaObjectInteraction/")
set(SOFAOBJECTINTERACTION_SRC "${SOFAOBJECTINTERACTION_DIR}/src/SofaObjectInteraction")
set(SOFARIGID_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaRigid/")
set(SOFARIGID_SRC "${SOFARIGID_DIR}/src/SofaRigid")

# WARNING: this takes all of SofaGeneralDeformable **EXCEPT** TriangularTensorMassForceField
set(SOFAGENERALDEFORMABLE_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralDeformable/")
set(SOFAGENERALDEFORMABLE_SRC "${SOFAGENERALDEFORMABLE_DIR}/src/SofaGeneralDeformable")
set(SOFAGENERALOBJECTINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralObjectInteraction/")
set(SOFAGENERALOBJECTINTERACTION_SRC "${SOFAGENERALOBJECTINTERACTION_DIR}/src/SofaGeneralObjectInteraction")

set(HEADER_FILES
    ${SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_SOURCE_DIR}/config.h.in 
    ${SOFADEFORMABLE_SRC}/MeshSpringForceField.h
    ${SOFADEFORMABLE_SRC}/MeshSpringForceField.inl
    ${SOFADEFORMABLE_SRC}/RestShapeSpringsForceField.h
    ${SOFADEFORMABLE_SRC}/RestShapeSpringsForceField.inl
    ${SOFADEFORMABLE_SRC}/SpringForceField.h
    ${SOFADEFORMABLE_SRC}/SpringForceField.inl
    ${SOFADEFORMABLE_SRC}/StiffSpringForceField.h
    ${SOFADEFORMABLE_SRC}/StiffSpringForceField.inl
    ${SOFAOBJECTINTERACTION_SRC}/PenalityContactForceField.h
    ${SOFAOBJECTINTERACTION_SRC}/PenalityContactForceField.inl
    ${SOFARIGID_SRC}/JointSpring.h
    ${SOFARIGID_SRC}/JointSpring.inl
    ${SOFARIGID_SRC}/JointSpringForceField.h
    ${SOFARIGID_SRC}/JointSpringForceField.inl
    ${SOFADEFORMABLE_SRC}/AngularSpringForceField.h
    ${SOFADEFORMABLE_SRC}/AngularSpringForceField.inl
    ${SOFADEFORMABLE_SRC}/PolynomialRestShapeSpringsForceField.h
    ${SOFADEFORMABLE_SRC}/PolynomialRestShapeSpringsForceField.inl
    ${SOFADEFORMABLE_SRC}/PolynomialSpringsForceField.h
    ${SOFADEFORMABLE_SRC}/PolynomialSpringsForceField.inl
    ${SOFAGENERALDEFORMABLE_SRC}/FastTriangularBendingSprings.h
    ${SOFAGENERALDEFORMABLE_SRC}/FastTriangularBendingSprings.inl
    ${SOFAGENERALDEFORMABLE_SRC}/FrameSpringForceField.h
    ${SOFAGENERALDEFORMABLE_SRC}/FrameSpringForceField.inl
    ${SOFAGENERALDEFORMABLE_SRC}/QuadBendingSprings.h
    ${SOFAGENERALDEFORMABLE_SRC}/QuadBendingSprings.inl
    ${SOFAGENERALDEFORMABLE_SRC}/QuadularBendingSprings.h
    ${SOFAGENERALDEFORMABLE_SRC}/QuadularBendingSprings.inl
    ${SOFAGENERALDEFORMABLE_SRC}/RegularGridSpringForceField.h
    ${SOFAGENERALDEFORMABLE_SRC}/RegularGridSpringForceField.inl
    ${SOFAGENERALDEFORMABLE_SRC}/TriangleBendingSprings.h
    ${SOFAGENERALDEFORMABLE_SRC}/TriangleBendingSprings.inl
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBendingSprings.h
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBendingSprings.inl
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBiquadraticSpringsForceField.h
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBiquadraticSpringsForceField.inl
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularQuadraticSpringsForceField.h
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularQuadraticSpringsForceField.inl
    # ${SOFAGENERALDEFORMABLE_SRC}/TriangularTensorMassForceField.h
    # ${SOFAGENERALDEFORMABLE_SRC}/TriangularTensorMassForceField.inl
    ${SOFAGENERALDEFORMABLE_SRC}/VectorSpringForceField.h
    ${SOFAGENERALDEFORMABLE_SRC}/VectorSpringForceField.inl
    ${SOFAGENERALOBJECTINTERACTION_SRC}/BoxStiffSpringForceField.h
    ${SOFAGENERALOBJECTINTERACTION_SRC}/BoxStiffSpringForceField.inl
    ${SOFAGENERALOBJECTINTERACTION_SRC}/RepulsiveSpringForceField.h
    ${SOFAGENERALOBJECTINTERACTION_SRC}/RepulsiveSpringForceField.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_SOURCE_DIR}/init.cpp
    ${SOFADEFORMABLE_SRC}/MeshSpringForceField.cpp
    ${SOFADEFORMABLE_SRC}/RestShapeSpringsForceField.cpp
    ${SOFADEFORMABLE_SRC}/SpringForceField.cpp
    ${SOFADEFORMABLE_SRC}/StiffSpringForceField.cpp
    ${SOFAOBJECTINTERACTION_SRC}/PenalityContactForceField.cpp
    ${SOFARIGID_SRC}/JointSpring.cpp
    ${SOFARIGID_SRC}/JointSpringForceField.cpp
    ${SOFADEFORMABLE_SRC}/AngularSpringForceField.cpp
    ${SOFADEFORMABLE_SRC}/PolynomialRestShapeSpringsForceField.cpp
    ${SOFADEFORMABLE_SRC}/PolynomialSpringsForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/FastTriangularBendingSprings.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/FrameSpringForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/QuadBendingSprings.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/QuadularBendingSprings.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/RegularGridSpringForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/TriangleBendingSprings.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBendingSprings.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularBiquadraticSpringsForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularQuadraticSpringsForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/TriangularTensorMassForceField.cpp
    ${SOFAGENERALDEFORMABLE_SRC}/VectorSpringForceField.cpp
    ${SOFAGENERALOBJECTINTERACTION_SRC}/BoxStiffSpringForceField.cpp
    ${SOFAGENERALOBJECTINTERACTION_SRC}/RepulsiveSpringForceField.cpp
)

set(WRAPPER_FILES
    wrapper/SofaDeformable/config.h
    wrapper/SofaObjectInteraction/config.h
    wrapper/SofaGeneralDeformable/config.h
    wrapper/SofaGeneralObjectInteraction/config.h
    wrapper/SofaRigid/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Topology.Grid)

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/physicalmodel/solidmechanics/elasticity/springs/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
add_library(${TOO_LONG_TARGET_NAME} ALIAS ${TARGET_NAME})
set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${TOO_LONG_TARGET_NAME})
set_target_properties(${TARGET_NAME} PROPERTIES PROJECT_LABEL ${TOO_LONG_TARGET_NAME})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology.Grid)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFADEFORMABLE)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAOBJECTINTERACTION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFARIGID)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALDEFORMABLE)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALOBJECTINTERACTION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFADEFORMABLE_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAOBJECTINTERACTION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFARIGID_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALDEFORMABLE_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALOBJECTINTERACTION_DIR}/src")
