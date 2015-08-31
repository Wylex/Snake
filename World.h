//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "InputHandler.h"
#include "Command.h"
#include "FPS.h"
#include <memory>

class World
{
    private:
        sf::RenderWindow window;
        FPS framesPS;
        Snake serpiente; 

        InputHandler impHandler; 

    public:
        World();
        void start();
};

#endif
