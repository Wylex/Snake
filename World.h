//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Collisions.h"
#include "InputHandler.h"
#include "Command.h"
#include "Food.h"
#include "Trampa.h"
#include "FPS.h"
#include <memory>

class World
{
    private:
        sf::RenderWindow window;
        int state;

        //Game
            FPS framesPS;
            Snake serpiente; 
            Food comida;
            Trampa trap;

            Collisions choques;

            InputHandler impHandler; 

        //Menu
            sf::Texture textura;
            sf::Sprite sprite;

    
    private:
        void startGame();
        void startMenu();

    public:
        World();
        void start();

        static const unsigned int width = 500;
        static const unsigned int weight = 700;
};

#endif
