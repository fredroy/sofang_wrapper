#include <sofa/components/io/config.h>

namespace sofa::components::io
{

extern "C" {
    SOFACOMPONENTSIO_API void initExternalModule();
    SOFACOMPONENTSIO_API const char* getModuleName();
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

} // namespace sofa::components::io
