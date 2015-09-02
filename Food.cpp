//Food.cpp

#include "Food.h"
#include "World.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Food::Food(): comida(radio)
{
    comida.setPointCount(3);    
    comida.setFillColor(sf::Color(90, 120, 180));

    srand(time(0));

    int num1 = rand() % (World::weight - 4*radio);
    int num2 = rand() % (World::width - 4*radio);

    comida.setPosition(num1 + 2*radio, num2 + 2*radio);

    collision = false;
}

void Food::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(comida, states);
}

sf::FloatRect Food::getCollisionBox() const
{
    return comida.getGlobalBounds();
}

void Food::collisionDetected(Entidad & entity)
{
    entidad = &entity;

    if(!collision)
        reloj.restart();

    collision = true;
}

void Food::update()
{
    if(collision)
    {
        if(typeid(Snake) == typeid(*entidad))
        {
            if(reloj.getElapsedTime() > sf::milliseconds(150))
            {    
                int num1 = rand() % (World::weight - 4*radio);
                int num2 = rand() % (World::width - 4*radio);

                comida.setPosition(num1 + 2*radio, num2 + 2*radio);

                collision = false;
            }
        }

        else if(typeid(Trampa) == typeid(*entidad))
        {
            int num1 = rand() % (World::weight - 4*radio);
            int num2 = rand() % (World::width - 4*radio);

            comida.setPosition(num1 + 2*radio, num2 + 2*radio);

            collision = false;
        }
    }
} 
