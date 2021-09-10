cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Constraint.Lagrangian LANGUAGES CXX)

set(SOFACOMPONENTSCONSTRAINTLAGRANGIAN_SOURCE_DIR "src/sofa/components/constraint/lagrangian")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTSCONSTRAINTLAGRANGIAN_SOURCE_DIR}/config.h.in
    ${SOFACONSTRAINT_SRC}/BilateralConstraintResolution.h
    ${SOFACONSTRAINT_SRC}/BilateralInteractionConstraint.h
    ${SOFACONSTRAINT_SRC}/BilateralInteractionConstraint.inl
    ${SOFACONSTRAINT_SRC}/ConstraintSolverImpl.h
    ${SOFACONSTRAINT_SRC}/ConstraintStoreLambdaVisitor.h
    ${SOFACONSTRAINT_SRC}/GenericConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/GenericConstraintSolver.h
    ${SOFACONSTRAINT_SRC}/LCPConstraintSolver.h
    ${SOFACONSTRAINT_SRC}/LinearSolverConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/LinearSolverConstraintCorrection.inl
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.inl
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.h
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.inl
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTSCONSTRAINTLAGRANGIAN_SOURCE_DIR}/initMinimal.cpp
    ${SOFACONSTRAINT_SRC}/BilateralInteractionConstraint.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintSolverImpl.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintStoreLambdaVisitor.cpp
    ${SOFACONSTRAINT_SRC}/GenericConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/GenericConstraintSolver.cpp
    ${SOFACONSTRAINT_SRC}/LCPConstraintSolver.cpp
    ${SOFACONSTRAINT_SRC}/LinearSolverConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.cpp
)

# Full set
set(HEADER_FILES
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.inl
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.h
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.inl
    ${SOFACONSTRAINT_SRC}/StopperConstraint.h
    ${SOFACONSTRAINT_SRC}/StopperConstraint.inl
    ${SOFACONSTRAINT_SRC}/UniformConstraint.h
    ${SOFACONSTRAINT_SRC}/UniformConstraint.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTSCONSTRAINTLAGRANGIAN_SOURCE_DIR}/init.cpp
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.cpp
    ${SOFACONSTRAINT_SRC}/StopperConstraint.cpp
    ${SOFACONSTRAINT_SRC}/UniformConstraint.cpp
)

set(WRAPPER_FILES
    wrapper/SofaConstraint/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCONSTRAINTLAGRANGIAN_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/constraint/lagrangian/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Topology_minimal)
# target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.LinearSolver_minimal)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.PhysicalModel.Mass) # Uncoupled needs UniformMass

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.LinearSolver)
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.ODESolver) # PrecompuptedCC needs EulerImplicit
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.Topology)
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.PhysicalModel.SolidMechanics.Elasticity.FEM) # PrecompuptedCC needs TetraFEM

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
