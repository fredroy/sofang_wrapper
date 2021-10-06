cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Constraint LANGUAGES CXX)

set(SOFACOMPONENTCONSTRAINT_SOURCE_DIR "src/sofa/component/constraint")

set(SOFACOMPONENTCONSTRAINT_DIRS Lagrangian Projective)
set(SOFACOMPONENTCONSTRAINT_TARGETS)
foreach(constraint_dir ${SOFACOMPONENTCONSTRAINT_DIRS})
	add_subdirectory(${constraint_dir})
	list(APPEND SOFACOMPONENTCONSTRAINT_TARGETS ${PROJECT_NAME}.${constraint_dir})
endforeach()


set(HEADER_FILES
    ${SOFACOMPONENTCONSTRAINT_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTCONSTRAINT_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTCONSTRAINT_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/constraint/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTCONSTRAINT_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCONSTRAINT)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
