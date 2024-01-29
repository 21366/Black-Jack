#ifndef  Interfaz_H
#define   Interfaz_H
#include "Juego.h"

#include <thread>
#include <chrono>


class Interfaz
{
private:
	Juego* jue;
public:
	Interfaz();
	~Interfaz();
	void bienvenida();
	void salida();
	void inicio();
	void menuPrincipal();
	void menuPSol(int);
	void Reglas();
	void Opciones1();
	void pCase1();
	int  opPS();
	int  opSec();
	int  opJ();
	void resultado(int);
};



#endif // ! Interfaz_H

