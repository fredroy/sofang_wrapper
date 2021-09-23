#include <sofa/components/physicalmodel/solidmechanics/config.h>

namespace sofa::components::physicalmodel::solidmechanics
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICS_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODELSOLIDMECHANICS_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel::solidmechanics
