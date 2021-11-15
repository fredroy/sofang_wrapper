cmake_minimum_required(VERSION 3.12)
project(Sofa.UI.Core LANGUAGES CXX)

set(SOFAUICORE_SOURCE_DIR "src/sofa/ui/core")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAGUICOMMON_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGuiCommon/")
set(SOFAGUICOMMON_SRC "${SOFAGUICOMMON_DIR}/src/sofa/gui")

set(SOFAGUI_DIR "${SOFA_SOURCE_DIR}/SofaGui/")
set(SOFAGUI_SRC "${SOFAGUI_DIR}/src/SofaGui")

set(HEADER_FILES
	${SOFAUICORE_SOURCE_DIR}/config.h.in
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
    ${SOFAUICORE_SOURCE_DIR}/init.cpp
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
    wrapper/sofa/gui/config.h
    wrapper/SofaGui/config.h
    wrapper/SofaGui/initSofaGui.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofang_check_dependencies(Sofa.Component.GUI)

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

configure_file(${SOFAUICORE_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/ui/core/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCommon SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC cxxopts)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.GUI)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGUICOMMON_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGUICOMMON_DIR}/compat")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGUICOMMON)
