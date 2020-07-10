#include <type_traits>

#include "ComponentManager.hpp"

namespace ecs
{
	template <typename T> bool ComponentManager::AddComponent()
	{
		// ensure the component inherits from the component interface class
		if (!std::is_base_of<IComponent, T>::value)
		{
			return false;
		}

		// if component is already registered
		if (m_componentNameToBits.count(typeid(T).name()) >= 1)
		{
			return false;
		}

		// add component to map of bits
		m_componentNameToBits.insert({ typeid(T).name() , m_numberOfComponents });
		++m_numberOfComponents;

		return true;
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