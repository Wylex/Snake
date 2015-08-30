//Snake.cpp

#include "Snake.h"

using namespace sf;

Snake::Snake(): serpiente(1)
{
    serpiente[0].setSize(Vector2f(size, size));
    serpiente[0].setFillColor(Color(160, 150, 150));

    velocidad = 3;

    isGrowing = false;

    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = false;
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for(int i(serpiente.size() -1); i >= 0; i--)
        target.draw(serpiente[i], states);

}

void Snake::goUp()
{
    if(!isDown)
    {
        isUp = true;
        isDown = false;
        isLeft = false;
        isRight = false;
    }
}

void Snake::goDown()
{
    if(!isUp)
    {
        isUp = false;
        isDown = true;
        isLeft = false;
        isRight = false;
    }
}

void Snake::goLeft()
{
    if(!isRight)
    {
        isUp = false;
        isDown = false;
        isLeft = true;
        isRight = false;
    }
}

void Snake::goRight()
{
    if(!isLeft)
    {
        isUp = false;
        isDown = false;
        isLeft = false;
        isRight = true;
    }
}

void Snake::move()
{
    Vector2f lastPos = serpiente[serpiente.size() - 1].getPosition();

    for(int i(serpiente.size() -1); i > 0; i--)
        serpiente[i].setPosition(serpiente[i-1].getPosition());
    //if(serpiente.size() > 1)
        //serpiente[serpiente.size() - 1].setPosition(serpiente[0].getPosition());

    if(isGrowing)
    {
        serpiente.push_back(RectangleShape(Vector2f(size, size)));
        serpiente[serpiente.size() -1].setPosition(lastPos);
        serpiente[serpiente.size() -1].setFillColor(Color(190, 180, 180));
        isGrowing = false;
    }

    if(isUp)
        serpiente[0].move(0, -velocidad);
    else if(isDown)
        serpiente[0].move(0, velocidad);
    else if(isRight)
        serpiente[0].move(velocidad, 0);
    else if(isLeft)
        serpiente[0].move(-velocidad, 0);
} 

void Snake::grow()
{
    isGrowing = true;
    /*Vector2f lastPos = serpiente[serpiente.size() - 1].getPosition();

    serpiente.push_back(RectangleShape(Vector2f(size, size)));
    serpiente[serpiente.size() -1].setPosition(lastPos);*/
}

sf::FloatRect Snake::getCollisionBox() const
{
    return serpiente[0].getGlobalBounds();
} 
