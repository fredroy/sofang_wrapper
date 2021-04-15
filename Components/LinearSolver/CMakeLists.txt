cmake_minimum_required(VERSION 3.12)
project(Sofa.Components.LinearSolver LANGUAGES CXX)

set(SOFACOMPONENTSLINEARSOLVER_SOURCE_DIR "src/sofa/components/linearsolver")

set(SOFAMODULES_SOURCE_DIR "${SOFA_SOURCE_DIR}/modules")
set(SOFAKERNELMODULES_SOURCE_DIR "${SOFA_KERNEL_SOURCE_DIR}/modules")

set(SOFABASELINEARSOLVER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaBaseLinearSolver/")
set(SOFABASELINEARSOLVER_SRC "${SOFABASELINEARSOLVER_DIR}/src/SofaBaseLinearSolver")
set(SOFAEIGEN2SOLVER_DIR "${SOFAKERNELMODULES_SOURCE_DIR}/SofaEigen2Solver/")
set(SOFAEIGEN2SOLVER_SRC "${SOFAEIGEN2SOLVER_DIR}/src/SofaEigen2Solver")

set(SOFAGENERALLINEARSOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaGeneralLinearSolver/")
set(SOFAGENERALLINEARSOLVER_SRC "${SOFAGENERALLINEARSOLVER_DIR}/src/SofaGeneralLinearSolver")
set(SOFADENSESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaDenseSolver/")
set(SOFADENSESOLVER_SRC "${SOFADENSESOLVER_DIR}/src/SofaDenseSolver")
set(SOFASPARSESOLVER_DIR "${SOFAMODULES_SOURCE_DIR}/SofaSparseSolver/")
set(SOFASPARSESOLVER_SRC "${SOFASPARSESOLVER_DIR}/src/SofaSparseSolver")

# Adding SofaPreconditioner ?
# Weird dependencies on SofaSimpleFEM anyway

set(HEADER_FILES
	${SOFACOMPONENTSLINEARSOLVER_SOURCE_DIR}/config.h.in
    ${SOFABASELINEARSOLVER_SRC}/BlocMatrixWriter.h
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.h
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.inl
    ${SOFABASELINEARSOLVER_SRC}/CompressedRowSparseMatrix.h
    ${SOFABASELINEARSOLVER_SRC}/CompressedRowSparseMatrix.inl
    ${SOFABASELINEARSOLVER_SRC}/DefaultMultiMatrixAccessor.h
    ${SOFABASELINEARSOLVER_SRC}/DiagonalMatrix.h
    ${SOFABASELINEARSOLVER_SRC}/FullMatrix.h
    ${SOFABASELINEARSOLVER_SRC}/FullMatrix.inl
    ${SOFABASELINEARSOLVER_SRC}/FullVector.h
    ${SOFABASELINEARSOLVER_SRC}/FullVector.inl
    ${SOFABASELINEARSOLVER_SRC}/GraphScatteredTypes.h
    ${SOFABASELINEARSOLVER_SRC}/MatrixExpr.h
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.h
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.inl
    ${SOFABASELINEARSOLVER_SRC}/SingleMatrixAccessor.h
    ${SOFABASELINEARSOLVER_SRC}/SparseMatrix.h
    ${SOFABASELINEARSOLVER_SRC}/matrix_bloc_traits.h
    ${SOFAEIGEN2SOLVER_SRC}/EigenBaseSparseMatrix.h
    ${SOFAEIGEN2SOLVER_SRC}/EigenMatrixManipulator.h
    ${SOFAEIGEN2SOLVER_SRC}/EigenSparseMatrix.h
    ${SOFAEIGEN2SOLVER_SRC}/EigenVector.h
    ${SOFAEIGEN2SOLVER_SRC}/EigenVectorWrapper.h
    ${SOFAEIGEN2SOLVER_SRC}/SVDLinearSolver.h
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
    ${SOFACOMPONENTSLINEARSOLVER_SOURCE_DIR}/init.cpp
    ${SOFABASELINEARSOLVER_SRC}/CGLinearSolver.cpp
    ${SOFABASELINEARSOLVER_SRC}/DefaultMultiMatrixAccessor.cpp
    ${SOFABASELINEARSOLVER_SRC}/FullMatrix.cpp
    ${SOFABASELINEARSOLVER_SRC}/FullVector.cpp
    ${SOFABASELINEARSOLVER_SRC}/GraphScatteredTypes.cpp
    ${SOFABASELINEARSOLVER_SRC}/MatrixLinearSolver.cpp
    ${SOFABASELINEARSOLVER_SRC}/SingleMatrixAccessor.cpp
    ${SOFAEIGEN2SOLVER_SRC}/EigenMatrixManipulator.cpp
    ${SOFAEIGEN2SOLVER_SRC}/EigenVector.cpp
    ${SOFAEIGEN2SOLVER_SRC}/SVDLinearSolver.cpp
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
    wrapper/SofaEigen2Solver/config.h
    wrapper/SofaGeneralLinearSolver/config.h
    wrapper/SofaDenseSolver/config.h
    wrapper/SofaSparseSolver/config.h
)
source_group("wrapper" FILES ${WRAPPER_FILES})

add_subdirectory(${SOFASPARSESOLVER_DIR}/extlibs/csparse ${CMAKE_CURRENT_BINARY_DIR}/extlibs/csparse)
sofa_set_01(SOFA_COMPONENTS_LINEARSOLVER_HAVE_CSPARSE VALUE TRUE)

sofa_find_package(metis QUIET) # Unix users can have an installed version of metis
if(NOT metis_FOUND)
    message(STATUS "Sofa.Components.LinearSolver: using built-in metis library")
    add_subdirectory(${SOFASPARSESOLVER_DIR}/extlibs/metis-5.1.0 ${CMAKE_CURRENT_BINARY_DIR}/extlibs/metis-5.1.0)
endif()
sofa_set_01(SOFA_COMPONENTS_LINEARSOLVER_HAVE_METIS VALUE TRUE)

sofa_find_package(SofaFramework REQUIRED)
sofa_find_package(Newmat REQUIRED)
sofa_find_package(Eigen3 REQUIRED)

if (SOFA_OPENMP AND "${EIGEN3_VERSION}" VERSION_LESS 3.2.9)
    sofa_find_package(OpenMP) # will set/update SOFA_COMPONENTS_LINEARSOLVER_HAVE_OPENMP
endif()

if (SOFA_COMPONENTS_LINEARSOLVER_HAVE_OPENMP)
    list(APPEND HEADER_FILES EigenBaseSparseMatrix_MT.h)
endif()

configure_file(${SOFACOMPONENTSLINEARSOLVER_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/include/sofa/components/linearsolver/config.h)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${WRAPPER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCore)
target_link_libraries(${PROJECT_NAME} PUBLIC newmat)
target_link_libraries(${PROJECT_NAME} PUBLIC metis csparse)
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/")

target_include_directories(${PROJECT_NAME} PUBLIC "${SOFABASELINEARSOLVER_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAEIGEN2SOLVER_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFAGENERALLINEARSOLVER_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFADENSESOLVER_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${SOFASPARSESOLVER_DIR}/src")

target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFABASELINEARSOLVER)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAEIGEN2SOLVER)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFAGENERALLINEARSOLVER)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFADENSESOLVER)
target_compile_definitions(${PROJECT_NAME} PRIVATE SOFA_BUILD_SOFASPARSESOLVER)
