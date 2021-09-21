#include <sofa/components/physicalmodel/solidmechanics/elasticity/fem/config.h>

namespace sofa::components::physicalmodel::solidmechanics::elasticity::fem
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYFEM_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel::solidmechanics::elasticity::fem
