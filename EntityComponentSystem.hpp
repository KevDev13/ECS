#pragma once

#include <list>
#include <memory>

#include "Component.hpp"
#include "Entity.hpp"
#include "EntityList.hpp"
#include "System.hpp"

namespace ecs
{
	class EntityComponentSystem
	{
	public:
		EntityComponentSystem();
		~EntityComponentSystem();

		Entity CreateEntity();
		bool DeleteEntity(Entity id);
		template <typename T> void RegisterComponent();
		template <typename T> std::shared_ptr<T> RegisterSystem();

		template <typename T> void AddComponentToEntity(Entity id);
		template <typename T> bool AddEntityToSystem(Entity id);
		template <typename T> void RemoveComponentFromEntity(Entity id);
		template <typename T> void RemoveEntityFromSystem(Entity id);

	protected:
		std::unique_ptr<EntityList> m_entityList;
		// TODO: replace these with ComponentList and SystemList classes
		std::list<std::unique_ptr<IComponent>> m_components{};
		std::list<std::unique_ptr<ISystem>> m_systems{};
	};
}