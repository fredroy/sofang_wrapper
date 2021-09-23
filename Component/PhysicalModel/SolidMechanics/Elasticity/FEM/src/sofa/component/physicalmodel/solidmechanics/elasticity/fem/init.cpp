#include <sofa/component/physicalmodel/solidmechanics/elasticity/fem/config.h>

namespace sofa::component::physicalmodel::solidmechanics::elasticity::fem
{

extern "C" {
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_API const char* getModuleName();
}

void initExternalModule()
{
	static bool first = true;
	if (first)
	{
		first = false;
	}
}

const char* getModuleName()
{
	return MODULE_NAME;
}

} // namespace sofa::component::physicalmodel::solidmechanics::elasticity::fem
