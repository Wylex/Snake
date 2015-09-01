//Snake.cpp

#include "Snake.h"

using namespace sf;

Snake::Snake(): serpiente(1)
{
    serpiente[0].setSize(Vector2f(size, size));
    serpiente[0].setFillColor(Color(190, 180, 180));

    velocidad = 3;
    movimiento = 0;

    isGrowing = false;

    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = true;
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for(int i(serpiente.size() -1); i >= 0; i--)
        target.draw(serpiente[i], states);

}

void Snake::goUp()
{
    if(!isDown && movimiento > size + 2)
    {
        isUp = true;
        isDown = false;
        isLeft = false;
        isRight = false;

        movimiento = 0;
    }
}

void Snake::goDown()
{
    if(!isUp && movimiento > size + 2)
    {
        isUp = false;
        isDown = true;
        isLeft = false;
        isRight = false;

        movimiento = 0;
    }
}

void Snake::goLeft()
{
    if(!isRight && movimiento > size + 2)
    {
        isUp = false;
        isDown = false;
        isLeft = true;
        isRight = false;

        movimiento = 0;
    }
}

void Snake::goRight()
{
    if(!isLeft && movimiento > size + 2)
    {
        isUp = false;
        isDown = false;
        isLeft = false;
        isRight = true;

        movimiento = 0;
    }
}

void Snake::move()
{
    Vector2f lastPos = serpiente[serpiente.size() - 1].getPosition();

    for(int i(serpiente.size() -1); i > 0; i--)
        serpiente[i].setPosition(serpiente[i-1].getPosition());

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

    movimiento += velocidad;
} 

void Snake::grow()
{
    isGrowing = true;
}

sf::FloatRect Snake::getCollisionBox() const
{
    return serpiente[0].getGlobalBounds();
} 

void Snake::update()
{
    if(reloj.getElapsedTime() > microseconds(20000))
    {
        move();
        reloj.restart();
    } 
}

void Snake::collisionDetected(Entidad & entity)
{
    if(typeid(Food) == typeid(entity))
    {    
        grow();
        grow();
    }
}
