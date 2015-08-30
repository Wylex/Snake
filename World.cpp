#include "World.h"
#include <string>

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), impHandler()
{
}

void World::start()
{
    Clock reloj, reloj2;

    //Clock fps;
    //int numLaps(0);
    //Text txt;
    //txt.setPosition(100, 100);
    //txt.setColor(Color::Red);
 
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

        //if(fps.getElapsedTime() > seconds(1))
        //{
            //txt.setString(std::string(numLaps + " frames per second"));
            //numLaps = 0;
            //fps.restart();
        //}

        window.clear();
        window.draw(serpiente);
        //window.draw(txt);
        window.display();

        //numLaps++;

    }
}
