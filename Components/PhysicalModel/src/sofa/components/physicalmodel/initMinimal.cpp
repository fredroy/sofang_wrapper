#include <sofa/components/physicalmodel/config.h>

namespace sofa::components::physicalmodel
{

extern "C" {
	SOFACOMPONENTSPHYSICALMODEL_API void initExternalModule();
	SOFACOMPONENTSPHYSICALMODEL_API const char* getModuleName();
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

} // namespace sofa::components::physicalmodel
