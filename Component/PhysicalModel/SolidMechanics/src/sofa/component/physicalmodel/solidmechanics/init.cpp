#include <sofa/component/physicalmodel/solidmechanics/config.h>

namespace sofa::component::physicalmodel::solidmechanics
{

extern "C" {
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICS_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODELSOLIDMECHANICS_API const char* getModuleName();
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

} // namespace sofa::component::physicalmodel::solidmechanics
