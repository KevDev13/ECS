#pragma once

#include <bitset>
//#include <limits>

namespace ecs
{
	namespace ComponentInternal
	{
		using ComponentType = unsigned short;
	}

	// component bits and maximum number of components
	const ComponentInternal::ComponentType MAX_COMPONENTS = 1000;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;

	class IComponent
	{
	public:
		virtual inline bool SetComponentBit(ComponentInternal::ComponentType bit) { m_componentBit = bit; }
		virtual inline ComponentInternal::ComponentType GetComponentBit() const { return m_componentBit; }

	protected:
		ComponentInternal::ComponentType m_componentBit;
	};
}