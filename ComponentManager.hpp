#pragma once

#include <unordered_map>
#include <memory>

#include "Component.hpp"
#include "ComponentList.hpp"

namespace ecs
{
	class ComponentManager
	{
	public:
		template <typename T> bool AddComponentType();
		template <typename T> void AddComponentToEntity(Entity id);
		template <typename T> void AddComponentToEntity(Entity id, T component);
		template <typename T> bool RemoveComponentFromEntity(Entity id);
		
		template <typename T> int GetComponentBit() const;

	protected:
		// map from typename to a single bit
		std::unordered_map<const char*, Component> m_componentNameToBits{};
		// map of all component lists, one list for each component type
		std::unordered_map<const char*, std::shared_ptr<IComponentList>> m_componentLists{};
		// total number of components
		Component m_numberOfComponents{};
	};
}