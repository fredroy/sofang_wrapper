#pragma once

#include <sofa/component/engine/config.h>

#ifdef SOFA_BUILD_SOFAENGINE
#  define SOFA_SOFAENGINE_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAENGINE_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
