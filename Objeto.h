//Objeto.h

#ifndef OBJETO_H
#define OBJETO_H

#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <memory>

template <typename T>
class Objeto: public Entidad, public sf::Drawable
{
    protected:
        T objeto;
        bool collision;
        sf::Clock reloj;
        Entidad * entidad;
        
    protected:
        void updatePosition();  

    public:
        Objeto(int f, int c, int s);

        virtual void update();
  
        virtual double getPosicion();

        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
        virtual sf::FloatRect getCollisionBox() const override;
        virtual void collisionDetected(Entidad & entity) override;
};

template <typename T>
Objeto<T>::Objeto(int f, int c, int s): Entidad(f, c, s)
{
    srand(time(0));

    updatePosition();

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

template <typename T>
void Objeto<T>::updatePosition()
{
  int num1 = rand() % filas;
  int num2 = rand() % columnas;

  objeto.setPosition(num2 * size, num1 * size);
}

#endif
