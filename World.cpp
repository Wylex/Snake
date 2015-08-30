#include "World.h"

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), impHandler()
{
}

void World::start()
{
    Clock reloj;
 
    while(window.isOpen())
    {
        std::shared_ptr<Command> comando = impHandler.handleInput(window);
        if(comando != 0)
            comando->execute(serpiente);
 
        if(reloj.getElapsedTime() > seconds(1))
        {
            serpiente.move();
            reloj.restart();
        } 

        window.clear();
        window.draw(serpiente);
        window.display();

    }
}
