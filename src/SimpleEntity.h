#include <SFML/Graphics.hpp>
#include <memory>
#include "Components.h"
#pragma once
class SimpleEntity
{
public:
	std::shared_ptr<int>cID;
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<std::string>cName;
	std::shared_ptr<sf::RectangleShape> cShape;

	SimpleEntity();


};