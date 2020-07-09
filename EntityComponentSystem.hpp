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
		void AddComponentToEntity(Entity id, std::shared_ptr<IComponent> component);
		bool AddEntityToSystem(Entity id, std::shared_ptr<ISystem> system);
		void RemoveComponentFromEntity(Entity id, std::shared_ptr<IComponent> component);
		void RemoveEntityFromSystem(Entity id, std::shared_ptr<IComponent> component);

		void Update();

	protected:
		std::unique_ptr<EntityList> m_entityList;
		std::list<std::unique_ptr<IComponent>> m_components{};
		std::list<std::unique_ptr<ISystem>> m_systems{};
	};
}