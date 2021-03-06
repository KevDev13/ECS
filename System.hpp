#pragma once

#include <set>
#include <bitset>
#include <vector>
#include <memory>

#include "Entity.hpp"
#include "Component.hpp"

namespace ecs
{
	class ISystem
	{
	public:
		virtual void Update() = 0;

		virtual bool AddEntity(Entity id, ComponentBits components)
		{
			if (!EntityHasRequiredComponents(components))
			{
				return false;
			}

			m_entities.push_back(id);

			return true;
		}

		virtual void RemoveEntity(Entity id)
		{
			for (auto iter = m_entities.begin(); iter != m_entities.end(); ++iter)
			{
				if (*iter == id)
				{
					m_entities.erase(iter);
					break;
				}
			}
		}

		virtual inline void SetRequiredComponents(ComponentBits components) { m_requiredComponents = components; }
		virtual inline void AddRequiredComponent(Component bit) { m_requiredComponents.set(bit); }
		virtual inline void ResetRequiredComponents() { m_requiredComponents.reset(); }

		virtual inline ComponentBits GetRequiredComponents() const { return m_requiredComponents; }
		
	protected:
		ComponentBits m_requiredComponents{};
		std::vector<Entity> m_entities{};

		virtual bool EntityHasRequiredComponents(ComponentBits testComponents) const
		{
			/*
			bitwise AND the test components to the required components.
			This will 0 out any bit that is either a) not required or b) required but not present, meaning only required bits that are present will be 1
			at that point. Then, we can get the count of bits that are set. Since only bits that are required will be set, if count() from the result is the same
			as count() in the required components bitset, we know that the component bits being tested have the required components.
			*/
			ComponentBits result = m_requiredComponents & testComponents;
			return result.count() == m_requiredComponents.count();
		}
	};
}