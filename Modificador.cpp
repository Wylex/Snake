//Modificador.cpp

#include "Modificador.h"

Modificador::Modificador(int f, int c, int s): Objeto(f, c, s)
{
	objeto.setRadius(size/2.0);

	objeto.setFillColor(sf::Color(67, 222, 113));
}

void Modificador::update()
{
	if(collision)
	{
		if(typeid(Trampa) == typeid(*entidad))
		{
			updatePosition();

			collision = false;
		}
		else if(typeid(Food) == typeid(*entidad))
		{
			updatePosition();

			collision = false;
		}
		else if(typeid(Snake) == typeid(*entidad))
		{
			updatePosition();

			collision = false;
			static_cast<Snake *>(entidad)->changeSpeed(10);
		}
	}
}
