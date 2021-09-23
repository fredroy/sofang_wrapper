#include <sofa/component/collision/detection/algorithm/config.h>

namespace sofa::component::collision::detection::algorithm
{
	
extern "C" {
    SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_API void initExternalModule();
    SOFACOMPONENTCOLLISIONDETECTIONALGORITHM_API const char* getModuleName();
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

} // namespace sofa::component::collision::detection::algorithm
