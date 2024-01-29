#ifndef Mazo_H
#define Mazo_H
#include "Carta.h"

class Mazo {
private:
	Carta** vecar;
	int can;
	int tam;
public:
	Mazo();
	~Mazo();
	void Inicializa();
	void Barajar();
	Carta* TomarCarta();
	void cambiarAs();
	void borrar();
	std::string toString();
};



#endif // !Mazo_H


