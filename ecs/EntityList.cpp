

#include "EntityList.hpp"

namespace ecs
{
	EntityList::EntityList()
	{
		for (Entity id = 0; id < MAX_ENTITIES; ++id)
		{
			m_availableEntities.push(id);
		}
	}

	EntityList::~EntityList()
	{

	}

	/*
	Creates a new entity and sets id to the new entity id. 
	Returns true if function was able to successfully create the new id, false otherwise.
	*/
	bool EntityList::CreateEntity(Entity& id)
	{
		// if the number of entities in use have already hit the max number we can have
		if (m_entitiesInUse.count() >= MAX_ENTITIES)
		{
			return false;
		}

		// get next available entity and remove from list of available entity ids
		id = m_availableEntities.front();
		m_availableEntities.pop();
		m_componentBits[id].reset();	// likely not needed but just in case

		m_entitiesInUse.set(id);		// set the entity in use

		return true;
	}

	/*
	Deletes the entity. Returns true if the id was valid, false otherwise.
	*/
	bool EntityList::DeleteEntity(Entity id)
	{
		// check if the entity exists or not
		if (id >= MAX_ENTITIES || !EntityExists(id))
		{
			return false;
		}

		m_componentBits[id].reset();	// reset component bits
		m_availableEntities.push(id);	// add the id to the list of available ids
		m_entitiesInUse.reset(id);		// set the bit to 0 to indicate the entity is no longer in use
	}
}