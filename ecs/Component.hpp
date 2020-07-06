#pragma once

#include <bitset>

namespace ecs
{
	// component bits and maximum number of components
	const unsigned short MAX_COMPONENTS = USHRT_MAX;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;

	class IComponent
	{

	};
}