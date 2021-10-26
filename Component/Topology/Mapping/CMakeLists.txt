cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology.Mapping LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGYMAPPING_SOURCE_DIR "src/sofa/component/topology/mapping")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFATOPOLOGYMAPPING_DIR "${SOFAMODULES_SOURCE_DIR}/SofaTopologyMapping/")
set(SOFATOPOLOGYMAPPING_SRC "${SOFATOPOLOGYMAPPING_DIR}/src/SofaTopologyMapping")

set(HEADER_FILES
    ${SOFACOMPONENTTOPOLOGYMAPPING_SOURCE_DIR}/config.h.in
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
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGYMAPPING_SOURCE_DIR}/init.cpp
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
)

set(WRAPPER_FILES
    wrapper/SofaTopologyMapping/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Topology.Grid)
sofang_check_dependencies(Sofa.Component.Topology.DynamicContainer)

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTTOPOLOGYMAPPING_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/topology/mapping/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology.Grid)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology.DynamicContainer)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFATOPOLOGYMAPPING)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFATOPOLOGYMAPPING_DIR}/src")