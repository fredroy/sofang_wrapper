cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.IO.Misc LANGUAGES CXX)

set(SOFACOMPONENTIOMISC_SOURCE_DIR "src/sofa/component/io/misc")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAGENERALLOADER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralLoader/")
set(SOFAGENERALLOADER_SRC "${SOFAGENERALLOADER_DIR}/src/SofaGeneralLoader")
set(SOFAEXPORTER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaExporter/")
set(SOFAEXPORTER_SRC "${SOFAEXPORTER_DIR}/src/SofaExporter")

set(HEADER_FILES
    ${SOFACOMPONENTIOMISC_SOURCE_DIR}/config.h.in
    ${SOFAGENERALLOADER_SRC}/ReadState.h
    ${SOFAGENERALLOADER_SRC}/ReadState.inl
    ${SOFAEXPORTER_SRC}/WriteState.h
    ${SOFAEXPORTER_SRC}/WriteState.inl
    ${SOFAGENERALLOADER_SRC}/ReadTopology.h
    ${SOFAGENERALLOADER_SRC}/ReadTopology.inl
    ${SOFAGENERALLOADER_SRC}/InputEventReader.h
    ${SOFAEXPORTER_SRC}/WriteTopology.h
    ${SOFAEXPORTER_SRC}/WriteTopology.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTIOMISC_SOURCE_DIR}/init.cpp
    ${SOFAGENERALLOADER_SRC}/ReadState.cpp
    ${SOFAEXPORTER_SRC}/WriteState.cpp
    ${SOFAGENERALLOADER_SRC}/ReadTopology.cpp
    ${SOFAGENERALLOADER_SRC}/InputEventReader.cpp
    ${SOFAEXPORTER_SRC}/WriteTopology.cpp
)

set(WRAPPER_FILES
    wrapper/SofaGeneralLoader/config.h
    wrapper/SofaExporter/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTIOMISC_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/io/misc/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALLOADER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAEXPORTER)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALLOADER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAEXPORTER_DIR}/src")
