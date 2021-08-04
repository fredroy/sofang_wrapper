cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Collision.Detection.Intersection LANGUAGES CXX)

set(SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR "src/sofa/components/collision/detection/intersection")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAGENERALMESHCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralMeshCollision/")
set(SOFAGENERALMESHCOLLISION_SRC "${SOFAGENERALMESHCOLLISION_DIR}/src/SofaGeneralMeshCollision")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")
set(SOFAMISCCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscCollision/")
set(SOFAMISCCOLLISION_SRC "${SOFAMISCCOLLISION_DIR}/src/SofaMiscCollision")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.h
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.inl
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.h
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.h
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.inl
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshMinProximityIntersection.h
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/initMinimal.cpp
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.cpp
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.cpp
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshMinProximityIntersection.cpp
)

# Full set
set(HEADER_FILES
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.h
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.inl
    ${SOFAUSERINTERACTION_SRC}/RayNewProximityIntersection.h
    ${SOFAMISCCOLLISION_SRC}/BaseIntTool.h
    ${SOFAMISCCOLLISION_SRC}/CapsuleIntTool.h
    ${SOFAMISCCOLLISION_SRC}/CapsuleIntTool.inl
    ${SOFAMISCCOLLISION_SRC}/IntrCapsuleOBB.h
    ${SOFAMISCCOLLISION_SRC}/IntrCapsuleOBB.inl
    ${SOFAMISCCOLLISION_SRC}/IntrOBBOBB.h
    ${SOFAMISCCOLLISION_SRC}/IntrOBBOBB.inl
    ${SOFAMISCCOLLISION_SRC}/IntrSphereOBB.h
    ${SOFAMISCCOLLISION_SRC}/IntrSphereOBB.inl
    ${SOFAMISCCOLLISION_SRC}/IntrUtility3.h
    ${SOFAMISCCOLLISION_SRC}/IntrUtility3.inl
    ${SOFAMISCCOLLISION_SRC}/OBBIntTool.h
    ${SOFAMISCCOLLISION_SRC}/OBBModel.h
    ${SOFAMISCCOLLISION_SRC}/OBBModel.inl
    ${SOFAMISCCOLLISION_SRC}/IntrMeshUtility.h
    ${SOFAMISCCOLLISION_SRC}/IntrMeshUtility.inl
    ${SOFAMISCCOLLISION_SRC}/IntrTriangleOBB.h
    ${SOFAMISCCOLLISION_SRC}/IntrTriangleOBB.inl
    ${SOFAMISCCOLLISION_SRC}/MeshIntTool.h
    ${SOFAMISCCOLLISION_SRC}/MeshIntTool.inl

)

set(SOURCE_FILES
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.cpp
    ${SOFAUSERINTERACTION_SRC}/RayNewProximityIntersection.cpp
    ${SOFAMISCCOLLISION_SRC}/BaseIntTool.cpp
    ${SOFAMISCCOLLISION_SRC}/CapsuleIntTool.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrCapsuleOBB.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrOBBOBB.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrSphereOBB.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrUtility3.cpp
    ${SOFAMISCCOLLISION_SRC}/OBBIntTool.cpp
    ${SOFAMISCCOLLISION_SRC}/OBBModel.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrMeshUtility.cpp
    ${SOFAMISCCOLLISION_SRC}/IntrTriangleOBB.cpp
    ${SOFAMISCCOLLISION_SRC}/MeshIntTool.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
    wrapper/SofaMiscCollision/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/collision/detection/intersection/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Topology_minimal)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Collision.Models_minimal)

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Collision.Models)

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAMISCCOLLISION_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMISCCOLLISION)
