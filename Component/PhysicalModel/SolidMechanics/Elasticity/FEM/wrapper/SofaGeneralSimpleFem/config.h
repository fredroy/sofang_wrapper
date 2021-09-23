#pragma once

#include <sofa/components/physicalmodel/solidmechanics/elasticity/fem/config.h>

#ifdef SOFA_BUILD_SOFAGENERALSIMPLEFEM
#  define SOFA_SOFAGENERALSIMPLEFEM_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAGENERALSIMPLEFEM_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
