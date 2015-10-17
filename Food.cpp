//Food.cpp

#include "Food.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Food::Food(int f, int c, int s): Objeto(f, c, s)
{
    //textura.loadFromFile("Ressources/aaa.png");
    //objeto.setTexture(textura);
    radio = size/2.0;

    objeto.setPointCount(3);
    objeto.setRadius(radio);

    objeto.setFillColor(sf::Color(90, 120, 180));
    //objeto.setFillColor(sf::Color::Black);
    //objeto.setOutlineThickness(-8 + radio);
    //objeto.setOutlineColor(sf::Color(90, 120, 180));

    //srand(time(0));

    //int num1 = rand() % filas;
    //int num2 = rand() % columnas;

    //objeto.setPosition(num2 * size, num1 * size);

    //collision = false;
}

/*void Food::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(objeto, states);
}

sf::FloatRect Food::getCollisionBox() const
{
    return objeto.getGlobalBounds();
}

void Food::collisionDetected(Entidad & entity)
{
    entidad = &entity;

    if(!collision)
        reloj.restart();

    collision = true;
}*/

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

                objeto.setPosition(num2 * size, num1 * size);

                collision = false;
            }
        }

        else if(typeid(Trampa) == typeid(*entidad))
        {
            //int num1 = rand() % (size * columnas - 4*radio);
            //int num2 = rand() % (size * filas - 4*radio);
            //objeto.setPosition(num1 + 2*radio, num2 + 2*radio);

            int num1 = rand() % filas;
            int num2 = rand() % columnas;

            objeto.setPosition(num2 * size, num1 * size);

            collision = false;
        }
    }
} 

/*double Food::getPosicion()
{
  return (objeto.getPosition().x * objeto.getPosition().y);
}*/
