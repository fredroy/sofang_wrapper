#pragma once

#include <sofa/component/topology/dynamiccontainer/config.h>

#ifdef SOFA_BUILD_SOFANONUNIFORMFEM
#  define SOFA_SOFANONUNIFORMFEM_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFANONUNIFORMFEM_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
