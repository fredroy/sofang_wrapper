#include <sofa/component/physicalmodel/solidmechanics/elasticity/config.h>

namespace sofa::component::physicalmodel::solidmechanics::elasticity
{

extern "C" {
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITY_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITY_API const char* getModuleName();
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

} // namespace sofa::component::physicalmodel::solidmechanics::elasticity
