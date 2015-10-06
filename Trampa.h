//Trampa.h

#ifndef TRAMPA_H
#define TRAMPA_H

#include "Entidad.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class Trampa: public Entidad, public sf::Drawable
{
    private:
        sf::CircleShape trap;
        bool collision;
        sf::Clock reloj;
        Entidad * entidad;

    public:
        Trampa(int f, int c, int s);

        double radio;

        void update();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

#endif
