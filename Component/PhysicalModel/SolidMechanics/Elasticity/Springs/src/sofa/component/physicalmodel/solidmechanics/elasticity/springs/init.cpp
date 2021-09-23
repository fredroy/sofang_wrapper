#include <sofa/component/physicalmodel/solidmechanics/elasticity/springs/config.h>

namespace sofa::component::physicalmodel::solidmechanics::elasticity::springs
{

extern "C" {
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_API const char* getModuleName();
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

} // namespace sofa::component::physicalmodel::solidmechanics::elasticity::springs
