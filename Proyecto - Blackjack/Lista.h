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
	void guardarLista();
	void cargarLista();
	void guardarManoJ();
	void CargarManoJ();
	Nodo* buscar(int);
	bool Borrar(JugadorGenerico*);
	bool listaVacia();
	void Eliminar();

	std::string toString();
};

#endif 



