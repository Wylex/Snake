//Food.cpp

#include "Food.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Food::Food(int f, int c, int s): Objeto(f, c, s)
{
    objeto.setPointCount(3);
    objeto.setRadius(size/2.0);

    objeto.setFillColor(sf::Color(90, 120, 180));

    //objeto.setFillColor(sf::Color::Black);
    //objeto.setOutlineThickness(-8 + radio);
    //objeto.setOutlineColor(sf::Color(90, 120, 180));
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

                objeto.setPosition(num2 * size, num1 * size);

                collision = false;
            }
        }

        else if(typeid(Trampa) == typeid(*entidad))
        {
            int num1 = rand() % filas;
            int num2 = rand() % columnas;

            objeto.setPosition(num2 * size, num1 * size);

            collision = false;
        }
    }
} 
