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
		template <typename T> bool AddComponent();
		template <typename T> bool RemoveComponent();
		
		template <typename T> int GetComponentBit() const;

	protected:
		// map from typename to a single bit
		std::unordered_map<const char*, unsigned int> m_componentNameToBits{};
		// map of all component lists, one list for each component type
		std::unordered_map<const char*, std::shared_ptr<IComponentList>> m_componentLists{};
		unsigned int m_numberOfComponents{};
	};
}