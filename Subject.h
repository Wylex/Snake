//Subject.h

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Entidad.h"
#include <vector>

class Subject
{
	protected:
		std::vector<Entidad *> entidades;

	public:
		void add(Entidad & entity);
		void remove(Entidad & entity);

	protected:
		//void notify(Entidad & entity);
};

#endif
