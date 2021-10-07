cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Detection.Algorithm LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_SOURCE_DIR "src/sofa/component/collision/detection/algorithm")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")

set(SOFAGENERALMESHCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralMeshCollision/")
set(SOFAGENERALMESHCOLLISION_SRC "${SOFAGENERALMESHCOLLISION_DIR}/src/SofaGeneralMeshCollision")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.h
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.h
    ${SOFABASECOLLISION_SRC}/BVHNarrowPhase.h
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAP.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAPNarrowPhase.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DSAPBox.h
    ${SOFAGENERALMESHCOLLISION_SRC}/IncrSAP.h
    ${SOFAGENERALMESHCOLLISION_SRC}/RayTraceNarrowPhase.h
    ${SOFAUSERINTERACTION_SRC}/RayTraceDetection.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.cpp
    ${SOFABASECOLLISION_SRC}/BVHNarrowPhase.cpp
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAP.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAPNarrowPhase.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DSAPBox.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/IncrSAP.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/RayTraceNarrowPhase.cpp
    ${SOFAUSERINTERACTION_SRC}/RayTraceDetection.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Collision.Models) # BruteForceBroadPhase Needs CubeModel, RayTraceNarrowPhase Needs TriangleOctreeModel

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/collision/detection/algorithm/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Collision.Models)

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONDETECTIONALGORITHM)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
