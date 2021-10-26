cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology.StaticContainer LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGYSTATICCONTAINER_SOURCE_DIR "src/sofa/component/topology/staticcontainer")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASETOPOLOGY_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseTopology/")
set(SOFABASETOPOLOGY_SRC "${SOFABASETOPOLOGY_DIR}/src/SofaBaseTopology")

set(SOFAGENERALTOPOLOGY_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralTopology/")
set(SOFAGENERALTOPOLOGY_SRC "${SOFAGENERALTOPOLOGY_DIR}/src/SofaGeneralTopology")

set(HEADER_FILES
    ${SOFACOMPONENTTOPOLOGYSTATICCONTAINER_SOURCE_DIR}/config.h.in
    ${SOFABASETOPOLOGY_SRC}/fwd.h
    ${SOFABASETOPOLOGY_SRC}/MeshTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.h
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGYSTATICCONTAINER_SOURCE_DIR}/init.cpp
    ${SOFABASETOPOLOGY_SRC}/MeshTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/CubeTopology.cpp
    ${SOFAGENERALTOPOLOGY_SRC}/SphereQuadTopology.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseTopology/config.h
    wrapper/SofaGeneralTopology/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTTOPOLOGYSTATICCONTAINER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/topology/staticcontainer/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASETOPOLOGY)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALTOPOLOGY)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASETOPOLOGY_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALTOPOLOGY_DIR}/src")
