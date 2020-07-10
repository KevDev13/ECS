#pragma once

#include <unordered_map>

#include "Component.hpp"

namespace ecs
{
	class ComponentManager
	{
	public:
		template <typename T> bool AddComponent();

	protected:
		// map from typename to a single bit
		std::unordered_map<const char*, unsigned int> m_componentNameToBits{};
		unsigned int m_numberOfComponents{};
	};
}