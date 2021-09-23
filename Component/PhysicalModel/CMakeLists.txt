cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.PhysicalModel LANGUAGES CXX)

set(SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR "src/sofa/component/physicalmodel")

# a bit special case as there is not Mass minimal (or rather all masses are deemed necessary)
set(SOFACOMPONENTPHYSICALMODEL_DIRS Mass SolidMechanics)
set(SOFACOMPONENTPHYSICALMODEL_TARGETS ${PROJECT_NAME}.Mass ${PROJECT_NAME}.SolidMechanics)
set(SOFACOMPONENTPHYSICALMODEL_TARGETS_MINIMAL ${PROJECT_NAME}.Mass ${PROJECT_NAME}.SolidMechanics_minimal)
foreach(physicalmodel_dir ${SOFACOMPONENTPHYSICALMODEL_DIRS})
	add_subdirectory(${physicalmodel_dir})
endforeach()


# Minimal set
set(MINIMAL_HEADER_FILES
    ${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/config.h.in
)

set(MINIMAL_SOURCE_FILES
    ${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/initMinimal.cpp
)

# Full set
set(SOURCE_FILES
    ${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/init.cpp
)

# Minimal config
set(MINIMAL_TARGET_NAME ${PROJECT_NAME}_minimal)

configure_file(${SOFACOMPONENTPHYSICALMODEL_SOURCE_DIR}/config.h.in 
    ${CMAKE_BINARY_DIR}/include/sofa/component/physicalmodel/config.h)

add_library(${MINIMAL_TARGET_NAME} SHARED ${MINIMAL_HEADER_FILES} ${MINIMAL_SOURCE_FILES})
set_target_properties(${MINIMAL_TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${MINIMAL_TARGET_NAME} PUBLIC ${SOFACOMPONENTPHYSICALMODEL_TARGETS_MINIMAL})

target_compile_definitions(${MINIMAL_TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTPHYSICALMODEL)
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${MINIMAL_TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if(BUILD_MINIMAL)
    return()
endif()

# Full config
set(FULL_TARGET_NAME ${PROJECT_NAME})

add_library(${FULL_TARGET_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${MINIMAL_TARGET_NAME})
target_link_libraries(${FULL_TARGET_NAME} PUBLIC ${SOFACOMPONENTPHYSICALMODEL_TARGETS})
