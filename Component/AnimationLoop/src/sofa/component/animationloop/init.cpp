#include <sofa/component/animationloop/config.h>

namespace sofa::component::animationloop
{
	
extern "C" {
    SOFACOMPONENTANIMATIONLOOP_API void initExternalModule();
    SOFACOMPONENTANIMATIONLOOP_API const char* getModuleName();
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

} // namespace sofa::component::animationloop
