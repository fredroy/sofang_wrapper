#include <sofa/components/constraint/config.h>

namespace sofa::components::constraint
{

extern "C" {
	SOFACOMPONENTSCONSTRAINT_API void initExternalModule();
	SOFACOMPONENTSCONSTRAINT_API const char* getModuleName();
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

} // namespace sofa::components::constraint
