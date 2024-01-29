#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	nickname = "";
	mano = new Mano;
}

JugadorGenerico::JugadorGenerico(std::string n)
{
	nickname = n;
	mano = new Mano;
}

JugadorGenerico::~JugadorGenerico()
{
	if (mano != nullptr)
		delete mano;
}
