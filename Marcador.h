//Marcador.h

#ifndef MARCADOR_H
#define MARCADOR_H

#include <SFML/Graphics.hpp>

class Marcador: public sf::Drawable
{
  public:
    Marcador(int width);
    void subirPuntuacion(int numPuntos);
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

  private:
    sf::Text txt;
    sf::Font fuente;

    int puntuacion;
};

#endif
