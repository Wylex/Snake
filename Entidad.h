//Entidad.h

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <typeinfo>

class Entidad: public sf::Drawable//, public Observer
{
	protected:
		int filas;
		int columnas;
		int size;

	public:
		Entidad(int f, int c, int s) {filas = f; columnas = c; size = s;}
		virtual sf::FloatRect getCollisionBox() const = 0;
		virtual void collisionDetected(Entidad & entity) = 0;
		//virtual void getNotification(Entidad & entity);
		//virtual double getPosicion() = 0;
};

#endif
