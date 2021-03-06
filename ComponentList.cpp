#include "ComponentList.hpp"

namespace ecs
{
	template <typename T> bool ComponentList<T>::AddComponent(Entity id, T component)
	{
		// ensure entity doesn't have the component already
		if (m_entityToIndexMap.count(id) >= 1)
		{
			return false;
		}

		m_entityToIndexMap.insert({ id, m_numberOfComponents });
		m_components[m_numberOfComponents] = component;
		++m_numberOfComponents;

		return true;
	}

	template <typename T> bool ComponentList<T>::RemoveComponent(Entity id)
	{
		// ensure entity is in the array
		if (m_entityToIndexMap.count(id) == 0)
		{
			return false;
		}

		// take last entity in the array and move it to the index of the component we're removing
		// this removes the component from the array but keeps it packed
		int indexToRemove = m_entityToIndexMap[id];
		m_components[indexToRemove] = m_components[m_numberOfComponents];

		// update entity to array position map
		for (auto iter = m_entityToIndexMap.begin(); iter != m_entityToIndexMap.end(); ++iter)
		{
			if (iter->second == m_numberOfComponents)
			{
				m_entityToIndexMap[iter->first] = indexToRemove;
				break;
			}
		}

		--m_numberOfComponents;
		
		return true;
	}

	template <typename T> T& ComponentList<T>::GetData(Entity id)
	{
		// if entity has the component, get it and return a reference. Otherwise return nullptr.
		if (m_entityToIndexMap.count(id) >= 1)
		{
			return m_entityToIndexMap[id];
		}

		return nullptr;
	}
}