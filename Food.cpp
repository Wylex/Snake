//Food.cpp

#include "Food.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Food::Food(int f, int c, int s): Entidad(f, c, s)
{
    //textura.loadFromFile("Ressources/aaa.png");
    //comida.setTexture(textura);
    radio = size/2.0;

    comida.setPointCount(3);
    comida.setRadius(radio);

    comida.setFillColor(sf::Color(90, 120, 180));
    //comida.setFillColor(sf::Color::Black);
    //comida.setOutlineThickness(-8 + radio);
    //comida.setOutlineColor(sf::Color(90, 120, 180));

    srand(time(0));

    int num1 = rand() % filas;
    int num2 = rand() % columnas;

    comida.setPosition(num2 * size, num1 * size);

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
                int num1 = rand() % filas;
                int num2 = rand() % columnas;

                comida.setPosition(num2 * size, num1 * size);

                collision = false;
            }
        }

        else if(typeid(Trampa) == typeid(*entidad))
        {
            //int num1 = rand() % (size * columnas - 4*radio);
            //int num2 = rand() % (size * filas - 4*radio);
            //comida.setPosition(num1 + 2*radio, num2 + 2*radio);

            int num1 = rand() % filas;
            int num2 = rand() % columnas;

            comida.setPosition(num2 * size, num1 * size);

            collision = false;
        }
    }
} 
