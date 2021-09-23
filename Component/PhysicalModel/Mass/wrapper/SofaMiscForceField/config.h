#pragma once

#include <sofa/component/physicalmodel/mass/config.h>

#ifdef SOFA_BUILD_SOFAMISCFORCEFIELD
#  define SOFA_SOFAMISCFORCEFIELD_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAMISCFORCEFIELD_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
