cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.AnimationLoop LANGUAGES CXX)

set(SOFACOMPONENTANIMATIONLOOP_SOURCE_DIR "src/sofa/component/animationloop")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAGENERALANIMATIONLOOP_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralAnimationLoop/")
set(SOFAGENERALANIMATIONLOOP_SRC "${SOFAGENERALANIMATIONLOOP_DIR}/src/SofaGeneralAnimationLoop")

set(HEADER_FILES
    ${SOFACOMPONENTANIMATIONLOOP_SOURCE_DIR}/config.h.in
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.h
    ${SOFACONSTRAINT_SRC}/FreeMotionTask.h
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTANIMATIONLOOP_SOURCE_DIR}/init.cpp
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.cpp
    ${SOFACONSTRAINT_SRC}/FreeMotionTask.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.cpp
)

set(WRAPPER_FILES
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralAnimationLoop/config.h
)

source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Constraint.Lagrangian) # FreeMotionAL needs LCPConstraintSolver

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTANIMATIONLOOP_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/animationloop/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Constraint.Lagrangian) 

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTANIMATIONLOOP)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALANIMATIONLOOP)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALANIMATIONLOOP_DIR}/src")
