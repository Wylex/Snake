#include "World.h"
#include <string>

using namespace sf;

World::World(): window(VideoMode(weight, width), "Snake"), impHandler(), framesPS("Ressources/Font.ttf")
{
    choques.add(serpiente);
    choques.add(comida);

    textura.loadFromFile("Ressources/Menu.png");
    sprite.setTexture(textura);
 
    state = 0;
}

void World::start()
{
    while(window.isOpen())
    {
        if(state == 0)
            startMenu();
        else if(state == 1)
            startGame();
    }
}

void World::startGame()
{
    std::shared_ptr<Command> comando = impHandler.handleInput(window);
    if(comando != 0)
        comando->execute(serpiente);

    serpiente.update();
    framesPS.update();
    comida.update();

    choques.check();

    window.clear();
    window.draw(comida);
    window.draw(serpiente);
    window.draw(framesPS);
    window.display();
}

void World::startMenu()
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::G)
                    state = 1;
                break;
        }
    }

    window.clear();
    window.draw(sprite);
    window.display();
}
