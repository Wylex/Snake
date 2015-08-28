#include "World.h"

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), impHandler()
{
}

void World::start()
{
    
    while(window.isOpen())
    {
        impHandler.handleInput(window);
 
        window.clear();
        window.draw(serpiente);
        window.display();

    }
}
