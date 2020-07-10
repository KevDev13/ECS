#pragma once

#include <unordered_map>

#include "Component.hpp"
#include "Entity.hpp"

namespace ecs
{
	class IComponentList
	{
	public:
		virtual bool RemoveComponent(Entity id) = 0;
	};

	template <typename T>
	class ComponentList : public IComponentList
	{
	public:
		ComponentList();
		~ComponentList();

		bool AddComponent(Entity id, T component);
		bool RemoveComponent(Entity id) override;

		T& GetData(Entity id);

	protected:
		std::array<T, MAX_COMPONENTS> m_components{};
		std::unordered_map<Entity, unsigned int> m_entityToIndexMap{};

		unsigned int m_numberOfComponents{};
	};
}