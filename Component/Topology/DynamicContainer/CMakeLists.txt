cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology.DynamicContainer LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGYDYNAMICCONTAINER_SOURCE_DIR "src/sofa/component/topology/dynamiccontainer")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASETOPOLOGY_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseTopology/")
set(SOFABASETOPOLOGY_SRC "${SOFABASETOPOLOGY_DIR}/src/SofaBaseTopology")

set(SOFAGENERALTOPOLOGY_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralTopology/")
set(SOFAGENERALTOPOLOGY_SRC "${SOFAGENERALTOPOLOGY_DIR}/src/SofaGeneralTopology")
set(SOFANONUNIFORMFEM_DIR "${SOFAMODULES_SOURCE_DIR}/SofaNonUniformFem/")
set(SOFANONUNIFORMFEM_SRC "${SOFANONUNIFORMFEM_DIR}/src/SofaNonUniformFem")

set(HEADER_FILES
    ${SOFACOMPONENTTOPOLOGYDYNAMICCONTAINER_SOURCE_DIR}/config.h.in
    ${SOFABASETOPOLOGY_SRC}/fwd.h
    ${SOFABASETOPOLOGY_SRC}/CommonAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyModifier.h
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
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyModifier.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.inl
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyAlgorithms.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyContainer.h
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyModifier.h
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.h
    #${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.h
    #${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.inl
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyAlgorithms.h
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyContainer.h
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyModifier.h
    ${SOFANONUNIFORMFEM_SRC}/MultilevelHexahedronSetTopologyContainer.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGYDYNAMICCONTAINER_SOURCE_DIR}/init.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/EdgeSetTopologyModifier.cpp
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
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/TetrahedronSetTopologyModifier.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetGeometryAlgorithms.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyContainer.cpp
    ${SOFABASETOPOLOGY_SRC}/TriangleSetTopologyModifier.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.cpp
    # ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridGeometryAlgorithms.cpp
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyContainer.cpp
    ${SOFANONUNIFORMFEM_SRC}/DynamicSparseGridTopologyModifier.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseTopology/config.h
    wrapper/SofaGeneralTopology/config.h
    wrapper/SofaNonUniformFem/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTTOPOLOGYDYNAMICCONTAINER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/topology/dynamiccontainer/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASETOPOLOGY)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALTOPOLOGY)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFATOPOLOGYMAPPING)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFANONUNIFORMFEM)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASETOPOLOGY_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALTOPOLOGY_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFANONUNIFORMFEM_DIR}/src")
