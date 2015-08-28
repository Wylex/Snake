#include "World.h"

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), shape(Vector2f(15,15)), impHandler()
{
    shape.setFillColor(Color::White);
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
