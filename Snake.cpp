//Snake.cpp

#include "Snake.h"
#include <iostream>

using namespace sf;

Snake::Snake(int f, int c, int s): Entidad(f, c, s), serpiente(1), puntos(c*s)
{
	velocidad = 50;

	serpiente[0].setSize(Vector2f(size, size));
	serpiente[0].setFillColor(Color(190, 180, 180));
	serpiente[0].setPosition(sf::Vector2f(0, int(filas/2)*size));

	aMovido = false;

	isGrowing = true;

	isUp = false;
	isDown = false;
	isLeft = false;
	isRight = true;
}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(puntos);

	for(int i(serpiente.size() -1); i >= 0; i--)
		target.draw(serpiente[i], states);
}

void Snake::goUp()
{
	if(!isDown and aMovido)//Si no está moviendo en dirección contraria y ya ha movido por lo menos un cuadrado
	{
		isUp = true;
		isDown = false;
		isLeft = false;
		isRight = false;

		aMovido = false;
	}
}

void Snake::goDown()
{
	if(!isUp and aMovido)
	{
		isUp = false;
		isDown = true;
		isLeft = false;
		isRight = false;

		aMovido = false;
	}
}

void Snake::goLeft()
{
	if(!isRight and aMovido)
	{
		isUp = false;
		isDown = false;
		isLeft = true;
		isRight = false;

		aMovido = false;
	}
}

void Snake::goRight()
{
	if(!isLeft and aMovido)
	{
		isUp = false;
		isDown = false;
		isLeft = false;
		isRight = true;

		aMovido = false;
	}
}

void Snake::move()
{
	Vector2f lastPos = serpiente[serpiente.size() - 1].getPosition();

	//Mover cuerpo
	for(int i(serpiente.size() -1); i > 0; i--)
		serpiente[i].setPosition(serpiente[i-1].getPosition());

	//Añadir cuadrado
	if(isGrowing)
	{
		serpiente.push_back(RectangleShape(Vector2f(size, size)));
		serpiente[serpiente.size() -1].setPosition(lastPos);
		serpiente[serpiente.size() -1].setFillColor(Color(190, 180, 180));
		isGrowing = false;
	}

	//Mover cabeza
	if(isUp)
		serpiente[0].move(0, -size);
	else if(isDown)
		serpiente[0].move(0, size);
	else if(isRight)
		serpiente[0].move(size, 0);
	else if(isLeft)
		serpiente[0].move(-size, 0);

	aMovido = true;

	//Verificar que la serpiente está dentro de los bordes
	sf::Vector2f pos = serpiente[0].getPosition();
	if(pos.x >= (size * columnas))
		serpiente[0].setPosition(0, pos.y);
	else if(pos.y >= (size * filas))
		serpiente[0].setPosition(pos.x, 0);
	else if(pos.x < 0)
		serpiente[0].setPosition((size * columnas) - size, pos.y);
	else if(pos.y < 0)
		serpiente[0].setPosition(pos.x, (size * filas) - size);

	checkCollisionsBody();//Check if head eats body
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
	if(reloj.getElapsedTime() > milliseconds(velocidad))
	{
		move();
		reloj.restart();
	} 

	for(int i(0); i < modificadores.size(); i++)
	{
		if(modificadores[i].reloj.getElapsedTime().asSeconds() > modificadores[i].duracion)
		{
			velocidad -= modificadores[i].speed;
			modificadores.erase(modificadores.begin()+i);
		}
	}
}

void Snake::collisionDetected(Entidad & entity)
{
	static double p;

	if(typeid(Food) == typeid(entity))
	{    
		if(p != (static_cast<Food *>(&entity))->getPosicion())
		{
			grow();
			puntos.subirPuntuacion(1);
		}

		p = (static_cast<Food *>(&entity))->getPosicion();
	}
	else if(typeid(Trampa) == typeid(entity))
		restart();
}

void Snake::restart()
{
	serpiente.clear();
	serpiente.push_back(RectangleShape(Vector2f(size, size)));

	serpiente[0].setFillColor(Color(190, 180, 180));
	serpiente[0].setPosition(sf::Vector2f(0, int(filas/2)*size));

	isGrowing = true;

	isUp = false;
	isDown = false;
	isLeft = false;
	isRight = true;

	velocidad = 50;
}

void Snake::changeSpeed(int s, int t)
{
	velocidad += s;

	ModifSpeed a;
	a.speed = s;
	a.duracion = t;
	sf::Clock c;
	a.reloj = c;
	modificadores.push_back(a);
}

void Snake::checkCollisionsBody()
{
	for(int i(1); i < serpiente.size(); i++)
	{
		if(serpiente[0].getGlobalBounds().intersects(serpiente[i].getGlobalBounds()))
			serpiente.erase(serpiente.begin() + i, serpiente.end() -1);
	}
}
