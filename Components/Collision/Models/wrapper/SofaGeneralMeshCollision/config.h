#pragma once

#include <sofa/components/collision/models/config.h>

#ifdef SOFA_BUILD_SOFAGENERALMESHCOLLISION
#  define SOFA_SOFAGENERALMESHCOLLISION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGENERALMESHCOLLISION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif