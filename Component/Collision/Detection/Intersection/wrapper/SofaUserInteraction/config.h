#pragma once

#include <sofa/component/collision/detection/intersection/config.h>

#ifdef SOFA_BUILD_SOFAUSERINTERACTION
#  define SOFA_SOFAUSERINTERACTION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAUSERINTERACTION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
