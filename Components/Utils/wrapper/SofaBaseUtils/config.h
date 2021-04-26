#pragma once

#include <sofa/components/utils/config.h>

#ifdef SOFA_BUILD_SOFABASEUTILS
#  define SOFA_SOFABASEUTILS_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFABASEUTILS_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
