#include <ioStream>
#include "Vec2.h"

#pragma once
class Component {};

class CTransform : public  Component
{
public:
	Vec2 pos;
	Vec2 velocity;
	CTransform();
	CTransform(const Vec2, const Vec2);
	~CTransform();
	void print();
};