#pragma once

#include <sofa/components/mapping/config.h>

#ifdef SOFA_BUILD_SOFAGENERALRIGID
#  define SOFA_SOFAGENERALRIGID_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGENERALRIGID_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif