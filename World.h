//World.h

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <memory>
#include <vector>
#include "Snake.h"
#include "Collisions.h"
#include "InputHandler.h"
#include "Command.h"
#include "Food.h"
#include "Modificador.h"
#include "Trampa.h"
#include "FPS.h"
#include "Wall.h"

class World
{
	private:
		sf::RenderWindow window;
		int state;

		//Game
		bool pause;

		FPS framesPS;
		Trampa trap;
		Snake serpiente; 
		Food comida;
		Modificador modif;

		Collisions choques;

		InputHandler impHandler; 

		//Menu
		sf::Texture textura;
		sf::Sprite sprite;

		//Pause Menu
		sf::Font fnt;
		sf::Text txt;


	private:
		void startGame();
		void startMenu();
		void startMapCreation();

	public:
		World();
		void start();

		static const unsigned int filas = 35;
		static const unsigned int columnas = 45;
		static const unsigned int size = 15;
		static const unsigned int width = size * columnas;
		static const unsigned int height = size * filas;
};

#endif
