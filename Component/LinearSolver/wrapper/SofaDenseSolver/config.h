#pragma once

#include <sofa/component/linearsolver/config.h>

#ifdef SOFA_BUILD_SOFADENSESOLVER
#  define SOFA_SOFADENSESOLVER_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFADENSESOLVER_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
