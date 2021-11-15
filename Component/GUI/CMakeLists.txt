cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.GUI LANGUAGES CXX)

set(SOFACOMPONENTGUI_SOURCE_DIR "src/sofa/component/gui")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAGRAPHCOMPONENT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGraphComponent/")
set(SOFAGRAPHCOMPONENT_SRC "${SOFAGRAPHCOMPONENT_DIR}/src/SofaGraphComponent/")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(HEADER_FILES
	${SOFACOMPONENTGUI_SOURCE_DIR}/config.h.in
    ${SOFAGRAPHCOMPONENT_SRC}/AddFrameButtonSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/AddRecordedCameraButtonSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/AttachBodyButtonSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/FixPickedParticleButtonSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/InteractingBehaviorModel.h
    ${SOFAGRAPHCOMPONENT_SRC}/MouseButtonSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/PauseAnimation.h
    ${SOFAGRAPHCOMPONENT_SRC}/PauseAnimationOnEvent.h
    ${SOFAGRAPHCOMPONENT_SRC}/SofaDefaultPathSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/StatsSetting.h
    ${SOFAGRAPHCOMPONENT_SRC}/ViewerSetting.h
    ${SOFAUSERINTERACTION_SRC}/InteractionPerformer.h
    ${SOFAUSERINTERACTION_SRC}/MouseInteractor.h
    ${SOFAUSERINTERACTION_SRC}/MouseInteractor.inl
    ${SOFAUSERINTERACTION_SRC}/AddRecordedCameraPerformer.h
    ${SOFAUSERINTERACTION_SRC}/AttachBodyPerformer.h
    ${SOFAUSERINTERACTION_SRC}/AttachBodyPerformer.inl
    ${SOFAUSERINTERACTION_SRC}/ComponentMouseInteraction.h
    ${SOFAUSERINTERACTION_SRC}/ComponentMouseInteraction.inl
    ${SOFAUSERINTERACTION_SRC}/FixParticlePerformer.h
    ${SOFAUSERINTERACTION_SRC}/FixParticlePerformer.inl
    ${SOFAUSERINTERACTION_SRC}/InciseAlongPathPerformer.h
    ${SOFAUSERINTERACTION_SRC}/TopologicalChangeManager.h
    ${SOFAUSERINTERACTION_SRC}/RemovePrimitivePerformer.h
    ${SOFAUSERINTERACTION_SRC}/RemovePrimitivePerformer.inl
    ${SOFAUSERINTERACTION_SRC}/StartNavigationPerformer.h
    ${SOFAUSERINTERACTION_SRC}/SuturePointPerformer.h
    ${SOFAUSERINTERACTION_SRC}/SuturePointPerformer.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTGUI_SOURCE_DIR}/init.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/AddFrameButtonSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/AddRecordedCameraButtonSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/AttachBodyButtonSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/FixPickedParticleButtonSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/MouseButtonSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/PauseAnimation.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/PauseAnimationOnEvent.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/SofaDefaultPathSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/StatsSetting.cpp
    ${SOFAGRAPHCOMPONENT_SRC}/ViewerSetting.cpp
    ${SOFAUSERINTERACTION_SRC}/InteractionPerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/MouseInteractor.cpp
    ${SOFAUSERINTERACTION_SRC}/AddRecordedCameraPerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/AttachBodyPerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/ComponentMouseInteraction.cpp
    ${SOFAUSERINTERACTION_SRC}/FixParticlePerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/InciseAlongPathPerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/TopologicalChangeManager.cpp
    ${SOFAUSERINTERACTION_SRC}/RemovePrimitivePerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/StartNavigationPerformer.cpp
    ${SOFAUSERINTERACTION_SRC}/SuturePointPerformer.cpp
)

set(WRAPPER_FILES
    wrapper/SofaGraphComponent/config.h
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.Collision.Response.Contact)
sofang_check_dependencies(Sofa.Component.Collision.Models)
sofang_check_dependencies(Sofa.Component.Visual)
sofang_check_dependencies(Sofa.Component.Constraint.Projective)
sofang_check_dependencies(Sofa.Component.Topology.Mapping) # TopologyChangeManager needs Hexa2TetraMapping

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTGUI_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/gui/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Collision.Response.Contact)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Collision.Models)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Visual)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Constraint.Projective)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Topology.Mapping)


target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGRAPHCOMPONENT_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGRAPHCOMPONENT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
