//Collisions.h

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <map>
#include "Entidad.h"

class Collisions
{
    public:
        enum Key
        {
            Comida,
            Potenciador
        };

    private:
        std::map<Key, Entidad *> entidades;
    
    public:
        void add(Key llave, Entidad * entity);
        void remove(Key llave);

        void check();
};

#endif
