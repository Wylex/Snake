//Wall.cpp

#include "Wall.h"

Wall::Wall(int f, int c, int s, int length, int x, int y, bool hori): Entidad(f, c, s)
{
	xPos = x;
	yPos = y;
	numberSquares = length;
	horizontal = hori;

	for(int i(0); i < numberSquares; i++)
	{
		if(horizontal)
		{
			objeto.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
			objeto[i].setPosition(x + i*s, y);
		}
		if(!horizontal)
		{
			objeto.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
			objeto[i].setPosition(x, y + i*s);
		}

		objeto[i].setFillColor(sf::Color(102, 51, 0));
	}
}

void Wall::rotate()
{
	sf::Vector2f pos = objeto[0].getPosition();

	if(horizontal)
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].setPosition(sf::Vector2f(pos.x, pos.y + i*size));	

		horizontal = false;
	}
	else if(!horizontal)
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].setPosition(sf::Vector2f(pos.x + i*size, pos.y));	

		horizontal = true;
	}
}

void Wall::move(int i)
{
	if(i == 1)
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].move(-size, 0);
	}
	else if(i == 2)
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].move(0, size);
	}
	else if(i == 3)
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].move(0, -size);
	}
	else
	{
		for(int i(0); i < numberSquares; i++)
			objeto[i].move(size, 0);
	}
}

sf::FloatRect Wall::getCollisionBox() const 
{
}

void Wall::collisionDetected(Entidad & entity)
{
}

void Wall::grow()
{
	sf::Vector2f pos = objeto[0].getPosition();

	if(horizontal)
	{
		objeto.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
		objeto[objeto.size() -1].setPosition(pos.x + numberSquares*size, pos.y);
	}
	else
	{
		objeto.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
		objeto[objeto.size() -1].setPosition(pos.x, pos.y + numberSquares*size);
	}

	objeto[numberSquares].setFillColor(sf::Color(102, 51, 0));

	numberSquares++;
}

void Wall::decrease()
{
	if(numberSquares > 1)
	{
		objeto.pop_back();
		numberSquares--;
	}
}

void Wall::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(int i(0); i < objeto.size(); i++)
		target.draw(objeto[i], states);
}

/*double Wall::getPosicion()
{
}

void Wall::updatePosition()
{
}*/
