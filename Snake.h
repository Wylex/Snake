//Snake.h

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Snake: public sf::Drawable
{
    private:
        std::vector<sf::RectangleShape> serpiente;

    public:
        Snake();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};

#endif
