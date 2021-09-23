#include <sofa/component/collision/config.h>

namespace sofa::component::collision
{

extern "C" {
	SOFACOMPONENTCOLLISION_API void initExternalModule();
	SOFACOMPONENTCOLLISION_API const char* getModuleName();
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

} // namespace sofa::component::collision
