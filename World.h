//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Collisions.h"
#include "InputHandler.h"
#include "Command.h"
#include "Food.h"
#include "FPS.h"
#include <memory>

class World
{
    private:
        sf::RenderWindow window;
        FPS framesPS;
        Snake serpiente; 
        Food comida;

        Collisions choques;

        InputHandler impHandler; 

    public:
        World();
        void start();

        static const unsigned int width = 500;
        static const unsigned int weight = 700;
};

#endif
