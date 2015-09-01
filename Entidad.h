//Entidad.h

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <typeinfo>

class Entidad
{
    public:
        virtual sf::FloatRect getCollisionBox() const = 0;
        virtual void collisionDetected(Entidad & entity) = 0;
};

#endif
