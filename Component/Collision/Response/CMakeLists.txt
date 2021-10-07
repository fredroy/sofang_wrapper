cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision.Response LANGUAGES CXX)

set(SOFACOMPONENTCOLLISIONRESPONSE_SOURCE_DIR "src/sofa/component/collision/response")

set(SOFACOMPONENTCOLLISIONRESPONSE_DIRS Contact)
set(SOFACOMPONENTCOLLISIONRESPONSE_TARGETS)
foreach(response_dir ${SOFACOMPONENTCOLLISIONRESPONSE_DIRS})
	sofang_add_component_subdirectory(${response_dir})
    list(APPEND SOFACOMPONENTCOLLISIONRESPONSE_TARGETS ${PROJECT_NAME}.${response_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISIONRESPONSE_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISIONRESPONSE_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTCOLLISIONRESPONSE_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/collision/response/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTCOLLISIONRESPONSE_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISIONRESPONSE)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
