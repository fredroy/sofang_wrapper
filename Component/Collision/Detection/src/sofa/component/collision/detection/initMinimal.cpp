#include <sofa/component/collision/detection/config.h>

namespace sofa::component::collision::detection
{

extern "C" {
	SOFACOMPONENTCOLLISIONDETECTION_API void initExternalModule();
	SOFACOMPONENTCOLLISIONDETECTION_API const char* getModuleName();
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

} // namespace sofa::component::collision::detection
