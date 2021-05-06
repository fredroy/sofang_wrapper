cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.Controller LANGUAGES CXX)

set(SOFACOMPONENTSCONTROLLER_SOURCE_DIR "src/sofa/components/controller")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAUSERINTERACTION_DIR "${SOFAMODULES_SOURCE_DIR}/SofaUserInteraction/")
set(SOFAUSERINTERACTION_SRC "${SOFAUSERINTERACTION_DIR}/src/SofaUserInteraction")

set(HEADER_FILES
	${SOFACOMPONENTSCONTROLLER_SOURCE_DIR}/config.h.in
    ${SOFAUSERINTERACTION_SRC}/Controller.h
    ${SOFAUSERINTERACTION_SRC}/MechanicalStateController.h
    ${SOFAUSERINTERACTION_SRC}/MechanicalStateController.inl
    ${SOFAUSERINTERACTION_SRC}/SleepController.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTSCONTROLLER_SOURCE_DIR}/init.cpp
    ${SOFAUSERINTERACTION_SRC}/Controller.cpp
    ${SOFAUSERINTERACTION_SRC}/MechanicalStateController.cpp
    ${SOFAUSERINTERACTION_SRC}/SleepController.cpp
)

set(WRAPPER_FILES
    wrapper/SofaUserInteraction/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTSCONTROLLER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/controller/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAUSERINTERACTION_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAUSERINTERACTION)