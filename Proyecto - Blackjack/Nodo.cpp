#include "Nodo.h"

#include "Nodo.h"

Nodo::Nodo() : next(nullptr), jugador(nullptr)  { }

Nodo::Nodo(Nodo* ne, JugadorGenerico* dat)   
{
	next = ne;
	jugador = dat;
}

Nodo::~Nodo() {
	if (jugador != nullptr) {
		delete jugador;
	}
}

Nodo* Nodo::getSiguiente() { return next; } // conocer la direccion  del siguiente nodo
void Nodo::setSiguiente(Nodo* n) { next = n; }
JugadorGenerico* Nodo::getJugador() { return jugador; }

void  Nodo::setJugador(JugadorGenerico& da) {
	if (next != nullptr) { delete next; } // si ya exite persona en este nodo que lo elimine
	jugador = (JugadorGenerico*)&da;
}

