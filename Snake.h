//Snake.h

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Trampa.h"
#include "Food.h"

#include "Marcador.h"


class Snake: public sf::Drawable, public Entidad
{
    private:
        std::vector<sf::RectangleShape> serpiente;
        bool aMovido;
        int velocidad;

        bool isUp, isDown, isLeft, isRight;
        bool isGrowing;

        sf::Clock reloj;

        void restart();

        Marcador puntos;

    public:
        Snake(int f, int c, int s);
        void move();
        void grow();
        void update();

        void goUp();
        void goDown();
        void goLeft();
        void goRight();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

#endif
