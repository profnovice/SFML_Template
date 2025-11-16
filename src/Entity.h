#include <SFML/Graphics.hpp>
#include "Vec2.h"
#include "Components.h"

#pragma once
class Entity 
{
	const int m_entityID;
	sf::CircleShape & m_shape;
	Vec2 m_position;
	std::vector<Component> m_components;


public:


	Entity(int,sf::CircleShape&);

	//mutators
	void setShape(sf::CircleShape&);

	void setVecPosition(Vec2);

	void addComponent(Component);
	bool getComponent( Component &);

	const Vec2 getVecPosition();
	
	sf::CircleShape& getShape();



};

