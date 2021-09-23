#pragma once

#include <sofa/components/collision/models/config.h>

#ifdef SOFA_BUILD_SOFAMESHCOLLISION
#  define SOFA_SOFAMESHCOLLISION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAMESHCOLLISION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
