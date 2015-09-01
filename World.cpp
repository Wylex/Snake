#include "World.h"
#include <string>

using namespace sf;

World::World(): window(VideoMode(weight, width), "Snake"), impHandler(), framesPS("Ressources/Font.ttf")
{
    choques.add(serpiente);
    choques.add(comida);
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
        comida.update();
        choques.check();

        window.clear();
        window.draw(comida);
        window.draw(serpiente);
        window.draw(framesPS);
        window.display();
    }
}
