//Snake.h

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entidad.h"

class Snake: public sf::Drawable, public Entidad
{
    private:
        std::vector<sf::RectangleShape> serpiente;
        static const int size = 15;
        int velocidad;

        bool isUp, isDown, isLeft, isRight;
        bool isGrowing;

    public:
        Snake();
        void move();
        void grow();

        void goUp();
        void goDown();
        void goLeft();
        void goRight();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
        virtual sf::FloatRect getCollisionBox() const;
        virtual void collisionDetected(Entidad & entity) {}
};

#endif
