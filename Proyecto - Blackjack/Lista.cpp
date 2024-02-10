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
void Lista::guardarLista()
{

	std::ofstream file;
	Nodo* aux = inicio;
	file.open("../Jugadores.txt"); //abre archivo
	if (file.is_open()) { //verifica si se abrio bien
		while (aux != nullptr) { //recorre la lista
			aux->getJugador()->guardarJuga(file); //llama al metodo para guardar el jugador en ese nodo
			aux = aux->getSiguiente(); // pasa al siguiente nodo
		}
	}
	else {
		std::cout << "No se abrio el archivo" << std::endl;
	}
	file.close(); //cierra el archivo
}

void Lista::cargarLista()
{
	std::ifstream file;
	std::string tipo = "";
	file.open("../Jugadores.txt"); //abre el archivo
	if (file.is_open()) { //verifica si abrio
		while (getline(file, tipo, '\n')) { //lee la primera linea
			if (tipo == "CASA") { //si en la variable tipo se guardo CASA el objeto se carga como dealer y se almacena como tal
				JugadorGenerico* aux = Dealer::CargarDealer(tipo);
				if (aux->getNickname() != "") { // verifica si se cargo correctamente
					InsertarDeUltimo(aux);
				}
			}
			else { //si no es CASA se ingresa como jugador
				JugadorGenerico* aux2 = Jugador::CargarJuga(tipo);
				if (aux2->getNickname() != "") { //verifica si se cargo correctamente
					InsertarDeUltimo(aux2); //se ingresa

				}

			}

		}

	}
	else {
		std::cout << "No se abrio el archivo" << std::endl;
	}
	file.close(); //se cierra el archivo
}


void Lista::guardarManoJ()
{

	Nodo* aux = inicio;
	std::ofstream file;
	std::string nickname;
	//para facilidad de recuperacion y separacion se crea un archivo por cada mano de jugador
	while (aux != nullptr) { // se crea un while para que avance hacia el siguiente jugador 

		nickname = "../Mano" + aux->getJugador()->getNickname() + ".txt"; //Se crea el nombre del archivo junto con el nombre de cada jugador 
		file.open(nickname); //se abre el archivo
		if (!file.is_open()) {
			std::cout << "Error al abrir el archivo...\n";
		}
		aux->getJugador()->getMano()->guardarMano(file); //se guarda la mano
		aux = aux->getSiguiente();// se pasa al siguiente jugador
		file.close(); //se cierra el archivo 
	}
}

void Lista::CargarManoJ()
{//funciona igual que la funcion guardar 
	Nodo* aux = inicio;
	std::ifstream file;
	std::string nickname;
	while (aux != nullptr) {
		nickname = "..\Mano" + aux->getJugador()->getNickname() + ".txt";
		file.open(nickname); //se abre el archivo
		if (!file.is_open()) {
			std::cout << "Error al abrir el archivo...\n";

		}
		aux->getJugador()->getMano()->cargarMano(file); //se guarda lal mano
		aux = aux->getSiguiente(); //se pasa al siguiente jugador
		file.close(); //se cierra el archivo
	}
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
