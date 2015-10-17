//Trampa.cpp

#include "Trampa.h"
#include <ctime>
#include <cstdlib>

//#include <iostream>


Trampa::Trampa(int f, int c, int s): Objeto(f, c, s)
{
  objeto.setFillColor(sf::Color::Red);

  objeto.setRadius(size/2.0);
  objeto.setPointCount(4);
}

void Trampa::update()
{
  if(collision)
  {
    if(reloj.getElapsedTime() > sf::milliseconds(150))
    {
      /*if(typeid(Snake) == typeid(*entidad))
      {    

      }*/

      collision = false;
    }
  }
} 
