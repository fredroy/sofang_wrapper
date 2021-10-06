cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Visual LANGUAGES CXX)

set(SOFACOMPONENTVISUAL_SOURCE_DIR "src/sofa/component/visual")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEVISUAL_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseVisual/")
set(SOFABASEVISUAL_SRC "${SOFABASEVISUAL_DIR}/src/SofaBaseVisual")

set(SOFAGENERALVISUAL_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralVisual/")
set(SOFAGENERALVISUAL_SRC "${SOFAGENERALVISUAL_DIR}/src/SofaGeneralVisual")

set(HEADER_FILES
    ${SOFACOMPONENTVISUAL_SOURCE_DIR}/config.h.in
    ${SOFABASEVISUAL_SRC}/BaseCamera.h
    ${SOFABASEVISUAL_SRC}/BackgroundSetting.h
    ${SOFABASEVISUAL_SRC}/Camera.h
    ${SOFABASEVISUAL_SRC}/InteractiveCamera.h
    ${SOFABASEVISUAL_SRC}/VisualModelImpl.h
    ${SOFABASEVISUAL_SRC}/VisualStyle.h
    ${SOFAGENERALVISUAL_SRC}/RecordedCamera.h
    ${SOFAGENERALVISUAL_SRC}/VisualTransform.h
    ${SOFAGENERALVISUAL_SRC}/Visual3DText.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTVISUAL_SOURCE_DIR}/init.cpp
    ${SOFABASEVISUAL_SRC}/BaseCamera.cpp
    ${SOFABASEVISUAL_SRC}/BackgroundSetting.cpp
    ${SOFABASEVISUAL_SRC}/Camera.cpp
    ${SOFABASEVISUAL_SRC}/InteractiveCamera.cpp
    ${SOFABASEVISUAL_SRC}/VisualModelImpl.cpp
    ${SOFABASEVISUAL_SRC}/VisualStyle.cpp
    ${SOFAGENERALVISUAL_SRC}/RecordedCamera.cpp
    ${SOFAGENERALVISUAL_SRC}/VisualTransform.cpp
    ${SOFAGENERALVISUAL_SRC}/Visual3DText.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseVisual/config.h
    wrapper/SofaGeneralVisual/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)
sofa_find_package(TinyXML REQUIRED) # BaseCamera

configure_file(${SOFACOMPONENTVISUAL_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/visual/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PRIVATE tinyxml)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Sofa.Component.Topology)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASEVISUAL)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALVISUAL)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASEVISUAL_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALVISUAL_DIR}/src")

# Subproject Visual.GL
sofa_find_package(Sofa.GL REQUIRED)
if(Sofa.GL_FOUND)
    add_subdirectory(GL)
endif()
