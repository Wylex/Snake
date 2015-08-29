//Entidad.h

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>

class Entidad
{
    public:
        virtual sf::FloatRect getCollisionBox() const = 0;
        virtual void collisionDetected(Entidad & entity);
};

#endif
