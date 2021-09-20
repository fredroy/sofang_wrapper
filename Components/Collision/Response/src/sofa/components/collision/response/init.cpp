#include <sofa/components/collision/response/config.h>

namespace sofa::components::collision::response
{

extern "C" {
	SOFACOMPONENTSCOLLISIONRESPONSE_API void initExternalModule();
	SOFACOMPONENTSCOLLISIONRESPONSE_API const char* getModuleName();
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

} // namespace sofa::components::collision::response
