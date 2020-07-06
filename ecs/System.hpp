#pragma once

#include <set>
#include <bitset>

#include "Entity.hpp"
#include "Component.hpp"

namespace ecs
{
	class ISystem
	{
	public:
		virtual void Update() = 0;

	protected:
		std::bitset<MAX_COMPONENTS> m_requiredComponents;
	};
}