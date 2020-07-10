#include "EntityComponentSystem.hpp"

namespace ecs
{
	EntityComponentSystem::EntityComponentSystem()
	{
		m_entityList = std::make_unique<EntityList>();
		m_componentManager = std::make_unique<ComponentManager>();
	}

	EntityComponentSystem::~EntityComponentSystem() {}

	Entity EntityComponentSystem::CreateEntity()
	{
		Entity id = 0;
		if (m_entityList->CreateEntity(id))
		{
			return id;
		}
		else
		{
			// TODO: throw an error or something here instead of still returning id
			return id;
		}
	}

	bool EntityComponentSystem::DeleteEntity(Entity id)
	{
		// TODO: remove entity from any systems it is in. Do this after creating SystemList class if needed
		return m_entityList->DeleteEntity(id);
	}

	template <typename T> bool EntityComponentSystem::RegisterComponent()
	{
		return m_componentManager->AddComponent<T>();
	}
}