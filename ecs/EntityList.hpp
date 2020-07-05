

#pragma once

#include <array>
#include <queue>

#include "Entity.hpp"

namespace ecs
{
	class EntityList
	{
	public:
		EntityList();
		~EntityList();

		bool CreateEntity(Entity& id);
		bool DeleteEntity(Entity id);
		inline void SetEntityComponents(Entity id, ComponentBits bits) { m_componentBits[id] = bits; }
		inline ComponentBits GetEntityComponents(Entity id) const { return m_componentBits[id]; }
		inline bool EntityExists(Entity id) const { return m_entitiesInUse.test(id); }

	protected:
		// array to map component bitset to each entity
		std::array<ComponentBits, MAX_ENTITIES> m_componentBits{};

		// array holding available ids
		std::queue<Entity> m_availableEntities{};

		// bitset of entities in use. This is somewhat redundant with the above array,
		// but I'm sacrificing additional memory size for speed of determining if an entity is in use
		std::bitset<MAX_ENTITIES> m_entitiesInUse{};
	};
}