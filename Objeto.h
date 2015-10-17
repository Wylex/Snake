//Objeto.h

#ifndef OBJETO_H
#define OBJETO_H

#include "Entidad.h"
//#include "Trampa.h"
//#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <memory>

template <typename T>
class Objeto: public Entidad, public sf::Drawable
{

    protected:

        //shared_ptr<sf::Shape> objeto;
        T objeto;
        bool collision;
        sf::Clock reloj;
        Entidad * entidad;

    public:
        Objeto(int f, int c, int s);

        double radio;

        void update();
  
        double getPosicion();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

template <typename T>
Objeto<T>::Objeto(int f, int c, int s): Entidad(f, c, s)
{
    //radio = size/2.0;

    //comida.setPointCount(3);
    //comida.setRadius(radio);

    //comida.setFillColor(sf::Color(90, 120, 180));

    srand(time(0));

    int num1 = rand() % filas;
    int num2 = rand() % columnas;

    objeto.setPosition(num2 * size, num1 * size);

    collision = false;
}

template <typename T>
void Objeto<T>::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(objeto, states);
}

template <typename T>
sf::FloatRect Objeto<T>::getCollisionBox() const
{
    return objeto.getGlobalBounds();
}

template <typename T>
void Objeto<T>::collisionDetected(Entidad & entity)
{
    entidad = &entity;

    if(!collision)
        reloj.restart();

    collision = true;
}

template <typename T>
void Objeto<T>::update()
{
}

template <typename T>
double Objeto<T>::getPosicion()
{
  return (objeto.getPosition().x * objeto.getPosition().y);
} 

#endif
