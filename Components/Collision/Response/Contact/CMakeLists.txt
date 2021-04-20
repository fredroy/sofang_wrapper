cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Collision.Response.Contact LANGUAGES CXX)

set(SOFACOMPONENTSCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR "src/sofa/components/collision/response/contact")

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
	${SOFACOMPONENTSCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/config.h.in
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
    ${SOFACOMPONENTSCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/init.cpp
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

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCOLLISIONDETECTIONRESPONSECONTACT_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/collision/response/contact/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Mapping)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.PhysicalModel.SolidMechanics.Elasticity.Springs) # BarycentricPenalityContact
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Container)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Collision.Models)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Constraint.Lagrangian)


target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMESHCOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)