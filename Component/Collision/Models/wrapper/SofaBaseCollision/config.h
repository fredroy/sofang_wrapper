#pragma once

#include <sofa/component/collision/models/config.h>

#ifdef SOFA_BUILD_SOFABASECOLLISION
#  define SOFA_SOFABASECOLLISION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFABASECOLLISION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
