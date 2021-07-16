cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.AnimationLoop LANGUAGES CXX)

set(SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR "src/sofa/components/animationloop")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAGENERALANIMATIONLOOP_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralAnimationLoop/")
set(SOFAGENERALANIMATIONLOOP_SRC "${SOFAGENERALANIMATIONLOOP_DIR}/src/SofaGeneralAnimationLoop")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/config.h.in
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.h
    ${SOFACONSTRAINT_SRC}/FreeMotionTask.h
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/initMinimal.cpp
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.cpp
    ${SOFACONSTRAINT_SRC}/FreeMotionTask.cpp
)

# Full set
set(HEADER_FILES
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.h
)

set(SOURCE_FILES
	${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/init.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.cpp
)

set(WRAPPER_FILES
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralAnimationLoop/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/animationloop/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.LinearSolver_minimal) # ConstraintSolverImpl needs FullMatrix
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Constraint.Lagrangian_minimal) # FreeMotionAL needs LCPConstraintSolver

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSANIMATIONLOOP)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAGENERALANIMATIONLOOP_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSANIMATIONLOOP)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALANIMATIONLOOP)
