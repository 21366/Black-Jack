#ifndef Nodo_H  
#define Nodo_H 
#include "JugadorGenerico.h"
#include "Dealer.h"
#include "Jugador.h"

class Nodo {
private:  //ATRIBUTOS DE LA CLASE 
	Nodo* next;
	JugadorGenerico* jugador;
public:
	//CONSTRUCTOR Y DESTRUCTOR 
	Nodo();
	Nodo(Nodo*, JugadorGenerico*);
	~Nodo();
	//GETTERS
	Nodo* getSiguiente();
	JugadorGenerico* getJugador();
	//SETTERS
	void setJugador(JugadorGenerico&);
	void setSiguiente(Nodo*);

};

#endif 



