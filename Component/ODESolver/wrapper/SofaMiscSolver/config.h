#pragma once

#include <sofa/component/odesolver/config.h>

#ifdef SOFA_BUILD_SOFAMISCSOLVER
#  define SOFA_SOFAMISCSOLVER_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAMISCSOLVER_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
