#include <sofa/components/collision/config.h>

namespace sofa::components::collision
{

extern "C" {
	SOFACOMPONENTSCOLLISION_API void initExternalModule();
	SOFACOMPONENTSCOLLISION_API const char* getModuleName();
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

} // namespace sofa::components::collision
