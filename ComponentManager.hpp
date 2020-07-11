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
		std::unordered_map<const char*, unsigned int> m_componentNameToBits{};
		// map of all component lists, one list for each component type
		std::unordered_map<const char*, std::shared_ptr<IComponentList>> m_componentLists{};
		unsigned int m_numberOfComponents{};

		// internal function to check if the component type is registered
		// using checkRegistered = true will verify that that the component type has been registered
		// using checkRegistered = false will verify that the componeny type has NOT been registed (i.e. return false if the type has already been registered
		template <typename T> bool ComponentTypeValid(bool checkRegistered) const;
		static const bool CHECK_REGISTERED = true;
		static const bool CHECK_NOT_REGISTERED = false;
	};
}