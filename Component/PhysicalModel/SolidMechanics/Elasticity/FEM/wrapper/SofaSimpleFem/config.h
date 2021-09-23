#pragma once

#include <sofa/component/physicalmodel/solidmechanics/elasticity/fem/config.h>

#ifdef SOFA_BUILD_SOFASIMPLEFEM
#  define SOFA_SOFASIMPLEFEM_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFASIMPLEFEM_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
