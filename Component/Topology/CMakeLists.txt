cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Topology LANGUAGES CXX)

set(SOFACOMPONENTTOPOLOGY_SOURCE_DIR "src/sofa/component/topology")

set(SOFACOMPONENTTOPOLOGY_DIRS StaticContainer Grid DynamicContainer Mapping)
set(SOFACOMPONENTTOPOLOGY_TARGETS)
foreach(topology_dir ${SOFACOMPONENTTOPOLOGY_DIRS})
	sofang_add_subdirectory_and_option(${topology_dir} ${PROJECT_NAME}.${topology_dir})
	list(APPEND SOFACOMPONENTTOPOLOGY_TARGETS ${PROJECT_NAME}.${topology_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTTOPOLOGY_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/topology/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTTOPOLOGY_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTTOPOLOGY)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
