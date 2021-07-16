#include <sofa/components/collision/detection/intersection/config.h>

namespace sofa::components::collision::detection::intersection
{
	
extern "C" {
    SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_API void initExternalModule();
    SOFACOMPONENTSCOLLISIONDETECTIONINTERSECTION_API const char* getModuleName();
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

} // namespace sofa::components::collision::detection::intersection
