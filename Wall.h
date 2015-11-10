//Wall.h

#ifndef WALL_H
#define WALL_H

#include <vector>
#include "Entidad.h"

class Wall: public Entidad, public sf::Drawable
{
	public:
		Wall(int f, int c, int s, int length, int x, int y, bool hori);
		virtual sf::FloatRect getCollisionBox() const override;
		virtual void collisionDetected(Entidad & entity) override;

		//Funciones para la edición del mapa
		void rotate();
		void move(int i);
		void grow();
		void decrease();

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		//virtual double getPosicion() override;

	private:
		std::vector<sf::RectangleShape> objeto;

		int xPos;
		int yPos;
		int numberSquares;
		bool horizontal;
};

#endif
