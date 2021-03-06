//World.cpp

#include "World.h"
#include <string>

using namespace sf;

#include <iostream>

World::World(): window(VideoMode(width, height), "Snake"), impHandler(), framesPS("Ressources/Font.ttf"), 
comida(filas, columnas, size), serpiente(filas, columnas, size), trap(filas, columnas, size), modif(filas, columnas, size)
{
	pause = false;

	choques.add(serpiente);
	choques.add(comida);
	choques.add(trap);
	choques.add(modif);

	textura.loadFromFile("Ressources/Menu.png");
	sprite.setTexture(textura);

	state = 0;

	//Cargar texto "PAUSE"
	fnt.loadFromFile("Ressources/Porter Bold.ttf");
	txt.setFont(fnt);
	txt.setColor(sf::Color(25, 50, 0));
	txt.setCharacterSize(75);
	txt.setString("PAUSE");
	sf::FloatRect frct = txt.getGlobalBounds();
	txt.setPosition(sf::Vector2f(width/2 - frct.width/2, height/2 - frct.height/2));
}

void World::start()
{
	while(window.isOpen())
	{
		if(state == 0)
			startMenu();
		else if(state == 1)
			startGame();
		else if(state == 2)
			startMapCreation();
	}
}

void World::startGame()
{
	std::shared_ptr<Command> comando = impHandler.handleInput(window);
	if(comando != 0)
	{
		if(typeid(pauseCommand) == typeid(*comando))
		{
			if(pause)
				pause = false;
			else if(!pause)
				pause = true;
		} 
		else
			comando->execute(serpiente);
	}

	if(!pause)
	{
		serpiente.update();
		comida.update();
		trap.update();
		modif.update();

		choques.check();
	}
	framesPS.update();


	window.clear();
	window.draw(trap);
	window.draw(comida);
	window.draw(modif);
	window.draw(serpiente);
	window.draw(framesPS);
	if(pause)
		window.draw(txt);
	window.display();
}

void World::startMenu()
{
	Event event;

	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::G)
					state = 1;
				else if(event.key.code == sf::Keyboard::C)
					state = 2;
				break;
		}
	}

	window.clear();
	window.draw(sprite);
	window.display();
}

void World::startMapCreation()
{
	Event event;

	static int wallNumber(-1);
	static bool showGrille = false;	
	static int xPos = 0;
	static int yPos = 0;
	static std::vector<Wall> muros;

	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::G)
					state = 0;
				//Nuevo muro
				else if(event.key.code == sf::Keyboard::A)
					{
						if(wallNumber >= 0)
							muros[wallNumber].toggleColor();

						muros.push_back(Wall(filas, columnas, size, 1, xPos, yPos, true));
						wallNumber = muros.size() -1;
						muros[wallNumber].toggleColor();
					}
				//Movimientos muro
				if(wallNumber!= -1)
				{
					if(event.key.code == sf::Keyboard::H){
						muros[wallNumber].move(1);
						xPos -= size;}
					else if(event.key.code == sf::Keyboard::J){
						muros[wallNumber].move(2);
						yPos += size;}
					else if(event.key.code == sf::Keyboard::K){
						muros[wallNumber].move(3);
						yPos -= size;}
					else if(event.key.code == sf::Keyboard::L){
						muros[wallNumber].move(4);
						xPos += size;}
					//Crecer
					else if(event.key.code == sf::Keyboard::U)
						muros[wallNumber].grow();
					//Disminuir
					else if(event.key.code == sf::Keyboard::D)
						muros[wallNumber].decrease();
					//Rotar
					else if(event.key.code == sf::Keyboard::R)
						muros[wallNumber].rotate();
				}
				//change focus
				if(event.key.code == sf::Keyboard::N)
				{
					if(wallNumber >= 0)
					{
						muros[wallNumber].toggleColor();//Cambia el color del anterior muro seleccionado

						wallNumber++;
						if(wallNumber >= muros.size())
							wallNumber = 0;

						muros[wallNumber].toggleColor();//Cambio el color del muro seleccionado actualmente
					}
				}
				else if(event.key.code == sf::Keyboard::P)
				{
					if(wallNumber >= 0)
					{
						muros[wallNumber].toggleColor();//Cambia el color del anterior muro seleccionado

						wallNumber--;
						if(wallNumber < 0)
							wallNumber = muros.size() -1;

						if(wallNumber >= 0)
							muros[wallNumber].toggleColor();//Cambio el color del muro seleccionado actualmente
					}
				}
				//Mostrar tabla
				else if(event.key.code == sf::Keyboard::S)
				{
					if(showGrille)
						showGrille = false;
					else
						showGrille = true;
				}	
				break;
		}
	}

	window.clear();
	for(int i(0); i < muros.size(); i++)
		window.draw(muros[i]);
	if(showGrille)
		drawGrid();
	window.display();

}

void World::drawGrid()
{
	static int i = 0;
	static sf::RectangleShape lineasVerticales[columnas + 1];
	static sf::RectangleShape lineasHorizontales[filas + 1];

	if(i == 0)
	{
		i++;

		//Posicionar lineas verticales
		for(int i(0); i < columnas +1; i++)
		{
			lineasVerticales[i].setSize(sf::Vector2f(1, filas*size));
			lineasVerticales[i].setPosition(sf::Vector2f(size*i, 0));
			lineasVerticales[i].setFillColor(sf::Color(230, 220, 220));
		}
		lineasVerticales[columnas].move(-1, 0);

		//Posicionar lineas horizontales
		for(int i(0); i < filas +1; i++)
		{
			lineasHorizontales[i].setSize(sf::Vector2f(columnas*size, 1));
			lineasHorizontales[i].setPosition(sf::Vector2f(0, size*i));
			lineasHorizontales[i].setFillColor(sf::Color(230, 220, 220));
		}
		lineasHorizontales[filas].move(0, -1);
	}	

	//Draw lines
	for(int i(0); i < columnas +1; i++)
		window.draw(lineasVerticales[i]);
	for(int i(0); i < filas +1; i++)
		window.draw(lineasHorizontales[i]);
}
