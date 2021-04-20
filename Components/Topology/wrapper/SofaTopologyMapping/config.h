#pragma once

#include <sofa/components/topology/config.h>

#ifdef SOFA_BUILD_SOFATOPOLOGYMAPPING
#  define SOFA_SOFATOPOLOGYMAPPING_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFATOPOLOGYMAPPING_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
