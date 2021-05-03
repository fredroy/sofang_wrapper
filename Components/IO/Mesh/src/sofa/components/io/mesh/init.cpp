#include <sofa/components/io/mesh/config.h>

namespace sofa::components::io::mesh
{

extern "C" {
    SOFACOMPONENTSIOMESH_API void initExternalModule();
    SOFACOMPONENTSIOMESH_API const char* getModuleName();
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

} // namespace sofa::components::io::mesh
