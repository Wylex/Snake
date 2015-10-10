#include "World.h"
#include <string>

using namespace sf;

#include <iostream>

World::World(): window(VideoMode(weight, width), "Snake"), impHandler(), framesPS("Ressources/Font.ttf"), 
comida(filas, columnas, size), serpiente(filas, columnas, size), trap(filas, columnas, size)
{
    pause = false;

    choques.add(serpiente);
    choques.add(comida);
    choques.add(trap);

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
    {
      if(typeid(pauseCommand) == typeid(*comando))
      {
        if(pause)
          pause = false;
        else if(!pause)
          pause = true;
      } 
      else
        comando->execute(serpiente);
    }
    
    if(!pause)
    {
      serpiente.update();
      framesPS.update();
      comida.update();
      trap.update();

      choques.check();
    }


    window.clear();
    window.draw(trap);
    window.draw(comida);
    window.draw(serpiente);
    window.draw(framesPS);
    window.display();
}

void World::startMenu()
{
    Event event;

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
