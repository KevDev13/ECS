#pragma once

#include <list>
#include <memory>

#include "Component.hpp"
#include "ComponentList.hpp"
#include "ComponentManager.hpp"
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
		template <typename T> bool RegisterComponent();
		template <typename T> bool RegisterSystem();

		template <typename T> std::shared_ptr<T> GetSystem() const;

		template <typename T> void AddComponentToEntity(Entity id);
		template <typename T> void AddComponentToEntity(Entity id, T component);
		template <typename T> bool AddEntityToSystem(Entity id);
		template <typename T> void RemoveComponentFromEntity(Entity id);
		template <typename T> void RemoveEntityFromSystem(Entity id);

	protected:
		std::unique_ptr<EntityList> m_entityList;
		std::unique_ptr<ComponentManager> m_componentManager;
		// TODO: add SystemList/SystemManager class
	};
}