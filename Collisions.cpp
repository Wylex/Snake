//Collisions.cpp

#include "Collisions.h"

void Collisions::add(Key llave, Entidad entity)
{
    entidades.insert(std::pair<Key, Entidad>(llave, entity));    
}

void Collisions::remove(Key llave)
{
    entidades.erase(llave);
}
