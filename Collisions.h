//Collisions.h

#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <vector>
#include "Entidad.h"

class Collisions
{
    private:
        std::vector<Entidad *> entidades;
    
    public:
        void add(Entidad & entity);
        //void remove(Key llave);

        void check();
};

#endif
