#pragma once

#include <sofa/component/mapping/config.h>

#ifdef SOFA_BUILD_SOFARIGID
#  define SOFA_SOFARIGID_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFARIGID_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
