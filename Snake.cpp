//Snake.cpp

#include "Snake.h"

using namespace sf;

Snake::Snake(): serpiente(1)
{
    serpiente[0].setSize(Vector2f(15, 15));
    serpiente[0].setFillColor(Color::Red);
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for(int i(0); i < serpiente.size(); i++)
        target.draw(serpiente[i], states);

}
