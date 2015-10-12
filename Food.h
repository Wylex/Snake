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

        //unsigned int filas;
        //unsigned int columnas;
        //unsigned int size;

        sf::CircleShape comida;
        bool collision;
        sf::Clock reloj;
        Entidad * entidad;

    public:
        Food(int f, int c, int s);

        double radio;

        void update();
  
        double getPosicion();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

#endif
