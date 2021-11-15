cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.IO LANGUAGES CXX)

set(SOFACOMPONENTIO_SOURCE_DIR "src/sofa/component/io")

set(SOFACOMPONENTIO_DIRS Mesh Misc)
set(SOFACOMPONENTIO_TARGETS)
foreach(io_dir ${SOFACOMPONENTIO_DIRS})
    sofang_add_subdirectory_and_option(${io_dir} ${PROJECT_NAME}.${io_dir})
    list(APPEND SOFACOMPONENTIO_TARGETS ${PROJECT_NAME}.${io_dir})
endforeach()


set(HEADER_FILES
    ${SOFACOMPONENTIO_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTIO_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTIO_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/io/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTIO_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTIO)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
