#pragma once

#include <bitset>
//#include <limits>

namespace ecs
{
	namespace Component
	{
		using ComponentType = unsigned short;
	}

	// component bits and maximum number of components
	const Component::ComponentType MAX_COMPONENTS = 1000;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;

	class IComponent
	{
	public:
		inline bool SetComponentBit(Component::ComponentType bit) { m_componentBit = bit; }
		inline Component::ComponentType GetComponentBit() const { return m_componentBit; }
	protected:
		Component::ComponentType m_componentBit;
	};
}