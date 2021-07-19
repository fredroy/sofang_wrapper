#include <sofa/components/utils/config.h>

namespace sofa::components::utils
{

void init()
{
	static bool first = true;
	if (first)
	{
		first = false;
	}
}

extern "C" {
    SOFACOMPONENTSUTILS_API void initExternalModule();
    SOFACOMPONENTSUTILS_API const char* getModuleName();
}

void initExternalModule()
{
	init();
}

const char* getModuleName()
{
	return sofa::components::utils::MODULE_NAME;
}

} // namespace sofa::components::utils
