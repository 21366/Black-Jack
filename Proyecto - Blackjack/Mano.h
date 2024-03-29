#ifndef Mano_h
#define Mano_h
#include "Mazo.h"

class Mano
{
private: //ATRIBUTOS DE LA CLASE 
	Carta** vecmano;
	int can;
	int tam;
public:
	//CONSTRUCTOR Y DESTRUCTOR
	Mano();
	~Mano();
	// Metodos 
	void agregarCartaCarta(Carta*);
	void agregarCartaMazo(Mazo*);
	void borrar();
	int getPuntos();
	void voltearCarta();
	bool CambiarAs();
	std::string toString();
	void guardarMano(std::ofstream&);
	void cargarMano(std::ifstream&);
};

#endif // !Mano_h

