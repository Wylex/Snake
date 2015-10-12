//Entidad.h

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <typeinfo>

class Entidad
{
    protected:
        unsigned int filas;
        unsigned int columnas;
        unsigned int size;

    public:
        Entidad(int f, int c, int s) {filas = f; columnas = c; size = s;}
        virtual sf::FloatRect getCollisionBox() const = 0;
        virtual void collisionDetected(Entidad & entity) = 0;
        //virtual double getPosicion() = 0;
};

#endif
