#pragma once

#include <sofa/components/engine/config.h>

#ifdef SOFA_BUILD_SOFAMISCENGINE
#  define SOFA_SOFAMISCENGINE_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAMISCENGINE_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
