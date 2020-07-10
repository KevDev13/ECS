#pragma once

#include <unordered_map>

#include "Component.hpp"
#include "Entity.hpp"

namespace ecs
{
	template <typename T>
	class ComponentList
	{
	public:
		ComponentList();
		~ComponentList();

	protected:
		std::array<T, MAX_COMPONENTS> m_components{};
		std::unordered_map<Entity, unsigned int> m_entityToComponentVector{};

		unsigned int m_numberOfComponents{};
	};
}