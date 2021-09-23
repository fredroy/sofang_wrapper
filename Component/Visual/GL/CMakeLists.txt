cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Visual.GL LANGUAGES CXX)

set(SOFACOMPONENTVISUAL_SOURCE_DIR "src/sofa/component/visual/gl")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAOPENGLVISUAL_DIR "${SOFAMODULES_SOURCE_DIR}/SofaOpenglVisual/")
set(SOFAOPENGLVISUAL_SRC "${SOFAOPENGLVISUAL_DIR}/src/SofaOpenglVisual")
set(SOFAGENERALENGINE_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralEngine/")
set(SOFAGENERALENGINE_SRC "${SOFAGENERALENGINE_DIR}/src/SofaGeneralEngine")

# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTVISUAL_SOURCE_DIR}/config.h.in
    ${SOFAOPENGLVISUAL_SRC}/OglModel.h
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTVISUAL_SOURCE_DIR}/initMinimal.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglModel.cpp
)

# Full set
set(HEADER_FILES
    ${SOFAOPENGLVISUAL_SRC}/ClipPlane.h
    ${SOFAOPENGLVISUAL_SRC}/OglColorMap.h
    ${SOFAOPENGLVISUAL_SRC}/CompositingVisualLoop.h
    ${SOFAOPENGLVISUAL_SRC}/DataDisplay.h
    ${SOFAOPENGLVISUAL_SRC}/OglLabel.h
    ${SOFAOPENGLVISUAL_SRC}/PointSplatModel.h
    ${SOFAOPENGLVISUAL_SRC}/MergeVisualModels.h
    ${SOFAOPENGLVISUAL_SRC}/LightManager.h
    ${SOFAOPENGLVISUAL_SRC}/Light.h
    ${SOFAOPENGLVISUAL_SRC}/OrderIndependentTransparencyManager.h
    ${SOFAOPENGLVISUAL_SRC}/OglOITShader.h
    ${SOFAOPENGLVISUAL_SRC}/OglAttribute.h
    ${SOFAOPENGLVISUAL_SRC}/OglAttribute.inl
    ${SOFAOPENGLVISUAL_SRC}/OglShader.h
    ${SOFAOPENGLVISUAL_SRC}/OglShaderMacro.h
    ${SOFAOPENGLVISUAL_SRC}/OglShaderVisualModel.h
    ${SOFAOPENGLVISUAL_SRC}/OglShadowShader.h
    ${SOFAOPENGLVISUAL_SRC}/OglTexture.h
    ${SOFAOPENGLVISUAL_SRC}/OglTexturePointer.h
    ${SOFAOPENGLVISUAL_SRC}/OglVariable.h
    ${SOFAOPENGLVISUAL_SRC}/OglVariable.inl
    ${SOFAOPENGLVISUAL_SRC}/OglViewport.h
    ${SOFAOPENGLVISUAL_SRC}/OglCylinderModel.h
    ${SOFAOPENGLVISUAL_SRC}/OglGrid.h
    ${SOFAOPENGLVISUAL_SRC}/OglRenderingSRGB.h
    ${SOFAOPENGLVISUAL_SRC}/OglLineAxis.h
    ${SOFAOPENGLVISUAL_SRC}/OglSceneFrame.h
    ${SOFAOPENGLVISUAL_SRC}/PostProcessManager.h
    ${SOFAOPENGLVISUAL_SRC}/SlicedVolumetricModel.h
    ${SOFAOPENGLVISUAL_SRC}/VisualManagerPass.h
    ${SOFAOPENGLVISUAL_SRC}/VisualManagerSecondaryPass.h
    ${SOFAGENERALENGINE_SRC}/TextureInterpolation.h
    ${SOFAGENERALENGINE_SRC}/TextureInterpolation.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTVISUAL_SOURCE_DIR}/init.cpp
    ${SOFAOPENGLVISUAL_SRC}/ClipPlane.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglColorMap.cpp
    ${SOFAOPENGLVISUAL_SRC}/CompositingVisualLoop.cpp
    ${SOFAOPENGLVISUAL_SRC}/DataDisplay.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglGrid.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglLabel.cpp
    ${SOFAOPENGLVISUAL_SRC}/PointSplatModel.cpp
    ${SOFAOPENGLVISUAL_SRC}/MergeVisualModels.cpp
    ${SOFAOPENGLVISUAL_SRC}/Light.cpp
    ${SOFAOPENGLVISUAL_SRC}/LightManager.cpp
    ${SOFAOPENGLVISUAL_SRC}/OrderIndependentTransparencyManager.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglOITShader.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglAttribute.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglShader.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglShaderMacro.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglShaderVisualModel.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglShadowShader.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglTexture.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglTexturePointer.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglVariable.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglViewport.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglCylinderModel.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglGrid.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglRenderingSRGB.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglLineAxis.cpp
    ${SOFAOPENGLVISUAL_SRC}/OglSceneFrame.cpp
    ${SOFAOPENGLVISUAL_SRC}/PostProcessManager.cpp
    ${SOFAOPENGLVISUAL_SRC}/SlicedVolumetricModel.cpp
    ${SOFAOPENGLVISUAL_SRC}/VisualManagerPass.cpp
    ${SOFAOPENGLVISUAL_SRC}/VisualManagerSecondaryPass.cpp
    ${SOFAGENERALENGINE_SRC}/TextureInterpolation.cpp
)

set(WRAPPER_FILES
    wrapper/SofaOpenglVisual/config.h
    wrapper/SofaGeneralEngine/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)
sofa_find_package(SofaFramework REQUIRED)
sofa_find_package(Sofa.GL REQUIRED)

configure_file(${SOFACOMPONENTVISUAL_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/visual/gl/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.GL)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC Sofa.Component.Visual_minimal)

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTVISUALGL)
target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAOPENGLVISUAL)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${SOFAOPENGLVISUAL_DIR}/src")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})

target_include_directories(${FULL_TARGET_NAME} PUBLIC "${SOFAGENERALENGINE_DIR}/src")

target_compile_definitions(${FULL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTVISUALGL)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAOPENGLVISUAL)
target_compile_definitions(${FULL_TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALENGINE)
