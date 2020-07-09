#include "EntityComponentSystem.hpp"

namespace ecs
{
	EntityComponentSystem::EntityComponentSystem()
	{
		m_entityList = std::make_unique<EntityList>();
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
			// throw an error or something here
		}
	}

	bool EntityComponentSystem::DeleteEntity(Entity id)
	{
		return m_entityList->DeleteEntity(id);
	}

	void EntityComponentSystem::Update()
	{
		// iterate through all systems and update them
		for (auto it = m_systems.begin(); it != m_systems.end(); ++it)
		{
			(*it)->Update();
		}
	}
}