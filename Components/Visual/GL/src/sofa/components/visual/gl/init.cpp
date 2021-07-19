#include <sofa/components/visual/gl/config.h>

namespace sofa::component::visual::gl
{

extern "C" {
    SOFACOMPONENTSVISUALGL_API void initExternalModule();
    SOFACOMPONENTSVISUALGL_API const char* getModuleName();
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

} // namespace sofa::component::visual::gl
