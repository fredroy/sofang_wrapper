#include <sofa/components/animationloop/config.h>

namespace sofa::components::animationloop
{
	
extern "C" {
    SOFACOMPONENTSANIMATIONLOOP_API void initExternalModule();
    SOFACOMPONENTSANIMATIONLOOP_API const char* getModuleName();
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

} // namespace sofa::components::animationloop
