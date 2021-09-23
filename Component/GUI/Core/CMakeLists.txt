cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.GUI.Core LANGUAGES CXX)

set(SOFACOMPONENTGUICORE_SOURCE_DIR "src/sofa/component/gui/core")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAGRAPHCOMPONENT_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGraphComponent/")
set(SOFAGRAPHCOMPONENT_SRC "${SOFAGRAPHCOMPONENT_DIR}/src/SofaGraphComponent/")
set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(SOFAGUICOMMON_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGuiCommon/")
set(SOFAGUICOMMON_SRC "${SOFAGUICOMMON_DIR}/src/sofa/gui")

set(SOFAGUI_DIR "${SOFA_SOURCE_DIR}/SofaGui/")
set(SOFAGUI_SRC "${SOFAGUI_DIR}/src/SofaGui")

set(HEADER_FILES
	${SOFACOMPONENTGUICORE_SOURCE_DIR}/config.h.in
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
    ${SOFAGUICOMMON_SRC}/BaseGUI.h
    ${SOFAGUICOMMON_SRC}/BaseViewer.h
    ${SOFAGUICOMMON_SRC}/BatchGUI.h
    ${SOFAGUICOMMON_SRC}/ColourPickingVisitor.h
    ${SOFAGUICOMMON_SRC}/FilesRecentlyOpenedManager.h
    ${SOFAGUICOMMON_SRC}/GuiDataRepository.h
    ${SOFAGUICOMMON_SRC}/GUIManager.h
    ${SOFAGUICOMMON_SRC}/MouseOperations.h
    ${SOFAGUICOMMON_SRC}/OperationFactory.h
    ${SOFAGUICOMMON_SRC}/PickHandler.h
    ${SOFAGUICOMMON_SRC}/ViewerFactory.h
    ${SOFAGUICOMMON_SRC}/ArgumentParser.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTGUICORE_SOURCE_DIR}/init.cpp
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
    ${SOFAGUICOMMON_SRC}/BaseGUI.cpp
    ${SOFAGUICOMMON_SRC}/BaseViewer.cpp
    ${SOFAGUICOMMON_SRC}/BatchGUI.cpp
    ${SOFAGUICOMMON_SRC}/ColourPickingVisitor.cpp
    ${SOFAGUICOMMON_SRC}/FilesRecentlyOpenedManager.cpp
    ${SOFAGUICOMMON_SRC}/GuiDataRepository.cpp
    ${SOFAGUICOMMON_SRC}/GUIManager.cpp
    ${SOFAGUICOMMON_SRC}/MouseOperations.cpp
    ${SOFAGUICOMMON_SRC}/PickHandler.cpp
    ${SOFAGUICOMMON_SRC}/ViewerFactory.cpp
    ${SOFAGUICOMMON_SRC}/ArgumentParser.cpp
    ${SOFAGUI_SRC}/initSofaGui.cpp
)

set(WRAPPER_FILES
    wrapper/SofaGraphComponent/config.h
    wrapper/SofaUserInteraction/config.h
    wrapper/sofa/gui/config.h
    wrapper/SofaGui/config.h
    wrapper/SofaGui/initSofaGui.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

include(FetchContent)
FetchContent_Declare(cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts
        GIT_TAG        v2.2.1
)

FetchContent_GetProperties(cxxopts)
if(NOT cxxopts_POPULATED)
    FetchContent_Populate(cxxopts)

    set(CXXOPTS_BUILD_EXAMPLES OFF CACHE INTERNAL "")
    set(CXXOPTS_BUILD_TESTS OFF CACHE INTERNAL "")
    set(CXXOPTS_ENABLE_INSTALL ON CACHE INTERNAL "")

    add_subdirectory(${cxxopts_SOURCE_DIR} ${cxxopts_BINARY_DIR})
endif()

configure_file(${SOFACOMPONENTGUICORE_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/gui/core/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCommon SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC cxxopts)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Collision.Response.Contact)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Collision.Models)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Visual)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.Constraint.Projective)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGRAPHCOMPONENT_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGUICOMMON_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGUICOMMON_DIR}/compat")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGRAPHCOMPONENT)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGUICOMMON)
