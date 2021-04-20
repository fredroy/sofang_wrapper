cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.AnimationLoop LANGUAGES CXX)

set(SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR "src/sofa/components/animationloop")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAGENERALANIMATIONLOOP_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralAnimationLoop/")
set(SOFAGENERALANIMATIONLOOP_SRC "${SOFAGENERALANIMATIONLOOP_DIR}/src/SofaGeneralAnimationLoop")

set(HEADER_FILES
	${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/config.h.in
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.h
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.h
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.h
)

set(SOURCE_FILES
	${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/init.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintAnimationLoop.cpp
    ${SOFACONSTRAINT_SRC}/FreeMotionAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiStepAnimationLoop.cpp
    ${SOFAGENERALANIMATIONLOOP_SRC}/MultiTagAnimationLoop.cpp
)

set(WRAPPER_FILES
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralAnimationLoop/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.LinearSolver)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Constraint.Lagrangian)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

configure_file(${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/animationloop/config.h)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALANIMATIONLOOP_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALANIMATIONLOOP)
