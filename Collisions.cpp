//Collisions.cpp

#include "Collisions.h"
#include <iostream>

void Collisions::add(Entidad & entity)
{
    entidades.push_back(&entity);
}

/*void Collisions::remove(Key llave)
{
    entidades.erase(llave);
}*/

void Collisions::check() 
{
    for(int i(0); i < entidades.size(); i++)
    {
        for(int b(i); b < entidades.size(); b++)
        {
            if(entidades[i]->getCollisionBox().intersects(entidades[b]->getCollisionBox()))
            {
                entidades[i]->collisionDetected(*entidades[b]);
                entidades[b]->collisionDetected(*entidades[i]);
            }
        }
    }
}
