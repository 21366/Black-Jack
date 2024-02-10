#ifndef  JugadorGenerico_H
#define JugadorGenerico_H
#include "Mano.h"

class JugadorGenerico
{
protected: //ATRIBUTOS DE LA CLASE 
	std::string nickname;
	Mano* mano;
public:
	//CONSTRUCTOR Y DESTRUCTOR 
	JugadorGenerico();
	JugadorGenerico(std::string);
	virtual~JugadorGenerico();
	//Metodos para sus clases derivadas
	virtual void setNickname(std::string) = 0;
	virtual std::string getNickname() = 0;
	virtual Mano* getMano() = 0;
	virtual void guardarJuga(std::ofstream&) = 0;
	virtual void pedirCartaM(Mazo*) = 0;
	virtual bool sePaso(JugadorGenerico* n) = 0;
	virtual std::string toString() = 0;
};


#endif // ! JugadorGenerico_H



