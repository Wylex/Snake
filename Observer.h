//Observer.h

#ifndef OBERVER_H
#define OBERVER_H

#include "Entidad.h"

class Observer
{
	virtual void collisionDetected(Entidad & entity) = 0;
};

#endif
