cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.IO.Mesh LANGUAGES CXX)

set(SOFACOMPONENTIOMESH_SOURCE_DIR "src/sofa/component/io/mesh")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFALOADER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaLoader/")
set(SOFALOADER_SRC "${SOFALOADER_DIR}/src/SofaLoader")

set(SOFAGENERALLOADER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralLoader/")
set(SOFAGENERALLOADER_SRC "${SOFAGENERALLOADER_DIR}/src/SofaGeneralLoader")
set(SOFAEXPORTER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaExporter/")
set(SOFAEXPORTER_SRC "${SOFAEXPORTER_DIR}/src/SofaExporter")

set(HEADER_FILES
    ${SOFACOMPONENTIOMESH_SOURCE_DIR}/config.h.in
    ${SOFALOADER_SRC}/BaseVTKReader.h
    ${SOFALOADER_SRC}/BaseVTKReader.inl
    ${SOFALOADER_SRC}/MeshObjLoader.h
    ${SOFALOADER_SRC}/MeshVTKLoader.h
    ${SOFAGENERALLOADER_SRC}/MeshGmshLoader.h
    ${SOFAEXPORTER_SRC}/OBJExporter.h
    ${SOFAEXPORTER_SRC}/VTKExporter.h
    ${SOFAGENERALLOADER_SRC}/GIDMeshLoader.h
    ${SOFAGENERALLOADER_SRC}/GridMeshCreator.h
    ${SOFAGENERALLOADER_SRC}/MeshOffLoader.h
    ${SOFAGENERALLOADER_SRC}/MeshSTLLoader.h
    ${SOFAGENERALLOADER_SRC}/MeshTrianLoader.h
    ${SOFAGENERALLOADER_SRC}/MeshXspLoader.h
    ${SOFAGENERALLOADER_SRC}/OffSequenceLoader.h
    ${SOFAGENERALLOADER_SRC}/SphereLoader.h
    ${SOFAGENERALLOADER_SRC}/StringMeshCreator.h
    ${SOFAGENERALLOADER_SRC}/VoxelGridLoader.h
    ${SOFAEXPORTER_SRC}/BlenderExporter.h
    ${SOFAEXPORTER_SRC}/BlenderExporter.inl
    ${SOFAEXPORTER_SRC}/MeshExporter.h
    ${SOFAEXPORTER_SRC}/STLExporter.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTIOMESH_SOURCE_DIR}/init.cpp
    ${SOFALOADER_SRC}/BaseVTKReader.cpp
    ${SOFALOADER_SRC}/MeshObjLoader.cpp
    ${SOFALOADER_SRC}/MeshVTKLoader.cpp
    ${SOFAGENERALLOADER_SRC}/MeshGmshLoader.cpp
    ${SOFAEXPORTER_SRC}/OBJExporter.cpp
    ${SOFAEXPORTER_SRC}/VTKExporter.cpp
    ${SOFAGENERALLOADER_SRC}/GIDMeshLoader.cpp
    ${SOFAGENERALLOADER_SRC}/GridMeshCreator.cpp
    ${SOFAGENERALLOADER_SRC}/MeshOffLoader.cpp
    ${SOFAGENERALLOADER_SRC}/MeshSTLLoader.cpp
    ${SOFAGENERALLOADER_SRC}/MeshTrianLoader.cpp
    ${SOFAGENERALLOADER_SRC}/MeshXspLoader.cpp
    ${SOFAGENERALLOADER_SRC}/OffSequenceLoader.cpp
    ${SOFAGENERALLOADER_SRC}/SphereLoader.cpp
    ${SOFAGENERALLOADER_SRC}/StringMeshCreator.cpp
    ${SOFAGENERALLOADER_SRC}/VoxelGridLoader.cpp
    ${SOFAEXPORTER_SRC}/BlenderExporter.cpp
    ${SOFAEXPORTER_SRC}/MeshExporter.cpp
    ${SOFAEXPORTER_SRC}/STLExporter.cpp
)

set(WRAPPER_FILES
    wrapper/SofaLoader/config.h
    wrapper/SofaGeneralLoader/config.h
    wrapper/SofaExporter/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(TinyXML REQUIRED) # for BaseVTKReader
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTIOMESH_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/io/mesh/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PRIVATE tinyxml)

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTIOMESH)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFALOADER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALLOADER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAEXPORTER)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFALOADER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALLOADER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAEXPORTER_DIR}/src")
