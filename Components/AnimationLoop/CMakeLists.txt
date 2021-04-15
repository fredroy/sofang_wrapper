cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.AnimationLoop LANGUAGES CXX)

set(SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR "src/sofa/components/animationloop")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFA_SOURCE_DIR}/modules/SofaConstraint/")
set(SOFACONSTRAINT_SOURCE_DIR "${SOFACONSTRAINT_DIR}/src/SofaConstraint")

set(HEADER_FILES
	${SOFACOMPONENTSANIMATIONLOOP_SOURCE_DIR}/config.h
    ${SOFACONSTRAINT_SOURCE_DIR}/ConstraintAnimationLoop.h
    ${SOFACONSTRAINT_SOURCE_DIR}/FreeMotionAnimationLoop.h
)

set(SOURCE_FILES
    ${SOFACONSTRAINT_SOURCE_DIR}/ConstraintAnimationLoop.cpp
    ${SOFACONSTRAINT_SOURCE_DIR}/FreeMotionAnimationLoop.cpp
)

sofa_find_package(SofaFramework REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
