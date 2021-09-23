#pragma once

#include <sofa/component/physicalmodel/mass/config.h>

#ifdef SOFA_BUILD_SOFABASEMECHANICS
#  define SOFA_SOFABASEMECHANICS_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFABASEMECHANICS_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
