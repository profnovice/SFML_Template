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


int main()
{
    float vOff = 500;
    std::array<sf::Vertex, 3> vertices;

    vertices[0] = {{ 0.0f + vOff, 0.0f + vOff}, sf::Color::Green, { 0.0f + vOff,  100 + vOff}};
    vertices[1] = { { 100+ vOff, 0 + vOff }, sf::Color::Red, { 100 + vOff,  100 + vOff } };
    vertices[2] = { { 100 + vOff, 100 + vOff}, sf::Color::Blue, { 0.0f + vOff,  0.0f + vOff} };
    

    sf::VertexBuffer triangles(sf::PrimitiveType::Triangles);
    triangles.create(vertices.size());
    triangles.update(vertices.data());

    unsigned int windowWidth = 1920u;
    unsigned int windowHeight = 1080u;

    int frameLimit = 120;

    auto window = sf::RenderWindow(sf::VideoMode({windowWidth, windowHeight}), "CMake SFML Project", sf::Style::Default);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(frameLimit);
    sf::Image iconImage("assets/SFMLPracticeIcon.png");
    window.setIcon(iconImage);
 
    sf::ConvexShape mouse;

    mouse.setPointCount(3);
    mouse.setPoint(0, {0,0});
    mouse.setPoint(1, { 30,30 });
    mouse.setPoint(2, { 0,50});
    mouse.setFillColor(sf::Color(64, 64, 64));
    mouse.setOutlineColor(sf::Color(255, 255, 255));

    std::ifstream fin("assets/config.txt");

    std::vector<Entity> entityVector;

    int newId;
    int newRadius;
    int newR;
    int newG;
    int newB;
    int newPosx;
    int newPosy;

    sf::Vector2i mousePosition;

    std::vector<std::shared_ptr<sf::Shape>> shared_Shapes;

    std::shared_ptr<sf::Shape> shared_Shape01 = std::make_shared<sf::CircleShape>(20);
    std::shared_ptr<sf::Shape> shared_Shape02 = std::make_shared<sf::RectangleShape>(sf::Vector2f(40,40));
    shared_Shape01->setPosition({200, 200});

    shared_Shapes.push_back(shared_Shape01);
    shared_Shapes.push_back(shared_Shape02);

    Vec2 vec01(1, 1);
    Vec2 vec02(1, 1);
    Vec2 vec03(1, -3);

    vec02 = Vec2::normalize(vec03);

    const Vec2 circle1(150, 100);
    const  Vec2 circle2(210 , 200);
    const float circle1rad = 67;
    const float circle2rad = 100;
    sf::CircleShape circleShape1(circle1rad);
    sf::CircleShape circleShape2(circle2rad);
    circleShape1.setOrigin(sf::Vector2f(circle1rad, circle1rad));
    circleShape2.setOrigin(sf::Vector2f( circle2rad, circle2rad));
    circleShape1.setPosition(sf::Vector2f(circle1.x,circle1.y));
    circleShape2.setPosition(sf::Vector2f(circle2.x, circle2.y));
    circleShape1.setFillColor(sf::Color(255, 0, 255, 128));
    circleShape2.setFillColor(sf::Color(255, 255, 0, 128));
   
    
    if(Vec2::circleCollision(circle1,circle2,circle1rad,circle2rad))
    {
        std::cout << "Collision" << std::endl;


    }

    std::cout << (Vec2::circleOverlap(circle1, circle2, circle1rad, circle2rad)).toString() << std::endl;

    std::vector<SimpleEntity> allSimpleEntites;

    typedef std::vector<std::shared_ptr<SimpleEntity>> EntityVector;
    typedef std::shared_ptr<SimpleEntity> SimpEntPtr;

    EntityVector simpleEntitiesType;
   
    SimpEntPtr nullEntity = (std::make_shared<SimpleEntity>(512, "Broke"));

    nullEntity->cName = std::make_shared<std::string>("im so special");
    nullEntity->cShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(40, 40));
   
    nullEntity->cTransform = std::make_shared<CTransform>(Vec2(900, 900), Vec2(0.1, 1.0));

    nullEntity->cShape->setFillColor(sf::Color::Red);

    
    const sf::Font bitFont("assets/8bitOperatorPlus8-Regular.ttf");
   

    sf::Text text(bitFont);
   
    EntityManager manager;

    for (int i = 0; i < 20; ++i)
    {
        SimpEntPtr simpEnt;

        if(i%2 == 0)
        {
            simpEnt = manager.addEntity("I was Even");
        }else
        {
            simpEnt = manager.addEntity("I was Odd");
        }
       
         
        
        std::shared_ptr<std::string> simpEntName;
        simpEntName = std::make_shared<std::string>(std::string("Name") + std::to_string(i));
        simpEnt->cName = simpEntName;
        CTransform intermediateTransform(Vec2(i * 69 % 600, i * 33 % 700), Vec2(i * .02, -i * .02));
        simpEnt->cTransform = std::make_shared<CTransform>(intermediateTransform);
        simpEnt->cShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(40, 40));
        simpEnt->cShape->setFillColor(sf::Color(i*10,255-i*10,(i+1*10+i*100)%256));
        simpEnt->cDisplayTag = std::make_shared<CDisplayTag>(bitFont);
        simpEnt->cDisplayTag->text.setString(std::to_string(simpEnt->m_id));
        simpEnt->cDisplayTag->text.setFillColor(sf::Color::Black);
        

    }


    
    manager.update();

   
    
    text.setPosition({1000, 10});
   // text.setFillColor(sf::Color(255, 255, 255));

    sf::Text fpsText(bitFont);
    fpsText.setPosition({ 100,10 });
    fpsText.setFillColor(sf::Color(255, 255, 255));


    sf::Text pauseText(bitFont);

   
    pauseText.setString("PAUSED");
    pauseText.setFillColor(sf::Color(255, 255, 255));
    pauseText.setScale({2.0f,2.0f});
    pauseText.setOrigin(pauseText.getLocalBounds().getCenter());
    pauseText.setPosition({(float)windowWidth/2 , (float)windowHeight/2 });

    sf::Text clockText(bitFont);
    clockText.setString("Clock");
    clockText.setFillColor(sf::Color(255, 255, 255));
    clockText.setPosition({ (float)windowWidth-200, 100.0f});
    
    

    int circleRadius = 64;
    sf::CircleShape myShape(circleRadius);
    myShape.setPosition({512,512});
    sf::Color newColor(255, 255, 255);
    myShape.setFillColor(newColor);

    Entity myEntity =  Entity(1, myShape);


    int counterLoop = 0;

    Vec2 movementDir(0,0);
    float movementMultiplyer = .5f;
    float sprintMultiplyer = 2.0f;

    int keysDown = 0;

    sf::Clock clock;
    


    sf::Texture ceilingTexture("assets/CeilingSquareAltered.png");
    ceilingTexture.setSmooth(false);
    sf::Sprite ceilingSprite(ceilingTexture);
    ceilingSprite.setPosition({ (float)windowWidth - 256.0f, (float)windowHeight - 256.0f });


    bool keyDown_A = false;
    bool keyDown_D = false;
    bool keyDown_W = false;
    bool keyDown_S = false;
    bool keyDown_Shift = false;
    bool mouseDown_LeftButton = false;
    

    sf::Clock deltaTimeClock;
    float deltaTime = 0.0f;

    sf::Clock framesPerSecondClock;
    size_t framesSinceClockTick = 0;

    //SimpEntPtr testSimpleEntity = manager.addEntity("test entity");

    bool isPaused = false;


    while (window.isOpen())
    {
        deltaTime = deltaTimeClock.getElapsedTime().asMicroseconds() / 1000.0f;
        deltaTimeClock.restart();
        mouseDown_LeftButton = false;

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            //window.setKeyRepeatEnabled(false) use if I want to make the press a single action rather than on a heartbeat 
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    if (!isPaused)
                    {
                        isPaused = true;
                        clock.stop();
                    }
                    else 
                    {
                        isPaused = false; 
                        clock.start();

                    }

                if (keyPressed->scancode == sf::Keyboard::Scancode::A)
                {
                    keyDown_A = true;


                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::D)
                {
                    keyDown_D = true;


                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::W)
                {
                    keyDown_W = true;


                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::S)
                {
                    keyDown_S = true;


                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::LShift)
                {
                    keyDown_Shift = true;


                }

                
            }
            else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyReleased->scancode == sf::Keyboard::Scancode::A)
                {

                    keyDown_A = false;
                }

                if (keyReleased->scancode == sf::Keyboard::Scancode::D)
                {

                    keyDown_D = false;
                }
                if (keyReleased->scancode == sf::Keyboard::Scancode::W)
                {

                    keyDown_W = false;
                }

                if (keyReleased->scancode == sf::Keyboard::Scancode::S)
                {

                    keyDown_S = false;
                }
                if (keyReleased->scancode == sf::Keyboard::Scancode::LShift)
                {

                    keyDown_Shift = false;
                }

                
            }
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                //std::cout << "x" << (float)mousePosition.x << "y" << (float)mousePosition.y << std::endl;
                mousePosition = mouseMoved->position;
                mouse.setPosition({(float)mousePosition.x,(float)mousePosition.y});

            }
            else if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseClick->button == sf::Mouse::Button::Left)
                {
                    mouseDown_LeftButton = true;
                    std::cout << "button down" << std::endl;
                }

            }
            else if (const auto* mouseRelease = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseRelease->button == sf::Mouse::Button::Left)
                {
                    mouseDown_LeftButton = false;
                }

                }

            else if (const auto* resized = event->getIf<sf::Event::Resized>()) 
            {
                windowWidth = resized->size.x;
                windowHeight = resized->size.y;
                window.create(sf::VideoMode({ windowWidth, windowHeight }), "CMake SFML Project", sf::Style::Default);
                window.setMouseCursorVisible(false);
                window.setFramerateLimit(frameLimit);
                sf::Image iconImage("assets/SFMLPracticeIcon.png");
                window.setIcon(iconImage);



                pauseText.setPosition({ (float)windowWidth / 2 , (float)windowHeight / 2 });
            }

           
     
        }



        

        if (isPaused)
        {

            window.clear();
            window.draw(pauseText);
            window.display();
            continue;
        }
        
        manager.update();

        //std::cout<< testSimpleEntity.use_count() << std::endl;
        if(mouseDown_LeftButton)
        {
            
            SimpEntPtr simpEnt;
           
            
               simpEnt = manager.addEntity("I'm new");
         
               int i = simpEnt->m_id % 25;


            std::shared_ptr<std::string> simpEntName;
            simpEntName = std::make_shared<std::string>(std::string("Name") + std::to_string(i));
            simpEnt->cName = simpEntName;
            CTransform intermediateTransform(Vec2(mousePosition.x, mousePosition.y), Vec2(i * .02, -i * .02));
            simpEnt->cTransform = std::make_shared<CTransform>(intermediateTransform);
            simpEnt->cShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(40, 40));
            simpEnt->cShape->setFillColor(sf::Color(i * 10, 255 - i * 10, (i + 1 * 10 + i * 100) % 256));
            simpEnt->cDisplayTag = std::make_shared<CDisplayTag>(bitFont);
            simpEnt->cDisplayTag->text.setString(std::to_string(simpEnt->m_id));
            simpEnt->cDisplayTag->text.setFillColor(sf::Color::Black);


            std::cout << simpEnt->m_id << " created, ";
           
            manager.getAllEntities().front()->m_alive = false;
            std::cout << manager.getAllEntities().front()->m_id << " marked for death " << std::endl;



        }
        
       


        movementDir.x = 0;
        movementDir.y = 0;

        if (keyDown_A) 
        {
            movementDir.x += -1;
        }

        if (keyDown_D)
        {
            movementDir.x += 1;
        }
        if (keyDown_W)
        {
            movementDir.y += -1;
        }

        if (keyDown_S)
        {
            movementDir.y += 1;
        }
        if (keyDown_Shift) 
        {
            movementDir.x = movementDir.x * sprintMultiplyer;
            movementDir.y = movementDir.y * sprintMultiplyer;
        }

      

        
        window.clear();
        //magical draw area

        

        std::string clockString = std::to_string(clock.getElapsedTime().asSeconds());
        clockText.setString(clockString);

        std::string deltaTimeString = std::to_string( deltaTime);
        fpsText.setString(deltaTimeString);

        myEntity.setVecPosition(Vec2(myEntity.getVecPosition().x + movementDir.x * movementMultiplyer * deltaTime, myEntity.getVecPosition().y + movementDir.y * movementMultiplyer * deltaTime) );

        window.draw(ceilingSprite);

        window.draw(myEntity.getShape());

        window.draw(mouse);

        window.draw(clockText);

        
        window.draw(fpsText);

        for (auto& e : manager.getAllEntities())
        {

            if (e->cShape && e->cTransform)
            {
                
                if (e->cTransform->pos.x < 0.0f || e->cTransform->pos.x + e->cShape->getSize().x> windowWidth) {
                    e->cTransform->velocity.x = e->cTransform->velocity.x * -1.0f;
                }
                if (e->cTransform->pos.y < 0.0f || e->cTransform->pos.y +e->cShape->getSize().y > windowHeight) {
                    e->cTransform->velocity.y = e->cTransform->velocity.y * -1.0f;
                }

                

                e->cTransform->pos = e->cTransform->pos + e->cTransform->velocity * deltaTime;
                e->cShape->setPosition({e->cTransform->pos.x, e->cTransform->pos.y});
                window.draw(*e->cShape);

            }
            
            if (e->cDisplayTag && e->cTransform)
            {

                e->cDisplayTag->text.setPosition({ e->cTransform->pos.x,e->cTransform->pos.y });
                window.draw(e->cDisplayTag->text);

            }
            

        }



        framesSinceClockTick++;
        float elapsedSeconds = framesPerSecondClock.getElapsedTime().asSeconds();
        if (elapsedSeconds >= 1.0f)
        {
            text.setString(std::to_string(framesSinceClockTick / elapsedSeconds));
            float colorCodedfps = std::clamp((framesSinceClockTick / elapsedSeconds) / frameLimit * 255.0f, 0.0f, 255.0f);
            text.setFillColor(sf::Color(255 - colorCodedfps, colorCodedfps, .5));
            framesPerSecondClock.restart();
            framesSinceClockTick = 0;

            

        }
        window.draw(circleShape1);
        window.draw(circleShape2);

        window.draw(text);
        window.draw(triangles);
        //end magical draw area
        window.display();

        counterLoop = (counterLoop +1)% 256;

        
       
        
    }
}
