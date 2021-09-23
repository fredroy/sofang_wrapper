#include <sofa/components/physicalmodel/solidmechanics/elasticity/config.h>

namespace sofa::components::physicalmodel::solidmechanics::elasticity
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITY_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITY_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel::solidmechanics::elasticity
