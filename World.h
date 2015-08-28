//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "InputHandler.h"

class World
{
    private:
        sf::RenderWindow window;
        sf::RectangleShape shape;
        Snake serpiente; 

        InputHandler impHandler; 

    public:
        World();
        void start();
};

#endif
