#include <sofa/components/physicalmodel/solidmechanics/elasticity/springs/config.h>

namespace sofa::components::physicalmodel::solidmechanics::elasticity::springs
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICSELASTICITYSPRINGS_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel::solidmechanics::elasticity::springs
