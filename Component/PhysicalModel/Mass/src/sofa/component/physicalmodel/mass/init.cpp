#include <sofa/component/physicalmodel/mass/config.h>

namespace sofa::component::physicalmodel::mass
{

extern "C" {
	SOFACOMPONENTPHYSICALMODELMASS_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODELMASS_API const char* getModuleName();
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

} // namespace sofa::component::physicalmodel::mass
