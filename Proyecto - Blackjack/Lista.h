#ifndef Lista_H
#define Lista_H
#include "Nodo.h"

class Lista
{
private: //ATRIBUTOS DE LA CLASE
	Nodo* inicio;
public:
	//CONSTRUCTOR Y DESTRUCTOR 
	Lista();
	~Lista();
	//GETTERS
	Nodo* getInicio();
	void setInicio(Nodo*);
	//Metodos 
	void InsertarDePrimero(JugadorGenerico*);
	bool InsertarDeUltimo(JugadorGenerico*);
	bool NombreRepetido(JugadorGenerico*);
	int cantidadJugadores();
	bool guardarLista();
	bool cargarLista();
	bool guardarManoJ();
	bool CargarManoJ();
	Nodo* buscar(int);
	bool Borrar(JugadorGenerico*);
	bool listaVacia();
	void Eliminar();

	std::string toString();
};

#endif 



