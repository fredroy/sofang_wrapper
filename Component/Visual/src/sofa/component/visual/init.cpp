#include <sofa/components/visual/config.h>

namespace sofa::components::visual
{

extern "C" {
    SOFACOMPONENTSVISUAL_API void initExternalModule();
    SOFACOMPONENTSVISUAL_API const char* getModuleName();
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

} // namespace sofa::components::visual
