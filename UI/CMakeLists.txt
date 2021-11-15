cmake_minimum_required(VERSION 3.12)
project(Sofa.UI LANGUAGES CXX)

set(SOFAUI_SOURCE_DIR "src/sofa/ui")

set(SOFAUI_DIRS Core) # Qt...
set(SOFAUI_TARGETS)
foreach(ui_dir ${SOFAUI_DIRS})
	sofang_add_subdirectory_and_option(${ui_dir} ${PROJECT_NAME}.${ui_dir})
	list(APPEND SOFAUI_TARGETS ${PROJECT_NAME}.${ui_dir})
endforeach()

set(HEADER_FILES
    ${SOFAUI_SOURCE_DIR}/config.h.in
    ${SOFAUI_SOURCE_DIR}/init.h
)

set(SOURCE_FILES
    ${SOFAUI_SOURCE_DIR}/init.cpp
)

set(TARGET_NAME ${PROJECT_NAME})

configure_file(${SOFAUI_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/ui/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC ${SOFAUI_TARGETS})

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENT)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
