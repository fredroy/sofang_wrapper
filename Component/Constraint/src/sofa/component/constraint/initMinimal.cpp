#include <sofa/component/constraint/config.h>

namespace sofa::component::constraint
{

extern "C" {
	SOFACOMPONENTCONSTRAINT_API void initExternalModule();
	SOFACOMPONENTCONSTRAINT_API const char* getModuleName();
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

} // namespace sofa::component::constraint
