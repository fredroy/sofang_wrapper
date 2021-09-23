#pragma once

#include <sofa/component/collision/models/config.h>

#ifdef SOFA_BUILD_SOFAMISCCOLLISION
#  define SOFA_MISC_COLLISION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_MISC_COLLISION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
