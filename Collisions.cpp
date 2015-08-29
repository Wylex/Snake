//Collisions.cpp

#include "Collisions.h"

void Collisions::add(Key llave, Entidad * entity)
{
    entidades.insert(std::pair<Key, Entidad *>(llave, entity));    
}

void Collisions::remove(Key llave)
{
    entidades.erase(llave);
}

void Collisions::check() 
{
    for(auto i(entidades.begin()); i != entidades.end(); i++) 
    {
        auto b(i);
        for(auto a(++b); a != entidades.end(); a++)
        {
            if(i->second->getCollisionBox().intersects(a->second->getCollisionBox()))
            {
                i->second->collisionDetected(*a->second);
                a->second->collisionDetected(*i->second);
            }
        }
    }
}
