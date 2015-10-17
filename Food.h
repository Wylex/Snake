//Food.h

#ifndef FOOD_H
#define FOOD_H

#include "Objeto.h"
#include "Trampa.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Food: public Objeto<sf::CircleShape>
{
    public:

        Food(int f, int c, int s);

        void update();
};

#endif
