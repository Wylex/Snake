//Subject.cpp

#include "Subject.h"

void Subject::add(Entidad & entity)
{
	entidades.push_back(&entity);
}

void Subject::remove(Entidad & entity)
{
	for(int i(0); i < entidades.size(); i++)
	{
		if(entidades[i] == &entity)
			entidades.erase(entidades.begin() + i);
	}
}

/*void Subject::notify(Entidad & entity)
{
	//for(int i(0); i < entidades.size(); i++)
		//entidades[i]->getNotification(entity);
}*/
