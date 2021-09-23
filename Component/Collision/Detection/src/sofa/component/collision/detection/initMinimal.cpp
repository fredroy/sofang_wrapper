#include <sofa/components/collision/detection/config.h>

namespace sofa::components::collision::detection
{

extern "C" {
	SOFACOMPONENTSCOLLISIONDETECTION_API void initExternalModule();
	SOFACOMPONENTSCOLLISIONDETECTION_API const char* getModuleName();
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

} // namespace sofa::components::collision::detection
