#pragma once

#include <sofa/component/linearsolver/config.h>

#ifdef SOFA_BUILD_SOFAEIGEN2SOLVER
#  define SOFA_SOFAEIGEN2SOLVER_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAEIGEN2SOLVER_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
