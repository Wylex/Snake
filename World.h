//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "InputHandler.h"
#include "Command.h"
#include <memory>

class World
{
    private:
        sf::RenderWindow window;
        sf::Text txt;// FPS
        sf::Font fuente;// FPS
        Snake serpiente; 

        InputHandler impHandler; 

        void showFPS();

    public:
        World();
        void start();
};

#endif
