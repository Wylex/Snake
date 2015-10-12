//Trampa.cpp

#include "Trampa.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Trampa::Trampa(int f, int c, int s): Entidad(f, c, s)
{
    trap.setFillColor(sf::Color::Red);

    radio = size/2.0;

    trap.setRadius(radio);
    trap.setPointCount(4);

    srand(time(0));

    int num1 = rand() % filas;
    int num2 = rand() % columnas;

    trap.setPosition(num2 * size, num1 * size);

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
                /*int num1 = rand() % (size * filas - 4*radio);
                int num2 = rand() % (size * columnas - 4*radio);

                comida.setPosition(num1 + 2*radio, num2 + 2*radio);*/
            }

            collision = false;
        }
    }
} 

/*double Trampa::getPosition()
{
  return trap.getPosition().x * trap.getPosition().y;
}*/
