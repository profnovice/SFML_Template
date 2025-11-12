#include "Entity.h"

	
Entity::Entity(int entityID)
	:m_entityID(entityID)
{
	
}



void Entity::setVecPosition(const Vec2 position)
{
	m_position = position;
}

const Vec2 Entity::getVecPosition()
{
	return m_position;
}
