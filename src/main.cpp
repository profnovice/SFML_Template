#include <SFML/Graphics.hpp>//Simple Fast Multi-media Library
#include <fstream>


/*
std::string
std::vector
std::map
*/

/*
//definition
class Entity
{

    const int m_entityID;
    float m_scale;

public:
    Entity(int entityID)
        :m_entityID(entityID) // Initializer lists
    {


    }
    void setScale(float scale)
    {
        m_scale = scale;
    }
    const int getEntityID()
    {
        return m_entityID;
    }


};
*/
//namespace
namespace globalVariables
{
    float grav = 9.81f;

}


int main()
{

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    int circleRadius = 64;
    sf::CircleShape myShape(circleRadius);
    myShape.setPosition({512,512});
    sf::Color newColor(255, 255, 255);
    myShape.setFillColor(newColor);



    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

           
     
        }
        
        window.clear();
        //magical draw area

        window.draw(myShape);

        myShape.setPosition({ myShape.getPosition().x, myShape.getPosition().y - 1});




        //end magical draw area
        window.display();
    }
}
