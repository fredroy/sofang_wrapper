cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.PhysicalModel LANGUAGES CXX)

set(SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR "src/sofa/component/physicalmodel")

set(SOFACOMPONENTPHYSICALMODEL_DIRS Mass SolidMechanics)
set(SOFACOMPONENTPHYSICALMODEL_TARGETS)
foreach(physicalmodel_dir ${SOFACOMPONENTPHYSICALMODEL_DIRS})
	add_subdirectory(${physicalmodel_dir})
    list(APPEND SOFACOMPONENTPHYSICALMODEL_TARGETS ${PROJECT_NAME}.${physicalmodel_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/physicalmodel/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTPHYSICALMODEL_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTPHYSICALMODEL)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
