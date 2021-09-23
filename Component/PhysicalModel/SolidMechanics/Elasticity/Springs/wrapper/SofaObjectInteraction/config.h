#pragma once

#include <sofa/components/physicalmodel/solidmechanics/elasticity/springs/config.h>

#ifdef SOFA_BUILD_SOFAOBJECTINTERACTION
#  define SOFA_SOFAOBJECTINTERACTION_API SOFA_EXPORT_DYNAMIC_LIBRARY
#else
#  define SOFA_SOFAOBJECTINTERACTION_API SOFA_IMPORT_DYNAMIC_LIBRARY
#endif
