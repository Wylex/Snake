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
            Trampa trap;
            Food comida;

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

        static const unsigned int filas = 35;
        static const unsigned int columnas = 45;
        static const unsigned int width = Snake::size * filas;
        static const unsigned int weight = Snake::size * columnas;
};

#endif
