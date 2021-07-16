cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Mapping LANGUAGES CXX)

set(SOFACOMPONENTSANIMATIONMAPPING_SOURCE_DIR "src/sofa/components/mapping")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEMECHANICS_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseMechanics/")
set(SOFABASEMECHANICS_SRC "${SOFABASEMECHANICS_DIR}/src/SofaBaseMechanics")
set(SOFARIGID_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaRigid/")
set(SOFARIGID_SRC "${SOFARIGID_DIR}/src/SofaRigid")

set(SOFAGENERALRIGID_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralRigid/")
set(SOFAGENERALRIGID_SRC "${SOFAGENERALRIGID_DIR}/src/SofaGeneralRigid")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTSANIMATIONMAPPING_SOURCE_DIR}/config.h.in
    ${SOFABASEMECHANICS_SRC}/BarycentricMapping.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMapping.inl
    ${SOFABASEMECHANICS_SRC}/IdentityMapping.h
    ${SOFABASEMECHANICS_SRC}/IdentityMapping.inl
    ${SOFABASEMECHANICS_SRC}/MappedObject.h
    ${SOFABASEMECHANICS_SRC}/MappedObject.inl
    ${SOFABASEMECHANICS_SRC}/SubsetMapping.h
    ${SOFABASEMECHANICS_SRC}/SubsetMapping.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapper.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapper.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/TopologyBarycentricMapper.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/TopologyBarycentricMapper.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperMeshTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperMeshTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperRegularGridTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperRegularGridTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperSparseGridTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperSparseGridTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTopologyContainer.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTopologyContainer.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperEdgeSetTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperEdgeSetTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTriangleSetTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTriangleSetTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperQuadSetTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperQuadSetTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTetrahedronSetTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTetrahedronSetTopology.inl
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperHexahedronSetTopology.h
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperHexahedronSetTopology.inl
    ${SOFARIGID_SRC}/RigidMapping.h
    ${SOFARIGID_SRC}/RigidMapping.inl
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTSANIMATIONMAPPING_SOURCE_DIR}/initMinimal.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMapping.cpp
    ${SOFABASEMECHANICS_SRC}/IdentityMapping.cpp
    ${SOFABASEMECHANICS_SRC}/MappedObject.cpp
    ${SOFABASEMECHANICS_SRC}/SubsetMapping.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapper.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/TopologyBarycentricMapper.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperMeshTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperRegularGridTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperSparseGridTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTopologyContainer.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperEdgeSetTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTriangleSetTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperQuadSetTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperTetrahedronSetTopology.cpp
    ${SOFABASEMECHANICS_SRC}/BarycentricMappers/BarycentricMapperHexahedronSetTopology.cpp
    ${SOFARIGID_SRC}/RigidMapping.cpp
)

# Full set
set(HEADER_FILES
    ${SOFACOMPONENTSANIMATIONMAPPING_SOURCE_DIR}/init.cpp
    ${SOFARIGID_SRC}/RigidRigidMapping.h
    ${SOFARIGID_SRC}/RigidRigidMapping.inl
    ${SOFAGENERALRIGID_SRC}/ArticulatedHierarchyContainer.h
    ${SOFAGENERALRIGID_SRC}/ArticulatedHierarchyContainer.inl
    ${SOFAGENERALRIGID_SRC}/ArticulatedSystemMapping.h
    ${SOFAGENERALRIGID_SRC}/ArticulatedSystemMapping.inl
    ${SOFAGENERALRIGID_SRC}/LineSetSkinningMapping.h
    ${SOFAGENERALRIGID_SRC}/LineSetSkinningMapping.inl
    ${SOFAGENERALRIGID_SRC}/SkinningMapping.h
    ${SOFAGENERALRIGID_SRC}/SkinningMapping.inl
    ${SOFAGENERALRIGID_SRC}/bvh/BVHChannels.h
    ${SOFAGENERALRIGID_SRC}/bvh/BVHJoint.h
    ${SOFAGENERALRIGID_SRC}/bvh/BVHLoader.h
    ${SOFAGENERALRIGID_SRC}/bvh/BVHMotion.h
    ${SOFAGENERALRIGID_SRC}/bvh/BVHOffset.h
)

set(SOURCE_FILES
    ${SOFARIGID_SRC}/RigidRigidMapping.cpp
    ${SOFAGENERALRIGID_SRC}/ArticulatedHierarchyContainer.cpp
    ${SOFAGENERALRIGID_SRC}/ArticulatedSystemMapping.cpp
    ${SOFAGENERALRIGID_SRC}/LineSetSkinningMapping.cpp
    ${SOFAGENERALRIGID_SRC}/SkinningMapping.cpp
    ${SOFAGENERALRIGID_SRC}/bvh/BVHJoint.cpp
    ${SOFAGENERALRIGID_SRC}/bvh/BVHLoader.cpp
    ${SOFAGENERALRIGID_SRC}/bvh/BVHMotion.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseMechanics/config.h
    wrapper/SofaRigid/config.h
    wrapper/SofaGeneralRigid/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSANIMATIONMAPPING_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/mapping/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.LinearSolver_minimal)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Topology_minimal)

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASEMECHANICS)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFARIGID)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFABASEMECHANICS_DIR}/src")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFARIGID_DIR}/src")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.LinearSolver)
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.Topology)

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAGENERALRIGID_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFARIGID)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALRIGID)
