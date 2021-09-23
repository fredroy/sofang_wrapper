#include <sofa/component/collision/detection/intersection/config.h>

namespace sofa::component::collision::detection::intersection
{
	
extern "C" {
    SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_API void initExternalModule();
    SOFACOMPONENTCOLLISIONDETECTIONINTERSECTION_API const char* getModuleName();
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

} // namespace sofa::component::collision::detection::intersection
