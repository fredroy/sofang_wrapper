cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.ODESolver LANGUAGES CXX)

set(SOFACOMPONENTODESOLVER_SOURCE_DIR "src/sofa/component/odesolver")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFAEXPLICITODESOLVER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaExplicitOdeSolver/")
set(SOFAEXPLICITODESOLVER_SRC "${SOFAEXPLICITODESOLVER_DIR}/src/SofaExplicitOdeSolver")
set(SOFAIMPLICITODESOLVER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaImplicitOdeSolver/")
set(SOFAIMPLICITODESOLVER_SRC "${SOFAIMPLICITODESOLVER_DIR}/src/SofaImplicitOdeSolver")

set(SOFAGENERALIMPLICITODESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralImplicitOdeSolver/")
set(SOFAGENERALIMPLICITODESOLVER_SRC "${SOFAGENERALIMPLICITODESOLVER_DIR}/src/SofaGeneralImplicitOdeSolver")
set(SOFAGENERALEXPLICITODESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralExplicitOdeSolver/")
set(SOFAGENERALEXPLICITODESOLVER_SRC "${SOFAGENERALEXPLICITODESOLVER_DIR}/src/SofaGeneralExplicitOdeSolver")
set(SOFAMISCSOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaMiscSolver/")
set(SOFAMISCSOLVER_SRC "${SOFAMISCSOLVER_DIR}/src/SofaMiscSolver")

set(HEADER_FILES
    ${SOFACOMPONENTODESOLVER_SOURCE_DIR}/config.h.in
    ${SOFAEXPLICITODESOLVER_SRC}/EulerSolver.h
    ${SOFAIMPLICITODESOLVER_SRC}/EulerImplicitSolver.h
    ${SOFAIMPLICITODESOLVER_SRC}/StaticSolver.h
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/CentralDifferenceSolver.h
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/RungeKutta2Solver.h
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/RungeKutta4Solver.h
    ${SOFAGENERALIMPLICITODESOLVER_SRC}/VariationalSymplecticSolver.h
    ${SOFAMISCSOLVER_SRC}/DampVelocitySolver.h
    ${SOFAMISCSOLVER_SRC}/NewmarkImplicitSolver.h
)

set(SOURCE_FILES
    ${SOFACOMPONENTODESOLVER_SOURCE_DIR}/init.cpp
    ${SOFAEXPLICITODESOLVER_SRC}/EulerSolver.cpp
    ${SOFAIMPLICITODESOLVER_SRC}/EulerImplicitSolver.cpp
    ${SOFAIMPLICITODESOLVER_SRC}/StaticSolver.cpp
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/CentralDifferenceSolver.cpp
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/RungeKutta2Solver.cpp
    ${SOFAGENERALEXPLICITODESOLVER_SRC}/RungeKutta4Solver.cpp
    ${SOFAGENERALIMPLICITODESOLVER_SRC}/VariationalSymplecticSolver.cpp
    ${SOFAMISCSOLVER_SRC}/DampVelocitySolver.cpp
    ${SOFAMISCSOLVER_SRC}/NewmarkImplicitSolver.cpp
)

set(WRAPPER_FILES
    wrapper/SofaExplicitOdeSolver/config.h
    wrapper/SofaImplicitOdeSolver/config.h
    wrapper/SofaGeneralImplicitOdeSolver/config.h
    wrapper/SofaGeneralExplicitOdeSolver/config.h
    wrapper/SofaMiscSolver/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)

configure_file(${SOFACOMPONENTODESOLVER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/odesolver/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)

target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_SOFACOMPONENTODESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAEXPLICITODESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAIMPLICITODESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALEXPLICITODESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALIMPLICITODESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAMISCSOLVER)
target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAEXPLICITODESOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAIMPLICITODESOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALEXPLICITODESOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALIMPLICITODESOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAMISCSOLVER_DIR}/src")
