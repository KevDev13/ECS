

#pragma once

#include <set>

#include "Entity.hpp"

namespace ecs
{
	class ISystem
	{
	public:
		virtual void Run() = 0;

	protected:
		std::set<Entity> m_entities;
	};
}