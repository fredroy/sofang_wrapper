#include <sofa/component/utils/config.h>

namespace sofa::component::utils
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
    SOFACOMPONENTUTILS_API void initExternalModule();
    SOFACOMPONENTUTILS_API const char* getModuleName();
}

void initExternalModule()
{
	init();
}

const char* getModuleName()
{
	return sofa::component::utils::MODULE_NAME;
}

} // namespace sofa::component::utils
