#include <sofa/component/init.h>

namespace sofa::component
{

extern "C" {
	SOFACOMPONENT_API void initExternalModule();
	SOFACOMPONENT_API const char* getModuleName();
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

} // namespace sofa::component
