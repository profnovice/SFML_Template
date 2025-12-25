#include "Scene.h"

Scene::Scene(AssetManager& manager)
	:m_assetManager(manager), m_entityManager(), m_uiManager()
{}

void Scene::registerAction(sf::Keyboard::Scancode code, std::string name)
{
	m_inputMap[code] = name;
}

const InputMap& Scene::getInputMap() const 
{
	return m_inputMap;
}