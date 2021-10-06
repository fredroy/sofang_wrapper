cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Response.Contact LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR "src/sofa/component/collision/response/contact")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")
set(SOFAMESHCOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaMeshCollision/")
set(SOFAMESHCOLLISION_SRC "${SOFAMESHCOLLISION_DIR}/src/SofaMeshCollision")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BaseContactMapper.h
    ${SOFAMESHCOLLISION_SRC}/BarycentricContactMapper.h
    ${SOFAMESHCOLLISION_SRC}/BarycentricContactMapper.inl
    ${SOFAMESHCOLLISION_SRC}/BarycentricPenalityContact.h
    ${SOFAMESHCOLLISION_SRC}/BarycentricPenalityContact.inl
    ${SOFABASECOLLISION_SRC}/DefaultContactManager.cpp
    ${SOFAMESHCOLLISION_SRC}/IdentityContactMapper.h
    ${SOFAMESHCOLLISION_SRC}/IdentityContactMapper.inl
    ${SOFAMESHCOLLISION_SRC}/RigidContactMapper.h
    ${SOFAMESHCOLLISION_SRC}/RigidContactMapper.inl
    ${SOFAMESHCOLLISION_SRC}/SubsetContactMapper.h
    ${SOFAMESHCOLLISION_SRC}/SubsetContactMapper.inl
    ${SOFACONSTRAINT_SRC}/ContactIdentifier.h
    ${SOFACONSTRAINT_SRC}/FrictionContact.h
    ${SOFACONSTRAINT_SRC}/FrictionContact.inl
    ${SOFACONSTRAINT_SRC}/StickContactConstraint.h
    ${SOFACONSTRAINT_SRC}/StickContactConstraint.inl
    ${SOFAUSERINTERACTION_SRC}/RayContact.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/BaseContactMapper.cpp
    ${SOFAMESHCOLLISION_SRC}/BarycentricContactMapper.cpp
    ${SOFAMESHCOLLISION_SRC}/BarycentricPenalityContact.cpp
    ${SOFABASECOLLISION_SRC}/DefaultContactManager.cpp
    ${SOFAMESHCOLLISION_SRC}/IdentityContactMapper.cpp
    ${SOFAMESHCOLLISION_SRC}/RigidContactMapper.cpp
    ${SOFAMESHCOLLISION_SRC}/SubsetContactMapper.cpp
    ${SOFACONSTRAINT_SRC}/ContactIdentifier.cpp
    ${SOFACONSTRAINT_SRC}/FrictionContact.cpp
    ${SOFACONSTRAINT_SRC}/StickContactConstraint.cpp
    ${SOFAUSERINTERACTION_SRC}/RayContact.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaMeshCollision/config.h
    wrapper/SofaConstraint/config.h
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/collision/response/contact/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Mapping)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Container) # BarycentricMapper needs MechanicalObject
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.PhysicalModel.SolidMechanics.Elasticity.Springs) # BarycentricPenalityContact
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Constraint.Lagrangian) # FrictionContact needs UnilateralCC
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Collision.Models)

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONRESPONSECONTACT)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMESHCOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAMESHCOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
