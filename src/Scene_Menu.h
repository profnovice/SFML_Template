#include "Scene.h"

class Scene_Menu : public Scene {

	void update();
	void sDoAction(Action& action);
	void sRender(sf::RenderWindow& window);

};