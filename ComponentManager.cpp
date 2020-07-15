#include <type_traits>

#include "ComponentManager.hpp"

namespace ecs
{
	template <typename T> bool ComponentManager::AddComponentType()
	{
		// if component is already registered, return false
		if (m_componentNameToBits.count(typeid(T).name()) >= 1)
		{
			return false;
		}

		// add component to map of bits
		m_componentNameToBits.insert({ typeid(T).name() , m_numberOfComponents });
		++m_numberOfComponents;

		// add component to component lists
		m_componentLists.insert({ typeid(T).name(), std::make_shared<ComponentList<T>> });

		return true;
	}

	template <typename T> void ComponentManager::AddComponentToEntity(Entity id)
	{
		const char* name = typeid(T).name();
		// if component isn't registered, return without doing anything
		if (m_componentNameToBits.count(name) == 0)
		{
			return;
		} 

		// cast component list of the given type to a ComponentList (from IComponentList), then add the component to it
		std::shared_ptr<ComponentList<T>> compList = std::dynamic_pointer_cast<ComponentList<T>>(m_componentLists[name]);
		compList->AddComponent(id, T());
	}

	template <typename T> void ComponentManager::AddComponentToEntity(Entity id, T component)
	{
		const char* name = typeid(T).name();
		// if component isn't registered, return without doing anything
		if (m_componentNameToBits.count(name) == 0)
		{
			return;
		}

		// cast component list of the given type to a ComponentList (from IComponentList), then add the component to it
		std::shared_ptr<ComponentList<T>> compList = std::dynamic_pointer_cast<ComponentList<T>>(m_componentLists[name]);
		compList->AddComponent(id, component);
	}

	template <typename T> bool ComponentManager::RemoveComponentFromEntity(Entity id)
	{

	}

	template <typename T> int ComponentManager::GetComponentBit() const
	{
		// if component isn't registered, return -1
		if (m_componentNameToBits.count(typeid(T).name()) == 0)
		{
			return -1;
		}

		return m_componentNameToBits[typeid(T).name()];
	}
}