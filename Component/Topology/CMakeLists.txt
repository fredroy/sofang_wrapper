cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGY_SOURCE_DIR "src/sofa/component/topology")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASETOPOLOGY_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseTopology/")
set(SOFABASETOPOLOGY_SRC "${SOFABASETOPOLOGY_DIR}/src/SofaBaseTopology")

set(SOFAGENERALTOPOLOGY_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralTopology/")
set(SOFAGENERALTOPOLOGY_SRC "${SOFAGENERALTOPOLOGY_DIR}/src/SofaGeneralTopology")
set(SOFATOPOLOGYMAPPING_DIR "${SOFAMODULES_SOURCE_DIR}/SofaTopologyMapping/")
set(SOFATOPOLOGYMAPPING_SRC "${SOFATOPOLOGYMAPPING_DIR}/src/SofaTopologyMapping")
set(SOFANONUNIFORMFEM_DIR "${SOFAMODULES_SOURCE_DIR}/SofaNonUniformFem/")
set(SOFANONUNIFORMFEM_SRC "${SOFANONUNIFORMFEM_DIR}/src/SofaNonUniformFem")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/config.h.in
    ${SOFABASETOPOLOGY_SRC}/fwd.h
    ${SOFABASETOPOLOGY_SRC}/initSofaBaseTopology.h
    ${SOFABASETOPOLOGY_SRC}/CommonAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/GridTopology.h
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/MeshTopology.h
    ${SOFABASETOPOLOGY_SRC}/NumericalIntegrationDescriptor.h
    ${SOFABASETOPOLOGY_SRC}/NumericalIntegrationDescriptor.inl
    ${SOFABASETOPOLOGY_SRC}/PointSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/PointSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/PointSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/PointSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/PointSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/QuadSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/QuadSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/QuadSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/QuadSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/QuadSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/RegularGridTopology.h
    ${SOFABASETOPOLOGY_SRC}/SparseGridTopology.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/TopologyData.h
    ${SOFABASETOPOLOGY_SRC}/TopologyData.inl
    ${SOFABASETOPOLOGY_SRC}/TopologyDataHandler.h
    ${SOFABASETOPOLOGY_SRC}/TopologyDataHandler.inl
    ${SOFABASETOPOLOGY_SRC}/TopologySparseData.h
    ${SOFABASETOPOLOGY_SRC}/TopologySparseData.inl
    ${SOFABASETOPOLOGY_SRC}/TopologySubsetData.h
    ${SOFABASETOPOLOGY_SRC}/TopologySubsetData.inl
    ${SOFABASETOPOLOGY_SRC}/TopologySubsetIndices.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/polygon_cube_intersection.h
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/vec.h
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/initMinimal.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/GridTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/HexahedronSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/MeshTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/NumericalIntegrationDescriptor.cpp
    ${SOFABASETOPOLOGY_SRC}/PointSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/PointSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/PointSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/QuadSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/QuadSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/QuadSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/RegularGridTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/SparseGridTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/TopologySubsetData.cpp
    ${SOFABASETOPOLOGY_SRC}/TopologySubsetIndices.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/fast_polygon_cube_intersection.cpp
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/polygon_cube_intersection.cpp
)

# Full set
set(HEADER_FILES
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/CylinderGridTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/SphereGridTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.h
    ${SOFATOPOLOGYMAPPING_SRC}/CenterPointTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Edge2QuadTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Hexa2QuadTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Hexa2TetraTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/IdentityTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Mesh2PointMechanicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Mesh2PointMechanicalMapping.inl
    ${SOFATOPOLOGYMAPPING_SRC}/Mesh2PointTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Quad2TriangleTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedHexaTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedTetraMechanicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedTetraMechanicalMapping.inl
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedTetraTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/SubsetTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Tetra2TriangleTopologicalMapping.h
    ${SOFATOPOLOGYMAPPING_SRC}/Triangle2EdgeTopologicalMapping.h
    #${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.h
    #${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.inl
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyAlgorithms.h
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyContainer.h
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyModifier.h
    ${SOFANONUNIFORMFEM_SRC}/MultilevelHexahedronSetTopologyContainer.h
    ${SOFANONUNIFORMFEM_SRC}/SparseGridMultipleTopology.h
    ${SOFANONUNIFORMFEM_SRC}/SparseGridRamificationTopology.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/init.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/CylinderGridTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/SphereGridTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/CenterPointTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Edge2QuadTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Hexa2QuadTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Hexa2TetraTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/IdentityTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Mesh2PointMechanicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Mesh2PointTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Quad2TriangleTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedHexaTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedTetraMechanicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/SimpleTesselatedTetraTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/SubsetTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Tetra2TriangleTopologicalMapping.cpp
    ${SOFATOPOLOGYMAPPING_SRC}/Triangle2EdgeTopologicalMapping.cpp
    # ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.cpp
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyContainer.cpp
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyModifier.cpp
    ${SOFANONUNIFORMFEM_SRC}/SparseGridMultipleTopology.cpp
    ${SOFANONUNIFORMFEM_SRC}/SparseGridRamificationTopology.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseTopology/config.h
    wrapper/SofaGeneralTopology/config.h
    wrapper/SofaTopologyMapping/config.h
    wrapper/SofaNonUniformFem/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/topology/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASETOPOLOGY)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFABASETOPOLOGY_DIR}/src")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAGENERALTOPOLOGY_DIR}/src")
target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFATOPOLOGYMAPPING_DIR}/src")
target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFANONUNIFORMFEM_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALTOPOLOGY)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFATOPOLOGYMAPPING)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFANONUNIFORMFEM)
