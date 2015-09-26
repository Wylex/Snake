//Food.cpp

#include "Food.h"
#include "World.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Food::Food(): comida(radio, 3)
{
    //textura.loadFromFile("Ressources/aaa.png");
    //comida.setTexture(textura);

    //comida.setPointCount(300);
    comida.setFillColor(sf::Color::Black);
    comida.setOutlineThickness(-8 + radio);
    comida.setOutlineColor(sf::Color(90, 120, 180));

    srand(time(0));

    int num1 = rand() % World::filas;
    int num2 = rand() % World::columnas;

    comida.setPosition(num2 * Snake::size, num1 * Snake::size);

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
                int num1 = rand() % World::filas;
                int num2 = rand() % World::columnas;

                comida.setPosition(num2 * Snake::size, num1 * Snake::size);

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
