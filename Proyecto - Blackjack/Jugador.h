
#ifndef Jugador_H
#define Jugador_H
#include "JugadorGenerico.h"

class Jugador :public JugadorGenerico
{
public:
	//CONSTRUCTOR Y DESTRUCTOR
	Jugador();
	Jugador(std::string);
	virtual~Jugador();
	//GETTERS y SETTERS
	virtual void setNickname(std::string);
	virtual std::string getNickname();
	virtual Mano* getMano();
	// Metodos
	virtual void pedirCartaM(Mazo*);
	virtual bool sePaso(JugadorGenerico* n);
	virtual std::string toString();
};

#endif // !Jugador






