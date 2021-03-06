cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Detection LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONDETECTION_SOURCE_DIR "src/sofa/component/collision/detection")

set(SOFACOMPONENTCOLLISIONDETECTION_DIRS Algorithm Intersection)
set(SOFACOMPONENTCOLLISIONDETECTION_TARGETS)
foreach(detection_dir ${SOFACOMPONENTCOLLISIONDETECTION_DIRS})
	sofang_add_subdirectory_and_option(${detection_dir} ${PROJECT_NAME}.${detection_dir})
	list(APPEND SOFACOMPONENTCOLLISIONDETECTION_TARGETS ${PROJECT_NAME}.${detection_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONDETECTION_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISIONDETECTION_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTCOLLISIONDETECTION_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/collision/detection/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTCOLLISIONDETECTION_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONDETECTION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
