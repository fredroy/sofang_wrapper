#pragma once

#include <sofa/components/gui/core/config.h>

#ifdef SOFA_BUILD_SOFAGRAPHCOMPONENT
#  define SOFA_SOFAGRAPHCOMPONENT_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGRAPHCOMPONENT_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif