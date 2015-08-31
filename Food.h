//Food.h

#ifndef FOOD_H
#define FOOD_H

#include "Entidad.h"
#include <typeinfo>
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Food: public Entidad, public sf::Drawable
{
    private:
        sf::CircleShape comida;

    public:
        Food();

        static const int radio = 10;

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        virtual sf::FloatRect getCollisionBox() const;
        virtual void collisionDetected(Entidad & entity);
};

#endif
