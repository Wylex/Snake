//Modificador.h

#ifndef MODIF_H
#define MODIF_H

#include "Objeto.h"
#include "Snake.h"
#include "Trampa.h"
#include "Food.h"

class Modificador: public Objeto<sf::CircleShape>
{
  public:
        Modificador(int f, int c, int s);

        void update();
};

#endif
