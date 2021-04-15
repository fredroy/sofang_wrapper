#pragma once

#include <sofa/components/linearsolver/config.h>

#ifdef SOFA_BUILD_SOFACONSTRAINT
#  define SOFA_SOFACONSTRAINT_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFACONSTRAINT_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
