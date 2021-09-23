#include <sofa/component/physicalmodel/config.h>

namespace sofa::component::physicalmodel
{

extern "C" {
	SOFACOMPONENTPHYSICALMODEL_API void initExternalModule();
	SOFACOMPONENTPHYSICALMODEL_API const char* getModuleName();
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

} // namespace sofa::component::physicalmodel
