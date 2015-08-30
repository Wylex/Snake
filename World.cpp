#include "World.h"
#include <string>

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), impHandler()
{
    fuente.loadFromFile("Ressources/Font.ttf");//FPS
    txt.setFont(fuente);//FPS
    txt.setPosition(10, 10);//FPS
    txt.setColor(Color::Red);//FPS
    txt.setCharacterSize(15);//FPS
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

        window.clear();
        window.draw(serpiente);
        showFPS();
        window.draw(txt);//FPS
        window.display();


    }
}

void World::showFPS()
{
    static Clock tiempo;
    static int numLaps(0);

    static std::string str;

    if(tiempo.getElapsedTime() > seconds(1))
    {
        str = std::to_string(numLaps);
        str += " frames per second";
        txt.setString(str);
        numLaps = 0;
        tiempo.restart();
    }

    numLaps++;

}
