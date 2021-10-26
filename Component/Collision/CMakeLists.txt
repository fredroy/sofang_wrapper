cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.Collision LANGUAGES CXX)

set(SOFACOMPONENTCOLLISION_SOURCE_DIR "src/sofa/component/collision")

set(SOFACOMPONENTCOLLISION_DIRS Models Detection Response)
set(SOFACOMPONENTCOLLISION_TARGETS)
foreach(collision_dir ${SOFACOMPONENTCOLLISION_DIRS})
	sofang_add_component_subdirectory(${collision_dir} ${PROJECT_NAME}.${collision_dir})
	list(APPEND SOFACOMPONENTCOLLISION_TARGETS ${PROJECT_NAME}.${collision_dir})
endforeach()

set(HEADER_FILES
    ${SOFACOMPONENTCOLLISION_SOURCE_DIR}/config.h.in
)

set(SOURCE_FILES
    ${SOFACOMPONENTCOLLISION_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFACOMPONENTCOLLISION_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/collision/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFACOMPONENTCOLLISION_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTCOLLISION)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
