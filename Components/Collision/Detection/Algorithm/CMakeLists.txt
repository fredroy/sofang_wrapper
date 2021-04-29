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

set(HEADER_FILES
	${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.h
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.h
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAP.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAPNarrowPhase.h
    ${SOFAGENERALMESHCOLLISION_SRC}/DSAPBox.h
    ${SOFAGENERALMESHCOLLISION_SRC}/IncrSAP.h
    ${SOFAUSERINTERACTION_SRC}/RayTraceDetection.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/init.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceDetection.cpp
    ${SOFABASECOLLISION_SRC}/BruteForceBroadPhase.cpp
    ${SOFABASECOLLISION_SRC}/DefaultPipeline.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAP.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DirectSAPNarrowPhase.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/DSAPBox.cpp
    ${SOFAGENERALMESHCOLLISION_SRC}/IncrSAP.cpp
    ${SOFAUSERINTERACTION_SRC}/RayTraceDetection.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseCollision/config.h
    wrapper/SofaGeneralMeshCollision/config.h
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/collision/detection/algorithm/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Components.Collision.Models) # Needs CubeModel

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASECOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALMESHCOLLISION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASECOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALMESHCOLLISION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)