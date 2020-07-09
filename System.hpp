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
		virtual void Update()
		{
			if (m_systemShouldRun)
			{
				Run();
			}
		}

		virtual bool AddEntity(Entity id)
		{
			return true;
		}

		virtual void RemoveEntity(Entity id)
		{

		}

		virtual inline void SetRequiredComponents(ComponentBits components) { m_requiredComponents = components; }
		virtual inline void AddRequiredComponent(std::shared_ptr<IComponent> component) { m_requiredComponents.set(component->GetComponentBit()); }
		virtual inline void ResetRequiredComponents() { m_requiredComponents.reset(); }
		virtual inline void SetShouldRun(bool run) { m_systemShouldRun = run; }

		virtual inline ComponentBits GetRequiredComponents() const { return m_requiredComponents; }
		virtual inline bool WillRun() const { return m_systemShouldRun; }
		
	protected:
		ComponentBits m_requiredComponents{};
		std::vector<Entity> m_entities{};
		bool m_systemShouldRun;

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

		virtual void Run() = 0;
	};
}