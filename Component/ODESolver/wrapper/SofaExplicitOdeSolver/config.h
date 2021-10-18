#pragma once

#include <sofa/component/odesolver/config.h>

#ifdef SOFA_BUILD_SOFAEXPLICITODESOLVER
#  define SOFA_SOFAEXPLICITODESOLVER_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAEXPLICITODESOLVER_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif

#ifdef SOFA_BUILD_SOFAEXPLICITODESOLVER
#define SOFA_ATTRIBUTE_DISABLED__EULERSOLVER_OPTIM_DIAGONALMATRIX()
#else
#define SOFA_ATTRIBUTE_DISABLED__EULERSOLVER_OPTIM_DIAGONALMATRIX() \
    SOFA_ATTRIBUTE_DISABLED( \
    "v21.06 (PR#2165)", "v21.06",\
    "Optimization based on the diagonal property of the mass matrix is now detected automatically.")
#endif
