cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology.Grid LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGYGRID_SOURCE_DIR "src/sofa/component/topology/grid")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASETOPOLOGY_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseTopology/")
set(SOFABASETOPOLOGY_SRC "${SOFABASETOPOLOGY_DIR}/src/SofaBaseTopology")

set(SOFAGENERALTOPOLOGY_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralTopology/")
set(SOFAGENERALTOPOLOGY_SRC "${SOFAGENERALTOPOLOGY_DIR}/src/SofaGeneralTopology")
set(SOFANONUNIFORMFEM_DIR "${SOFAMODULES_SOURCE_DIR}/SofaNonUniformFem/")
set(SOFANONUNIFORMFEM_SRC "${SOFANONUNIFORMFEM_DIR}/src/SofaNonUniformFem")

set(HEADER_FILES
    ${SOFACOMPONENTTOPOLOGYGRID_SOURCE_DIR}/config.h.in
    ${SOFABASETOPOLOGY_SRC}/fwd.h
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/polygon_cube_intersection.h
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/vec.h
    ${SOFABASETOPOLOGY_SRC}/GridTopology.h
    ${SOFABASETOPOLOGY_SRC}/RegularGridTopology.h
    ${SOFABASETOPOLOGY_SRC}/SparseGridTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/CylinderGridTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/SphereGridTopology.h
    ${SOFANONUNIFORMFEM_SRC}/SparseGridMultipleTopology.h
    ${SOFANONUNIFORMFEM_SRC}/SparseGridRamificationTopology.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGYGRID_SOURCE_DIR}/init.cpp
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/fast_polygon_cube_intersection.cpp
    ${SOFABASETOPOLOGY_SRC}/polygon_cube_intersection/polygon_cube_intersection.cpp
    ${SOFABASETOPOLOGY_SRC}/GridTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/RegularGridTopology.cpp
    ${SOFABASETOPOLOGY_SRC}/SparseGridTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/CylinderGridTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/SphereGridTopology.cpp
    ${SOFANONUNIFORMFEM_SRC}/SparseGridMultipleTopology.cpp
    ${SOFANONUNIFORMFEM_SRC}/SparseGridRamificationTopology.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseTopology/config.h
    wrapper/SofaGeneralTopology/config.h
    wrapper/SofaNonUniformFem/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Topology.StaticContainer)

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTTOPOLOGYGRID_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/topology/grid/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology.StaticContainer)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASETOPOLOGY)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALTOPOLOGY)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFANONUNIFORMFEM)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASETOPOLOGY_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALTOPOLOGY_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFANONUNIFORMFEM_DIR}/src")
