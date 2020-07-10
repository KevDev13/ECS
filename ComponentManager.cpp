#include <type_traits>

#include "ComponentManager.hpp"

namespace ecs
{
	template <typename T> bool ComponentManager::AddComponentType()
	{
		if (!ComponentTypeValid<T>(CHECK_NOT_REGISTERED))
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

	template <typename T> bool ComponentManager::AddComponentToEntity(Entity id)
	{

	}

	template <typename T> bool ComponentManager::RemoveComponentFromEntity(Entity id)
	{

	}

	template <typename T> int ComponentManager::GetComponentBit() const
	{
		if (!ComponentTypeValid<T>(CHECK_REGISTERED))
		{
			return -1;
		}

		return m_componentNameToBits[typeid(T).name()];
	}

	template <typename T> bool ComponentManager::ComponentTypeValid(bool checkRegistered) const
	{
		// ensure the component inherits from the component interface class
		if (!std::is_base_of<IComponent, T>::value)
		{
			return false;
		}

		const char* name = typeid(T).name();

		// verify if componenet type has been registered or not, depending on what we're checking
		if (checkRegistered && m_componentNameToBits.count(name) == 0)
		{
			return false;
		}

		if (!checkRegistered && m_componentNameToBits.count(name) >= 1)
		{
			return false;
		}

		return true;
	}
}