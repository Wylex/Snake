//Food.h

#ifndef FOOD_H
#define FOOD_H

#include "Entidad.h"
#include "Trampa.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Food: public Entidad, public sf::Drawable
{
    private:
        sf::CircleShape comida;
        bool collision;
        sf::Clock reloj;
        Entidad * entidad;

    public:
        Food();

        static const int radio = 7.5;

        void update();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

#endif
