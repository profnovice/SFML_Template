#include "EntityManager.h"

/*
	EntityVec m_entities;
	EntityMap m_entityMap;
	size_t m_totalEntities = 0;
	size_t m_uniqueIdIndex = 0;

*/

bool is_Dead(const SimpEntPtr e)
{
	return !e->m_alive;
}


EntityManager::EntityManager()
	:m_queueToAdd(), m_entities(), m_entityMap()
	//:m_entities(std::make_shared<std::vector<SimpleEntity>>())
{
}

SimpEntPtr EntityManager::addEntity(const std::string & tag)
{
	//create a new entity obj
	SimpEntPtr e = std::make_shared<SimpleEntity>(m_uniqueIdIndex++, tag); m_totalEntities++;
	
	m_queueToAdd.push_back(e);
	//return shared ptr of new entity

	return e;
}

EntityVec EntityManager::getAllEntities()
{
	return m_entities;
}

EntityVec EntityManager::getEntitiesWithTag(std::string tag)
{
	return m_entityMap[tag];
}

void EntityManager::update()
{

	
	//for (auto& tag : m_entityMap)
	//{
	//	std::remove_if(tag begin(), m_entities.end(), is_Dead);

	//}
	
	for (auto e : m_queueToAdd)
	{//store in all entities vec
		m_entities.push_back(e);
		//store in map of tag->entityvector
		//std::cout << "Tag: " << e->m_tag << std::endl;
		m_entityMap[e->m_tag].push_back(e);

	}
	const auto deadEnd = std::remove_if(m_entities.begin(), m_entities.end(), is_Dead);
	m_entities.erase(deadEnd, m_entities.end());
	//for (auto& e : m_entities)
	{
		//std::cout << "ID: " << e->m_id << std::endl;

	}
	m_queueToAdd.clear();
	
}
