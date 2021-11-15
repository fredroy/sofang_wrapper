cmake_minimum_required(VERSION 3.12)
project(Sofa.Component LANGUAGES CXX)

set(SOFACOMPONENT_SOURCE_DIR "src/sofa/component")

set(SOFACOMPONENT_DIRS Utils ODESolver LinearSolver Topology PhysicalModel Constraint AnimationLoop Mapping Container Collision Engine Visual IO UI Controller) # Device
set(SOFACOMPONENT_TARGETS)
foreach(component_dir ${SOFACOMPONENT_DIRS})
	sofang_add_subdirectory_and_option(${component_dir} ${PROJECT_NAME}.${component_dir})
	list(APPEND SOFACOMPONENT_TARGETS ${PROJECT_NAME}.${component_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENT_SOURCE_DIR}/config.h.in
    ${SOFACOMPONENT_SOURCE_DIR}/init.h
)

set(SOURCE_FILES
    ${SOFACOMPONENT_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENT_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENT_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENT)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
