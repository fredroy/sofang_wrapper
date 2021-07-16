cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Collision.Detection.Algorithm LANGUAGES CXX)

set(SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR "src/sofa/components/collision/detection/algorithm")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASECOLLISION_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseCollision/")
set(SOFABASECOLLISION_SRC "${SOFABASECOLLISION_DIR}/src/SofaBaseCollision")

set(SOFAGENERALMESHCOLLISION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralMeshCollision/")
set(SOFAGENERALMESHCOLLISION_SRC "${SOFAGENERALMESHCOLLISION_DIR}/src/SofaGeneralMeshCollision")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.h
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.h
    ${SOFABASECOLLISION_SRC}/BVHNarrowPhase.h
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.h
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/initMinimal.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.cpp
    ${SOFABASECOLLISION_SRC}/BVHNarrowPhase.cpp
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.cpp
)

# Full set
set(HEADER_FILES
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAP.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAPNarrowPhase.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DSAPBox.h
    ${SOFAGENERALMESHCOLLISION_SRC}/IncrSAP.h
    ${SOFAGENERALMESHCOLLISION_SRC}/RayTraceNarrowPhase.h
    ${SOFAUSERINTERACTION_SRC}/RayTraceDetection.h
)

set(SOURCE_FILES
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

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/collision/detection/algorithm/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Components.Collision.Models_minimal) # BruteForceBroadPhase Needs CubeModel

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC Sofa.Components.Collision.Models) # RayTraceNarrowPhase Needs TriangleOctreeModel

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
