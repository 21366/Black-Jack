#ifndef  Juego_H
#define Juego_H

#include "Lista.h"
class Juego
{
private: //ATRIBUTOS DE LA CLASE
	Lista* lista;
	Mazo* baraja;
public:
	//CONSTRUCTOR Y DESTRUCTOR 
	Juego();
	~Juego();
	//GETTERS
	//SETTERS
	// Metodos 
	void Inicializarbaraja();
	bool ingresarJugadores(std::string);
	void ingresarDealer();
	void agregarCarta(int);
	bool perder(int);
	bool empate(int);
	bool ganar(int);
	bool cambiarAs(int);
	void resultado();
	void salir();
	bool Guardar();
	bool Cargar();
	bool GuardarMazo();
	bool CargarMazo();
	int CantidadeJugadores();
	std::string Nombre(int);
	std::string toString();
	std::string toStringJ(int);
};
#endif // ! Juego_H




