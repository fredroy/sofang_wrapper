#include <sofa/component/collision/response/config.h>

namespace sofa::component::collision::response
{

extern "C" {
	SOFACOMPONENTCOLLISIONRESPONSE_API void initExternalModule();
	SOFACOMPONENTCOLLISIONRESPONSE_API const char* getModuleName();
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

} // namespace sofa::component::collision::response
