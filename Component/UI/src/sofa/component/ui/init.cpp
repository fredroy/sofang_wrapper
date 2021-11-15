#include <sofa/component/ui/config.h>

namespace sofa::component::ui
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
    SOFACOMPONENTUI_API void initExternalModule();
    SOFACOMPONENTUI_API const char* getModuleName();
}

void initExternalModule()
{
	init();
}

const char* getModuleName()
{
	return sofa::component::ui::MODULE_NAME;
}

} // namespace sofa::component::ui
