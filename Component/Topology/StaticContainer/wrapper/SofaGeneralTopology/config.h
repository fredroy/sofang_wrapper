#pragma once

#include <sofa/component/topology/staticcontainer/config.h>

#ifdef SOFA_BUILD_SOFAGENERALTOPOLOGY
#  define SOFA_SOFAGENERALTOPOLOGY_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGENERALTOPOLOGY_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
