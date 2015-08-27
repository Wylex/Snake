#include "World.h"

using namespace sf;

World::World(): window(VideoMode(700, 500), "Snake"), shape(Vector2f(15,15))
{
    shape.setFillColor(Color::White);
}

void World::start()
{
    while(window.isOpen())
    {
        Event event;
        
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }
    
        window.clear();
        window.draw(serpiente);
        window.display();

    }
}
