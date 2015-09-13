//Trampa.cpp

#include "Trampa.h"
#include "World.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Trampa::Trampa(): trap(radio)
{
    trap.setFillColor(sf::Color::Red);

    srand(time(0));

    int num1 = rand() % World::filas;
    int num2 = rand() % World::columnas;

    trap.setPosition(num2 * Snake::size, num1 * Snake::size);

    collision = false;
}

void Trampa::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(trap, states);
}

sf::FloatRect Trampa::getCollisionBox() const
{
    return trap.getGlobalBounds();
}

void Trampa::collisionDetected(Entidad & entity)
{
    /*entidad = &entity;

    if(!collision)
        reloj.restart();

    collision = true;*/
}

void Trampa::update()
{
    if(collision)
    {
        if(reloj.getElapsedTime() > sf::milliseconds(150))
        {
            if(typeid(Snake) == typeid(*entidad))
            {    
                /*int num1 = rand() % (World::weight - 4*radio);
                int num2 = rand() % (World::width - 4*radio);

                comida.setPosition(num1 + 2*radio, num2 + 2*radio);*/
            }

            collision = false;
        }
    }
} 
