#include <sofa/ui/init.h>

namespace sofa::ui
{

extern "C" {
	SOFACOMPONENTUI_API void initExternalModule();
	SOFACOMPONENTUI_API const char* getModuleName();
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

} // namespace sofa::ui
