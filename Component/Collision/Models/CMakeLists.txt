cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Models LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONMODELS_SOURCE_DIR "src/sofa/component/collision/models")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")
set(SOFAMESHCOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaMeshCollision/")
set(SOFAMESHCOLLISION_SRC "${SOFAMESHCOLLISION_DIR}/src/SofaMeshCollision")

set(SOFAGENERALMESHCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralMeshCollision/")
set(SOFAGENERALMESHCOLLISION_SRC "${SOFAGENERALMESHCOLLISION_DIR}/src/SofaGeneralMeshCollision")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")
set(SOFAMISCCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscCollision/")
set(SOFAMISCCOLLISION_SRC "${SOFAMISCCOLLISION_DIR}/src/SofaMiscCollision")

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONMODELS_SOURCE_DIR}/config.h.in    
    ${SOFABASECOLLISION_SRC}/Cube.h
    ${SOFABASECOLLISION_SRC}/CubeModel.h
    ${SOFABASECOLLISION_SRC}/Sphere.h
    ${SOFABASECOLLISION_SRC}/SphereModel.h
    ${SOFABASECOLLISION_SRC}/SphereModel.inl
    ${SOFAMESHCOLLISION_SRC}/Line.h
    ${SOFAMESHCOLLISION_SRC}/LineModel.h
    ${SOFAMESHCOLLISION_SRC}/LineModel.inl
    ${SOFAMESHCOLLISION_SRC}/Point.h
    ${SOFAMESHCOLLISION_SRC}/PointModel.h
    ${SOFAMESHCOLLISION_SRC}/PointModel.inl
    ${SOFAMESHCOLLISION_SRC}/Triangle.h
    ${SOFAMESHCOLLISION_SRC}/TriangleModel.h
    ${SOFAMESHCOLLISION_SRC}/TriangleModel.inl
    ${SOFAUSERINTERACTION_SRC}/RayModel.h
    ${SOFABASECOLLISION_SRC}/CylinderModel.h
    ${SOFABASECOLLISION_SRC}/CylinderModel.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISIONMODELS_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/CubeModel.cpp
    ${SOFABASECOLLISION_SRC}/SphereModel.cpp
    ${SOFAMESHCOLLISION_SRC}/LineModel.cpp
    ${SOFAMESHCOLLISION_SRC}/PointModel.cpp
    ${SOFAMESHCOLLISION_SRC}/TriangleModel.cpp
    ${SOFAUSERINTERACTION_SRC}/RayModel.cpp
    ${SOFABASECOLLISION_SRC}/CylinderModel.cpp
    ${SOFAMESHCOLLISION_SRC}/RayTriangleIntersection.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/TriangleOctree.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/TriangleOctreeModel.cpp
    ${SOFAMISCCOLLISION_SRC}/CapsuleModel.cpp
    ${SOFAMISCCOLLISION_SRC}/OBBModel.cpp
    ${SOFAMISCCOLLISION_SRC}/RigidCapsuleModel.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaMeshCollision/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
    wrapper/SofaMiscCollision/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Topology)
sofang_check_dependencies(Sofa.Component.Mapping) # for LocalMinDistanceFilter

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCOLLISIONMODELS_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/collision/models/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Mapping) # for LocalMinDistanceFilter

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONMODELS)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMESHCOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMISCCOLLISION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAMESHCOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAMISCCOLLISION_DIR}/src")
