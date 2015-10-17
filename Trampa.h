//Trampa.h

#ifndef TRAMPA_H
#define TRAMPA_H

#include "Objeto.h"
#include <SFML/Graphics.hpp>

class Trampa: public Objeto<sf::CircleShape>
{
    public:
        Trampa(int f, int c, int s);

        void update();
};

#endif
