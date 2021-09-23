#include <sofa/components/physicalmodel/mass/config.h>

namespace sofa::components::physicalmodel::mass
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODELMASS_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODELMASS_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel::mass
