#include <sofa/components/odesolver/config.h>

namespace sofa::components::odesolver
{
	
extern "C" {
    SOFACOMPONENTSODESOLVER_API void initExternalModule();
    SOFACOMPONENTSODESOLVER_API const char* getModuleName();
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

} // namespace sofa::components::odesolver
