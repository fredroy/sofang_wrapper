#include <sofa/components/collision/detection/algorithm/config.h>

namespace sofa::components::collision::detection::algorithm
{
	
extern "C" {
    SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_API void initExternalModule();
    SOFACOMPONENTSCOLLISIONDETECTIONALGORITHM_API const char* getModuleName();
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

} // namespace sofa::components::collision::detection::algorithm
