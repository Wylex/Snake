//Collisions.cpp

#include "Collisions.h"

void Collisions::check() 
{
	for(int i(0); i < entidades.size(); i++)
	{
		for(int b(i + 1); b < entidades.size(); b++)
		{
			if(entidades[i]->getCollisionBox().intersects(entidades[b]->getCollisionBox()))
			{
				entidades[i]->collisionDetected(*entidades[b]);
				entidades[b]->collisionDetected(*entidades[i]);
			}
		}
	}
}
