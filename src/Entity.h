#include "Vec2.h"
#pragma once
class Entity 
{
	const int m_entityID;
	Vec2 m_position;


public:

	Entity(int);

	//mutators
	void setVecPosition(Vec2);


	const Vec2 getVecPosition();


};

