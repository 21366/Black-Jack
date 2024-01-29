#include "Lista.h"

Lista::Lista() :inicio{ nullptr } {}

Lista::~Lista() {
	Nodo* aux = inicio;
	while (aux != nullptr) {
		inicio = aux->getSiguiente();
		delete aux;
		aux = inicio;
	}
}

//Metodos gets  de los atributos de la clase
Nodo* Lista::getInicio() {return inicio;}

void Lista::setInicio(Nodo* aux){inicio = aux;}



/*Metodos */

/*Ingresar el jugador de primero siempre*/
void Lista::InsertarDePrimero(JugadorGenerico* jug) {
	inicio = new Nodo(inicio, jug);

}
/*Ingresar el jugador de de ultimo*/
bool Lista::InsertarDeUltimo(JugadorGenerico* jug)
{
	Nodo* aux = inicio;
	//si el primero esta vacio ingresa el nodo junto al jugador
	if (inicio == nullptr) {
		InsertarDePrimero(jug);
		return true;
	}
	//si la lista no esta vacia recorre hasta que el siguiente sea null y mete el nodo junto al jugador
	else {
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		if (NombreRepetido(jug) != true) {
			aux->setSiguiente(new Nodo(nullptr, jug));
			return true;
		}
		else {
			return false;
		}


	}
}

/*Verificar si el nombre del jugador ya existe*/
bool Lista::NombreRepetido(JugadorGenerico* jug)
{
	//verifica si es repétido, si lo es retorna true, de lo contrario false
	Nodo* aux = inicio;

	while (aux != nullptr) {
		if (jug->getNickname() == aux->getJugador()->getNickname()) {
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

/*Saber cuantos jugadores tiene*/
int Lista::cantidadJugadores()
{
	Nodo* tmp = inicio;
	int cont = 0;
	while (tmp != nullptr) {
		cont++;
		tmp = tmp->getSiguiente();
	}
	return cont;

}

Nodo* Lista::buscar(int posicion)
{
	if (posicion < 0 || posicion >= cantidadJugadores()) {
		return nullptr;
	}

	// Se recorre la lista hasta llegar a la posición indicada.
	Nodo* tmp = getInicio();
	for (int i = 0; i < posicion; i++) {
		tmp = tmp->getSiguiente();
	}
	return tmp;
}


/*Borrar un jugador en especifico*/
bool Lista::Borrar(JugadorGenerico* jug) {
	Nodo* aux = inicio;
	Nodo* anterior = nullptr;
	//si es el primero elimina el nodo y el jugador
	if (inicio != nullptr && inicio->getJugador() == jug) {
		Nodo* actual = inicio;
		inicio = actual->getSiguiente();
		delete actual;
		return true;
	}
	//si no es el primero recorre la lista hasta encontrar una coincidencia, acomoda los enlaces y borra el Nodo deseado
	else {
		while (aux != nullptr && aux->getJugador() != jug) {
			anterior = aux;
			aux = aux->getSiguiente();
		}
		anterior->setSiguiente(aux->getSiguiente());
		delete aux;
		return true;
	}
	return false;

}

// Para saber si la lista esta vacia 
/*  Devuelve true si esta vacia y false si esta llena */
bool Lista::listaVacia() {
	return (inicio == nullptr);
}

/*Borrar todos los jugadores*/
void Lista::Eliminar()
{
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->getSiguiente();
		delete tmp;
	}
}

/*Mostar los jugadores */
std::string Lista::toString() {
	std::stringstream s;
	Nodo* tmp = inicio;
	while (tmp != nullptr) {
		s << tmp->getJugador()->toString() << std::endl;
		tmp = tmp->getSiguiente();
	}
	return s.str();

}
