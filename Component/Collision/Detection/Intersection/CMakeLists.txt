cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Detection.Intersection LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR "src/sofa/component/collision/detection/intersection")

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

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.h
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.h
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.inl
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.h
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
    ${SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/BaseProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/DiscreteIntersection.cpp
    ${SOFABASECOLLISION_SRC}/MinProximityIntersection.cpp
    ${SOFABASECOLLISION_SRC}/NewProximityIntersection.cpp
    ${SOFACONSTRAINT_SRC}/LocalMinDistance.cpp
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
    wrapper/SofaConstraint/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
    wrapper/SofaMiscCollision/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/collision/detection/intersection/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Collision.Models)

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFACONSTRAINT)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMISCCOLLISION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFACONSTRAINT_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAMISCCOLLISION_DIR}/src")
