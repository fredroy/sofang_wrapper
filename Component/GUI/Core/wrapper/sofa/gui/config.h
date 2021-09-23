#pragma once

#include <sofa/component/gui/core/config.h>

#ifdef SOFA_BUILD_SOFAGUICOMMON
#  define SOFA_SOFAGUICOMMON_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGUICOMMON_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
