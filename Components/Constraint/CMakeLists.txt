cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Constraint LANGUAGES CXX)

set(SOFACOMPONENTSCONSTRAINT_SOURCE_DIR "src/sofa/components/constraint")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFACONSTRAINT_DIR "${SOFA_SOURCE_DIR}/modules/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")

set(HEADER_FILES
	${SOFACOMPONENTSCONSTRAINT_SOURCE_DIR}/config.h.in
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
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.inl
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.h
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.inl
    ${SOFACONSTRAINT_SRC}/StopperConstraint.h
    ${SOFACONSTRAINT_SRC}/StopperConstraint.inl
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.h
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.inl
    ${SOFACONSTRAINT_SRC}/UniformConstraint.h
    ${SOFACONSTRAINT_SRC}/UniformConstraint.inl
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.h
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTSCONSTRAINT_SOURCE_DIR}/init.cpp
    ${SOFACONSTRAINT_SRC}/BilateralInteractionConstraint.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintSolverImpl.cpp
    ${SOFACONSTRAINT_SRC}/ConstraintStoreLambdaVisitor.cpp
    ${SOFACONSTRAINT_SRC}/GenericConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/GenericConstraintSolver.cpp
    ${SOFACONSTRAINT_SRC}/LCPConstraintSolver.cpp
    ${SOFACONSTRAINT_SRC}/LinearSolverConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/PrecomputedConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/SlidingConstraint.cpp
    ${SOFACONSTRAINT_SRC}/StopperConstraint.cpp
    ${SOFACONSTRAINT_SRC}/UncoupledConstraintCorrection.cpp
    ${SOFACONSTRAINT_SRC}/UniformConstraint.cpp
    ${SOFACONSTRAINT_SRC}/UnilateralInteractionConstraint.cpp
)

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCONSTRAINT_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/constraint/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.LinearSolver)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.ODESolver)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Topology)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.PhysicalModel.SolidMechanics.Elasticity.FEM)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.PhysicalModel.Mass)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
