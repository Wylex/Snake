//Snake.cpp

#include "Snake.h"

using namespace sf;

Snake::Snake(): serpiente(1)
{
    serpiente[0].setSize(Vector2f(size, size));
    serpiente[0].setFillColor(Color(170, 100, 250));

    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = false;
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for(int i(0); i < serpiente.size(); i++)
        target.draw(serpiente[i], states);

}

void Snake::goUp()
{
    isUp = true;
    isDown = false;
    isLeft = false;
    isRight = false;
}

void Snake::goDown()
{
    isUp = true;
    isDown = true;
    isLeft = false;
    isRight = false;
}

void Snake::goLeft()
{
    isUp = false;
    isDown = false;
    isLeft = true;
    isRight = false;
}

void Snake::goRight()
{
    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = true;
}

void Snake::move()
{
    //for(int i(serpiente.size() -1); i > 0; i++)
        //serpiente[i] = serpiente[i - 1];
    if(serpiente.size() > 0)
        serpiente[serpiente.size() - 1] = serpiente[0];

    if(isUp)
        serpiente[0].move(0, -size);
    else if(isDown)
        serpiente[0].move(0, size);
    else if(isRight)
        serpiente[0].move(size, 0);
    else if(isLeft)
        serpiente[0].move(-size, 0);
} 

void Snake::grow()
{
    Vector2f lastPos = serpiente[serpiente.size() - 1].getPosition();

    serpiente.push_back(RectangleShape(Vector2f(size, size)));
    serpiente[serpiente.size() -1].setPosition(lastPos);
}
