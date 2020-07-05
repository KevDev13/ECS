#include <limits>	// used for UINT_MAX and USHRT_MAX. Can be removed if those are not needed below
#include <bitset>

#pragma once

namespace ecs
{
	// entity "class" and maximum number of entities
	using Entity = unsigned int;
	const Entity MAX_ENTITIES = 1000;

	// component bits and maximum number of components
	const unsigned short MAX_COMPONENTS = USHRT_MAX;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;
}