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

		bool AddComponent(Entity id, T component);
		bool RemoveComponent(Entity id);

		T& GetData(Entity id);

	protected:
		std::array<T, MAX_COMPONENTS> m_components{};
		std::unordered_map<Entity, unsigned int> m_entityToIndexMap{};

		unsigned int m_numberOfComponents{};
	};
}