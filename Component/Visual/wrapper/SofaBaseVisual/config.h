#pragma once

#include <sofa/component/visual/config.h>

#ifdef SOFA_BUILD_SOFABASEVISUAL
#  define SOFA_SOFABASEVISUAL_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFABASEVISUAL_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
