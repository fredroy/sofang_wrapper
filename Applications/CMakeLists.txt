cmake_minimum_required(VERSION 3.12)

get_property(BUILD_MINIMAL GLOBAL PROPERTY PROPERTY_SOFA_BUILD_MINIMAL SET)
if (NOT BUILD_MINIMAL)
	add_subdirectory(runSofa)
endif()
