//Snake.cpp

#include "Snake.h"
#include "World.h"

using namespace sf;

Snake::Snake(int f, int c, int s): Entidad(f, c, s), serpiente(1)
{
    serpiente[0].setSize(Vector2f(size, size));
    serpiente[0].setFillColor(Color(190, 180, 180));
    serpiente[0].setPosition(sf::Vector2f(0, World::width/2 - size/2));

    velocidad = size;
    aMovido = false;

    isGrowing = false;

    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = true;

    grow();
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for(int i(serpiente.size() -1); i >= 0; i--)
        target.draw(serpiente[i], states);

}

void Snake::goUp()
{
    if(!isDown and aMovido)// && movimiento > size + 2)
    {
        /*if(isLeft)
        {
            serpiente[0].setOrigin(0, size);
            serpiente[0].setRotation(90);
        }*/
        /*if(isRight)
        {
            serpiente[0].setOrigin(size/2, size);
            serpiente[0].setRotation(240);

            serpiente[0].move(0, size/2);
        }*/
     

        isUp = true;
        isDown = false;
        isLeft = false;
        isRight = false;

        //movimiento = 0;
        
        aMovido = false;
    }
}

void Snake::goDown()
{
    if(!isUp and aMovido)// && movimiento > size + 2)
    {
        isUp = false;
        isDown = true;
        isLeft = false;
        isRight = false;

        //movimiento = 0;
        
        aMovido = false;
    }
}

void Snake::goLeft()
{
    if(!isRight and aMovido)// && movimiento > size + 2)
    {
        isUp = false;
        isDown = false;
        isLeft = true;
        isRight = false;

        //movimiento = 0;
        
        aMovido = false;
    }
}

void Snake::goRight()
{
    if(!isLeft and aMovido)// && movimiento > size + 2)
    {
        isUp = false;
        isDown = false;
        isLeft = false;
        isRight = true;

        //movimiento = 0;
        
        aMovido = false;
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

    aMovido = true;

    sf::Vector2f pos = serpiente[0].getPosition();
    if(pos.x >= World::weight)
        serpiente[0].setPosition(0, pos.y);
    else if(pos.y >= World::width)
        serpiente[0].setPosition(pos.x, 0);
    else if(pos.x < 0)
        serpiente[0].setPosition(World::weight - size, pos.y);
    else if(pos.y < 0)
        serpiente[0].setPosition(pos.x, World::width - size);

    //movimiento += velocidad;
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
    if(reloj.getElapsedTime() > milliseconds(50))
    //if(reloj.getElapsedTime() > milliseconds(200))
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

    else if(typeid(Trampa) == typeid(entity))
        restart();
}

void Snake::restart()
{
    serpiente.clear();
    serpiente.push_back(RectangleShape(Vector2f(size, size)));

    serpiente[0].setFillColor(Color(190, 180, 180));
    serpiente[0].setPosition(sf::Vector2f(10, World::width/2 - size/2));

    velocidad = size;
    //movimiento = 0;

    isGrowing = false;

    isUp = false;
    isDown = false;
    isLeft = false;
    isRight = true;

    grow();
}
