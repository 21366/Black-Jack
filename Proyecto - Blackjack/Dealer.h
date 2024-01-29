#ifndef Dealer_H
#define Dealer_H
#include "JugadorGenerico.h"

class Dealer :public JugadorGenerico
{
public:
	//CONSTRUCTOR Y DESTRUCTOR
	Dealer();
	Dealer(std::string);
	virtual~Dealer();
	//GETTERS y SETTERS
	virtual void setNickname(std::string);
	virtual std::string getNickname();
	virtual Mano* getMano();
	// Metodos
	virtual void pedirCartaM(Mazo*);
	virtual bool sePaso(JugadorGenerico* n);
	virtual std::string toString();
};

#endif // !Dealer





