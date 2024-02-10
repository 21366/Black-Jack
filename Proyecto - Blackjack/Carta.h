#include <sstream> 
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include "Convertir.h"
#ifndef Carta_H
#define  Carta_H

class Carta
{
private: //ATRIBUTOS DE LA CLASE 
	int valor;
	std::string palo;
	int puntos;
	bool bocaAbajo;
public:
	//CONSTRUCTOR Y DESTRUCTOR 
	Carta();
	Carta(int, std::string, int, bool);

	virtual ~Carta();

	//GETTERS
	int getValor();
	std::string getPalo();
	int getPuntos();
	bool getBocaAbajo();

	//SETTERS
	void setValor(int);
	void setPuntos(int);
	void setPalo(std::string);
	void setBocaAbajo(bool);

	// Metodos 
	void voltear();
	void cambiarAs(int);
	//toString
	std::string toString();
	std::string toStringPalo();
	std::string toStringValor();
	static Carta* cargarCarta(std::string, std::string, std::string, bool); //metodo para archivos (carga carta)

};


#endif // !Carta_H

