#pragma once

#include <sofa/components/physicalmodel/solidmechanics/elasticity/springs/config.h>

#ifdef SOFA_BUILD_SOFADEFORMABLE
#  define SOFA_SOFADEFORMABLE_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFADEFORMABLE_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
