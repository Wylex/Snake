//Snake.h

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Snake: public sf::Drawable
{
    private:
        std::vector<sf::RectangleShape> serpiente;
        static const int size = 15;

        bool isUp, isDown, isLeft, isRight;

    public:
        Snake();
        void update();

        void goUp();
        void goDown();
        void goLeft();
        void goRight();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

#endif
