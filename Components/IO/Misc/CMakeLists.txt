cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.IO.Misc LANGUAGES CXX)

set(SOFACOMPONENTSIOMISC_SOURCE_DIR "src/sofa/components/io/misc")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAGENERALLOADER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralLoader/")
set(SOFAGENERALLOADER_SRC "${SOFAGENERALLOADER_DIR}/src/SofaGeneralLoader")
set(SOFAEXPORTER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaExporter/")
set(SOFAEXPORTER_SRC "${SOFAEXPORTER_DIR}/src/SofaExporter")

set(HEADER_FILES
	${SOFACOMPONENTSIOMISC_SOURCE_DIR}/config.h.in
    ${SOFAGENERALLOADER_SRC}/ReadState.h
    ${SOFAGENERALLOADER_SRC}/ReadState.inl
    ${SOFAGENERALLOADER_SRC}/ReadTopology.h
    ${SOFAGENERALLOADER_SRC}/ReadTopology.inl
    ${SOFAGENERALLOADER_SRC}/InputEventReader.h
    ${SOFAEXPORTER_SRC}/WriteState.h
    ${SOFAEXPORTER_SRC}/WriteState.inl
    ${SOFAEXPORTER_SRC}/WriteTopology.h
    ${SOFAEXPORTER_SRC}/WriteTopology.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTSIOMISC_SOURCE_DIR}/init.cpp
    ${SOFAGENERALLOADER_SRC}/ReadState.cpp
    ${SOFAGENERALLOADER_SRC}/ReadTopology.cpp
    ${SOFAGENERALLOADER_SRC}/InputEventReader.cpp
    ${SOFAEXPORTER_SRC}/WriteState.cpp
    ${SOFAEXPORTER_SRC}/WriteTopology.cpp
)

set(WRAPPER_FILES
    wrapper/SofaGeneralLoader/config.h
    wrapper/SofaExporter/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)
sofa_find_package(TinyXML REQUIRED) # for BaseVTKReader

configure_file(${SOFACOMPONENTSIOMISC_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/io/misc/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALLOADER_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAEXPORTER_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALLOADER)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAEXPORTER)
