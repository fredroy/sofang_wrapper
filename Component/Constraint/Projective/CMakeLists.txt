cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Constraint.Projective LANGUAGES CXX)

set(SOFACOMPONENTCONSTRAINTPROJECTIVE_SOURCE_DIR "src/sofa/component/constraint/projective")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABOUNDARYCONDITION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaBoundaryCondition/")
set(SOFABOUNDARYCONDITION_SRC "${SOFABOUNDARYCONDITION_DIR}/src/SofaBoundaryCondition")
set(SOFAGENERALOBJECTINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralObjectInteraction/")
set(SOFAGENERALOBJECTINTERACTION_SRC "${SOFAGENERALOBJECTINTERACTION_DIR}/src/SofaGeneralObjectInteraction")

set(HEADER_FILES
    ${SOFACOMPONENTCONSTRAINTPROJECTIVE_SOURCE_DIR}/config.h.in
    ${SOFABOUNDARYCONDITION_SRC}/FixedConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/FixedConstraint.inl
    ${SOFAGENERALOBJECTINTERACTION_SRC}/AttachConstraint.h
    ${SOFAGENERALOBJECTINTERACTION_SRC}/AttachConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/AffineMovementConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/AffineMovementConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/FixedPlaneConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/FixedPlaneConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/FixedRotationConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/FixedRotationConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/FixedTranslationConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/FixedTranslationConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/HermiteSplineConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/HermiteSplineConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/LinearMovementConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/LinearMovementConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/LinearVelocityConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/LinearVelocityConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/OscillatorConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/OscillatorConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/ParabolicConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/ParabolicConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/PartialFixedConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/PartialFixedConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/PartialLinearMovementConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/PartialLinearMovementConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/PatchTestMovementConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/PatchTestMovementConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/PointConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/PointConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/PositionBasedDynamicsConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/PositionBasedDynamicsConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/SkeletalMotionConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/SkeletalMotionConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToLineConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToLineConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPlaneConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPlaneConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPointConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPointConstraint.inl
    ${SOFABOUNDARYCONDITION_SRC}/ProjectDirectionConstraint.h
    ${SOFABOUNDARYCONDITION_SRC}/ProjectDirectionConstraint.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTCONSTRAINTPROJECTIVE_SOURCE_DIR}/init.cpp
    ${SOFABOUNDARYCONDITION_SRC}/FixedConstraint.cpp
    ${SOFAGENERALOBJECTINTERACTION_SRC}/AttachConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/AffineMovementConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/FixedPlaneConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/FixedRotationConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/FixedTranslationConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/HermiteSplineConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/LinearMovementConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/LinearVelocityConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/OscillatorConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/ParabolicConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/PartialFixedConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/PartialLinearMovementConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/PatchTestMovementConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/PointConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/PositionBasedDynamicsConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/SkeletalMotionConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToLineConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPlaneConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/ProjectToPointConstraint.cpp
    ${SOFABOUNDARYCONDITION_SRC}/ProjectDirectionConstraint.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBoundaryCondition/config.h
    wrapper/SofaGeneralObjectInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCONSTRAINTPROJECTIVE_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/constraint/projective/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.LinearSolver)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABOUNDARYCONDITION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALOBJECTINTERACTION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABOUNDARYCONDITION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALOBJECTINTERACTION_DIR}/src")
