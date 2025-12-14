#include "GameEngine.h"

GameEngine::GameEngine(const std::string& config) {
	init(config);
}

void GameEngine::init(const std::string& config) {
	//create window
	//load assets
	//load scenes
}

void GameEngine::run() {
	std::cout << "Game Engine Running..." << std::endl;
	while (m_running) {
		sUserInput();
		//update current scene
		//render current scene
	}
}

void GameEngine::sUserInput()
{

}

AssetManager& GameEngine::getAssetManager() {
	return m_assetManager;
}
sf::RenderWindow& GameEngine::getWindow() {
	return m_window;
}

Scene& GameEngine::getCurrentScene() {
	return m_scenes.at(m_currentScene);
}