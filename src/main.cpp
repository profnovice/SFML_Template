#include <SFML/Graphics.hpp>//Simple Fast Multi-media Library
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "Entity.h"
#include "Vec2.h"
#include "Components.h"
#include "SimpleEntity.h"
#include "EntityManager.h"
#include "Game.h"


template <typename T>
T custom_lerp(T a, T b, T t) {
    return a + t * (b - a);
}

int main()
{
    std::string config = std::string("assets/config.txt");
    Game game(config);
    game.run();    
    return 0;
}
