cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Collision.Detection.Intersection LANGUAGES CXX)

set(SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR "src/sofa/components/collision/detection/intersection")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")
set(SOFAMESHCOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaMeshCollision/")
set(SOFAMESHCOLLISION_SRC "${SOFAMESHCOLLISION_DIR}/src/SofaMeshCollision")

set(SOFACONSTRAINT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaConstraint/")
set(SOFACONSTRAINT_SRC "${SOFACONSTRAINT_DIR}/src/SofaConstraint")
set(SOFAGENERALMESHCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralMeshCollision/")
set(SOFAGENERALMESHCOLLISION_SRC "${SOFAGENERALMESHCOLLISION_DIR}/src/SofaGeneralMeshCollision")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(HEADER_FILES
	${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.h
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.inl
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.h
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.inl
    ${SOFACONSTRAINT_SRC}/LMDNewProximityIntersection.h
    ${SOFACONSTRAINT_SRC}/LMDNewProximityIntersection.inl
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.h
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.inl
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshMinProximityIntersection.h
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.h
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.inl
    ${SOFAUSERINTERACTION_SRC}/RayNewProximityIntersection.h
### OBB things to remove
    ${SOFABASECOLLISION_SRC}/BaseIntTool.h
    ${SOFABASECOLLISION_SRC}/CapsuleIntTool.h
    ${SOFABASECOLLISION_SRC}/CapsuleIntTool.inl
    ${SOFABASECOLLISION_SRC}/IntrCapsuleOBB.h
    ${SOFABASECOLLISION_SRC}/IntrCapsuleOBB.inl
    ${SOFABASECOLLISION_SRC}/IntrOBBOBB.h
    ${SOFABASECOLLISION_SRC}/IntrOBBOBB.inl
    ${SOFABASECOLLISION_SRC}/IntrSphereOBB.h
    ${SOFABASECOLLISION_SRC}/IntrSphereOBB.inl
    ${SOFABASECOLLISION_SRC}/IntrUtility3.h
    ${SOFABASECOLLISION_SRC}/IntrUtility3.inl
    ${SOFABASECOLLISION_SRC}/OBBIntTool.h
    ${SOFABASECOLLISION_SRC}/OBBModel.h
    ${SOFABASECOLLISION_SRC}/OBBModel.inl
    ${SOFAMESHCOLLISION_SRC}/IntrMeshUtility.h
    ${SOFAMESHCOLLISION_SRC}/IntrMeshUtility.inl
    ${SOFAMESHCOLLISION_SRC}/IntrTriangleOBB.h
    ${SOFAMESHCOLLISION_SRC}/IntrTriangleOBB.inl
    ${SOFAMESHCOLLISION_SRC}/MeshIntTool.h
    ${SOFAMESHCOLLISION_SRC}/MeshIntTool.inl
### OBB things to remove

)

set(SOURCE_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.cpp
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.cpp
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.cpp
    ${SOFACONSTRAINT_SRC}/LMDNewProximityIntersection.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshMinProximityIntersection.cpp
    ${SOFAUSERINTERACTION_SRC}/RayDiscreteIntersection.cpp
    ${SOFAUSERINTERACTION_SRC}/RayNewProximityIntersection.cpp
### OBB things to remove
    ${SOFABASECOLLISION_SRC}/BaseIntTool.cpp
    ${SOFABASECOLLISION_SRC}/CapsuleIntTool.cpp
    ${SOFABASECOLLISION_SRC}/IntrCapsuleOBB.cpp
    ${SOFABASECOLLISION_SRC}/IntrOBBOBB.cpp
    ${SOFABASECOLLISION_SRC}/IntrSphereOBB.cpp
    ${SOFABASECOLLISION_SRC}/IntrUtility3.cpp
    ${SOFABASECOLLISION_SRC}/OBBIntTool.cpp
    ${SOFABASECOLLISION_SRC}/OBBModel.cpp
    ${SOFAMESHCOLLISION_SRC}/IntrMeshUtility.cpp
    ${SOFAMESHCOLLISION_SRC}/IntrTriangleOBB.cpp
    ${SOFAMESHCOLLISION_SRC}/MeshIntTool.cpp
### OBB things to remove
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaMeshCollision/config.h
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/collision/detection/intersection/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Topology)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Collision.Models)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMESHCOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
