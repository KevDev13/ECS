#pragma once

#include <limits>	// used for UINT_MAX and USHRT_MAX. Can be removed if those are not needed below
#include <bitset>

namespace ecs
{
	// entity "class" and maximum number of entities
	using Entity = unsigned int;
	const Entity MAX_ENTITIES = 1000;
}