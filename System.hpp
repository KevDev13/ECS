#pragma once

#include <set>
#include <bitset>
#include <vector>

#include "Entity.hpp"
#include "Component.hpp"

namespace ecs
{
	class ISystem
	{
	public:
		virtual void Update() = 0;

		void AddEntity(Entity id)
		{
			
		}

		void RemoveEntity(Entity id)
		{

		}
		inline void SetRequiredComponents(ComponentBits components) { m_requiredComponents = components; }

		inline ComponentBits GetRequiredComponents() const { return m_requiredComponents; }
		
	protected:
		ComponentBits m_requiredComponents;
		std::vector<Entity> m_entities;

		bool EntityHasRequiredComponents(ComponentBits testComponents) const
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