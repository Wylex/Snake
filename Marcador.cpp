//Marcador.cpp

#include "Marcador.h"
#include <string>

Marcador::Marcador(int width)
{
  puntuacion = 0;

  fuente.loadFromFile("Ressources/Font.ttf");
  txt.setFont(fuente);
  txt.setPosition(width/2 - 20, 10);
  txt.setColor(sf::Color::White);
  txt.setCharacterSize(20);

  txt.setString(std::to_string(puntuacion));
}

void Marcador::subirPuntuacion(int numPuntos)
{
  puntuacion += 10 * numPuntos;
  txt.setString(std::to_string(puntuacion));
}

void Marcador::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
        target.draw(txt, states);
}
