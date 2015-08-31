#include "World.h"
#include <string>

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), impHandler(), framesPS("Ressources/Font.ttf")
{
}

void World::start()
{
    Clock reloj, reloj2;

    while(window.isOpen())
    {
        std::shared_ptr<Command> comando = impHandler.handleInput(window);
        if(comando != 0)
            comando->execute(serpiente);
 
        if(reloj2.getElapsedTime() > seconds(1))
        {
            serpiente.grow();
            reloj2.restart();
        } 

        if(reloj.getElapsedTime() > microseconds(20000))
        {
            serpiente.move();
            reloj.restart();
        } 

        framesPS.update();

        window.clear();
        window.draw(serpiente);
        window.draw(framesPS);
        window.display();
    }
}
