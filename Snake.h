//Snake.h

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Trampa.h"
#include "Food.h"
#include "Marcador.h"


class Snake: public sf::Drawable, public Entidad
{
	private:
		std::vector<sf::RectangleShape> serpiente;
		bool aMovido;

		bool isUp, isDown, isLeft, isRight;
		bool isGrowing;

		sf::Clock reloj;

		void restart(); //reinicia el estado de la serpiente

		Marcador puntos;

		int velocidad;

		//Vector con el tiempo restante de un modificador y la velocidad que ha modificado
		struct ModifSpeed
		{
			int speed;
			sf::Time tiempo;
		};
		std::vector<ModifSpeed> modificadores;

	public:
		Snake(int f, int c, int s);
		void move();
		void grow();
		void update();

		void goUp();
		void goDown();
		void goLeft();
		void goRight();

		void changeSpeed(int s, int t = 10);

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
		virtual sf::FloatRect getCollisionBox() const override;
		virtual void collisionDetected(Entidad & entity) override;
};

#endif
