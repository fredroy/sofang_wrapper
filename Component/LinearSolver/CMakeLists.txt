cmake_minimum_required(VERSION 3.12)
project(Sofa.Component.LinearSolver LANGUAGES CXX)

set(SOFACOMPONENTLINEARSOLVER_SOURCE_DIR "src/sofa/component/linearsolver")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASELINEARSOLVER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseLinearSolver/")
set(SOFABASELINEARSOLVER_SRC "${SOFABASELINEARSOLVER_DIR}/src/SofaBaseLinearSolver")

set(SOFAGENERALLINEARSOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralLinearSolver/")
set(SOFAGENERALLINEARSOLVER_SRC "${SOFAGENERALLINEARSOLVER_DIR}/src/SofaGeneralLinearSolver")
set(SOFADENSESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaDenseSolver/")
set(SOFADENSESOLVER_SRC "${SOFADENSESOLVER_DIR}/src/SofaDenseSolver")
set(SOFASPARSESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaSparseSolver/")
set(SOFASPARSESOLVER_SRC "${SOFASPARSESOLVER_DIR}/src/SofaSparseSolver")

# Adding SofaPreconditioner ?
# Weird dependencies on SofaSimpleFEM anyway

set(HEADER_FILES
    ${SOFACOMPONENTLINEARSOLVER_SOURCE_DIR}/config.h.in
    ${SOFABASELINEARSOLVER_SRC}/BlocMatrixWriter.h
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.h
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.inl
    ${SOFABASELINEARSOLVER_SRC}/DefaultMultiMatrixAccessor.h
    ${SOFABASELINEARSOLVER_SRC}/GraphScatteredTypes.h
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.h
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.inl
    ${SOFABASELINEARSOLVER_SRC}/SingleMatrixAccessor.h
    ${SOFADENSESOLVER_SRC}/SVDLinearSolver.h
    ${SOFAGENERALLINEARSOLVER_SRC}/BTDLinearSolver.h
    ${SOFAGENERALLINEARSOLVER_SRC}/BTDLinearSolver.inl
    ${SOFAGENERALLINEARSOLVER_SRC}/CholeskySolver.h
    ${SOFAGENERALLINEARSOLVER_SRC}/CholeskySolver.inl
    ${SOFAGENERALLINEARSOLVER_SRC}/MinResLinearSolver.h
    ${SOFAGENERALLINEARSOLVER_SRC}/MinResLinearSolver.inl
    ${SOFADENSESOLVER_SRC}/LULinearSolver.h
    ${SOFADENSESOLVER_SRC}/NewMatMatrix.h
    ${SOFADENSESOLVER_SRC}/NewMatVector.h
    ${SOFASPARSESOLVER_SRC}/PrecomputedLinearSolver.h
    ${SOFASPARSESOLVER_SRC}/PrecomputedLinearSolver.inl
    ${SOFASPARSESOLVER_SRC}/SparseLDLSolver.h
    ${SOFASPARSESOLVER_SRC}/SparseLDLSolver.inl
    ${SOFASPARSESOLVER_SRC}/SparseLDLSolverImpl.h
    ${SOFASPARSESOLVER_SRC}/SparseCholeskySolver.h
    ${SOFASPARSESOLVER_SRC}/SparseLUSolver.h
    ${SOFASPARSESOLVER_SRC}/SparseLUSolver.inl
)

set(SOURCE_FILES
    ${SOFACOMPONENTLINEARSOLVER_SOURCE_DIR}/init.cpp
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.cpp
    ${SOFABASELINEARSOLVER_SRC}/DefaultMultiMatrixAccessor.cpp
    ${SOFABASELINEARSOLVER_SRC}/GraphScatteredTypes.cpp
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.cpp
    ${SOFABASELINEARSOLVER_SRC}/SingleMatrixAccessor.cpp
    ${SOFADENSESOLVER_SRC}/SVDLinearSolver.cpp
    ${SOFAGENERALLINEARSOLVER_SRC}/BTDLinearSolver.cpp
    ${SOFAGENERALLINEARSOLVER_SRC}/CholeskySolver.cpp
    ${SOFAGENERALLINEARSOLVER_SRC}/MinResLinearSolver.cpp
    ${SOFADENSESOLVER_SRC}/LULinearSolver.cpp
    ${SOFADENSESOLVER_SRC}/NewMatCGLinearSolver.cpp
    ${SOFADENSESOLVER_SRC}/NewMatCholeskySolver.cpp
    ${SOFASPARSESOLVER_SRC}/PrecomputedLinearSolver.cpp
    ${SOFASPARSESOLVER_SRC}/SparseLDLSolver.cpp
    ${SOFASPARSESOLVER_SRC}/SparseCholeskySolver.cpp
    ${SOFASPARSESOLVER_SRC}/SparseLUSolver.cpp
)

set(WRAPPER_FILES
    wrapper/SofaBaseLinearSolver/config.h
    wrapper/SofaGeneralLinearSolver/config.h
    wrapper/SofaDenseSolver/config.h
    wrapper/SofaSparseSolver/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

set(TARGET_NAME ${PROJECT_NAME})
sofa_find_package(SofaFramework REQUIRED)
sofa_find_package(Eigen3 REQUIRED)

if (SOFA_OPENMP AND "${EIGEN3_VERSION}" VERSION_LESS 3.2.9)
    sofa_find_package(OpenMP) # will set/update SOFA_COMPONENTS_LINEARSOLVER_HAVE_OPENMP
endif()

if (SOFA_COMPONENTS_LINEARSOLVER_HAVE_OPENMP)
    list(APPEND HEADER_FILES EigenBaseSparseMatrix_MT.h)
endif()

add_subdirectory(${SOFASPARSESOLVER_DIR}/extlibs/csparse ${CMAKE_CURRENT_BINARY_DIR}/extlibs/csparse)
sofa_set_01(SOFA_COMPONENTS_LINEARSOLVER_HAVE_CSPARSE VALUE TRUE)

sofa_find_package(metis QUIET) # Unix users can have an installed version of metis
if(NOT metis_FOUND)
    message(STATUS "Sofa.Component.LinearSolver: using built-in metis library")
    add_subdirectory(${SOFASPARSESOLVER_DIR}/extlibs/metis-5.1.0 ${CMAKE_CURRENT_BINARY_DIR}/extlibs/metis-5.1.0)
endif()
sofa_set_01(SOFA_COMPONENTS_LINEARSOLVER_HAVE_METIS VALUE TRUE)

sofa_find_package(Newmat REQUIRED)

configure_file(${SOFACOMPONENTLINEARSOLVER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/component/linearsolver/config.h)

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${TARGET_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${TARGET_NAME} PUBLIC Eigen3::Eigen)
target_link_libraries(${TARGET_NAME} PUBLIC newmat)
target_link_libraries(${TARGET_NAME} PUBLIC metis csparse)

target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFABASELINEARSOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFAGENERALLINEARSOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFADENSESOLVER)
target_compile_definitions(${TARGET_NAME} PRIVATE SOFA_BUILD_SOFASPARSESOLVER)

target_include_directories(${TARGET_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFABASELINEARSOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFAGENERALLINEARSOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFADENSESOLVER_DIR}/src")
target_include_directories(${TARGET_NAME} PUBLIC "${SOFASPARSESOLVER_DIR}/src")
