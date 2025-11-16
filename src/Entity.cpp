#include "Entity.h"

	

Entity::Entity(int entityID, sf::CircleShape & shape)
	:m_entityID(entityID), m_shape(shape)
{
	m_position = Vec2(shape.getPosition().x, shape.getPosition().y);
}



void Entity::setShape(sf::CircleShape & shape)
{
	m_shape = shape;
	m_position = Vec2(shape.getPosition().x, shape.getPosition().y);

}

void Entity::setVecPosition(const Vec2 position)
{
	m_position = position;
	m_shape.setPosition({ m_position.x, m_position.y });
}

void Entity::addComponent(Component inComponent)
{
	m_components.push_back(inComponent);
}

bool Entity::getComponent(Component & inComponent)
{
	for (Component c : m_components) {
		if (typeid(c) == typeid(inComponent)) {
			inComponent = c;
			return true;
		}
	}
	return false;
}

const Vec2 Entity::getVecPosition()
{
	return m_position;
}

sf::CircleShape & Entity::getShape()
{
	return m_shape;
}
