#pragma once

#include <bitset>
//#include <limits>

namespace ecs
{
	// component bits and maximum number of components
	const unsigned short MAX_COMPONENTS = 1000;
	using ComponentBits = std::bitset<MAX_COMPONENTS>;

	class IComponent
	{
	public:
		virtual inline bool SetComponentBit(unsigned short bit) { m_componentBit = bit; }
		virtual inline unsigned short GetComponentBit() const { return m_componentBit; }

	protected:
		unsigned short m_componentBit;
	};
}