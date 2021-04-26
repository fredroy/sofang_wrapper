cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Utils LANGUAGES CXX)

set(SOFACOMPONENTSUTILS_SOURCE_DIR "src/sofa/components/utils")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASEUTILS_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseUtils/")
set(SOFABASEUTILS_SRC "${SOFABASEUTILS_DIR}/src/SofaBaseUtils")

set(HEADER_FILES
	${SOFACOMPONENTSUTILS_SOURCE_DIR}/config.h.in
    ${SOFABASEUTILS_SRC}/messageHandlerComponent.h
    ${SOFABASEUTILS_SRC}/MakeAliasComponent.h
    ${SOFABASEUTILS_SRC}/MakeDataAliasComponent.h
    ${SOFABASEUTILS_SRC}/InfoComponent.h
    ${SOFABASEUTILS_SRC}/RequiredPlugin.h
    ${SOFABASEUTILS_SRC}/AddResourceRepository.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTSUTILS_SOURCE_DIR}/init.cpp
    ${SOFABASEUTILS_SRC}/messageHandlerComponent.cpp
    ${SOFABASEUTILS_SRC}/MakeAliasComponent.cpp
    ${SOFABASEUTILS_SRC}/MakeDataAliasComponent.cpp
    ${SOFABASEUTILS_SRC}/InfoComponent.cpp
    ${SOFABASEUTILS_SRC}/RequiredPlugin.cpp
    ${SOFABASEUTILS_SRC}/AddResourceRepository.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseUtils/config.h

)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSUTILS_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/utils/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaCore)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASEUTILS_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASEUTILS)
