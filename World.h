//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"

class World
{
    private:
        sf::RenderWindow window;
        sf::RectangleShape shape;
        Snake serpiente; 

    public:
        World();
        void start();
};

#endif
