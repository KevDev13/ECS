#pragma once

#include <bitset>
//#include <limits>

namespace ecs
{
	// component bits and maximum number of components
	using Component = unsigned short;
	const Component MAX_COMPONENTS = 1000;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;
}