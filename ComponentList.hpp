#pragma once

#include <vector>

namespace ecs
{
	template <typename T>
	class ComponentList
	{
	public:
		ComponentList();
		~ComponentList();

	protected:
		std::vector<T> m_components;
	};
}