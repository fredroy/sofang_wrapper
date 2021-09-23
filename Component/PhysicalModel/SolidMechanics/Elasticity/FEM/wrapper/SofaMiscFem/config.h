#pragma once

#include <sofa/component/physicalmodel/solidmechanics/elasticity/fem/config.h>

#ifdef SOFA_BUILD_SOFAMISCFEM
#  define SOFA_SOFAMISCFEM_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAMISCFEM_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
