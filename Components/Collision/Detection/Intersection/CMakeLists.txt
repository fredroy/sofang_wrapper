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
set(SOFAMISCCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscCollision/")
set(SOFAMISCCOLLISION_SRC "${SOFAMISCCOLLISION_DIR}/src/SofaMiscCollision")

set(HEADER_FILES
	${SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.h
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.inl
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.h
    ${SOFACONSTRAINT_SRC}/LMDNewProximityIntersection.h
    ${SOFACONSTRAINT_SRC}/LMDNewProximityIntersection.inl
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.h
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshDiscreteIntersection.inl
    ${SOFAGENERALMESHCOLLISION_SRC}/MeshMinProximityIntersection.h
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
    wrapper/SofaMeshCollision/config.h
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
    wrapper/SofaMiscCollision/config.h
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
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAMISCCOLLISION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAMISCCOLLISION)
