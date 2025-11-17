#include <SFML/Graphics.hpp>
#include <memory>
#include "Components.h"
#pragma once
class SimpleEntity
{
	const size_t m_id;
	const std::string & m_tag;
	bool m_alive;
public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<std::string>cName;
	std::shared_ptr<sf::RectangleShape> cShape;

	SimpleEntity(size_t, const std::string &);


};