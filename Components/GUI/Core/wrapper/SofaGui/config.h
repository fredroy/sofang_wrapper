#pragma once

#include <sofa/components/gui/core/config.h>

#ifdef SOFA_BUILD_SOFAGUI
#  define SOFA_SOFAGUI_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGUI_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
