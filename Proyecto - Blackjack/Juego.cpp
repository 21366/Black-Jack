#include "Juego.h"


Juego::Juego()
{
	//crea una baraja y una lista de jugadores automaticamente
	baraja = new Mazo();
	lista = new Lista();
}

Juego::~Juego()
{
	if (lista != nullptr) { delete lista; }
	if (baraja != nullptr) { delete baraja; }
}

/*Inicializar la baraja para el juego*/
void Juego::Inicializarbaraja()
{
	baraja->Inicializa();
	baraja->Barajar();
}

/*Ingresar jugador con sus dos cartas*/
bool Juego::ingresarJugadores(std::string nic)
{

	JugadorGenerico* aux = new Jugador(nic);
	if (lista->InsertarDeUltimo(aux) == true) {
		for (int i = 0; i < 2; i++) {
			aux->pedirCartaM(baraja);
		}
		return true;
	}
	else
		return false;
}

/*Ingresar dealer con sus dos cartas*/
void Juego::ingresarDealer()
{
	JugadorGenerico* aux = new Dealer();
	lista->InsertarDePrimero(aux);
	for (int i = 0; i < 2; i++) {
		aux->pedirCartaM(baraja);
	}
	aux->getMano()->voltearCarta();
}

/*Por si el usario desea un carta mas */
void Juego::agregarCarta(int posicion)
{
	Nodo* tmp = lista->buscar(posicion); // para saber que jugador es 
	tmp->getJugador()->pedirCartaM(baraja);
}


/*Si se paso retorna true */
bool Juego::perder(int posicion)
{
	// Buscar al jugador en la posición dada
	Nodo* tmp = lista->buscar(posicion);
	return tmp->getJugador()->sePaso(tmp->getJugador());
}

/*Si  es empate retorna true*/
bool Juego::empate(int posicion)
{
	Nodo* tmp = lista->buscar(posicion);
	Nodo* tmp2 = lista->buscar(0);
	if (tmp2->getJugador()->getMano()->getPuntos() == tmp->getJugador()->getMano()->getPuntos()) {
		return true;
	}
	else {
		return false;
	}
}
// para saber quien gano se los otras condiciones no se dan 
bool Juego::ganar(int posicion)
{
	Nodo* tmp = lista->buscar(posicion);
	Nodo* tmp2 = lista->buscar(0);
	/*Si gana el jugador retorno true */
	if (tmp->getJugador()->getMano()->getPuntos() > tmp2->getJugador()->getMano()->getPuntos() && perder(posicion) == false) {
		return true;
	}
	/*Si gana el dealer retorno false */
	else if (tmp->getJugador()->getMano()->getPuntos() < tmp2->getJugador()->getMano()->getPuntos() && perder(0) == false) {
		return false;
	}
}

// por si el jugador quiere camniar sus As 
bool Juego::cambiarAs(int posicion)
{
	Nodo* tmp = lista->buscar(posicion);
	if (tmp->getJugador()->getMano()->CambiarAs() == true)
	{
		return true;
	}
	else {
		return false;
	}
}

// para mostrar la carta del dealer oculta y si tiene menos de 17 que le den cartas 
void Juego::resultado()
{
	Nodo* tmp = lista->buscar(0);
	tmp->getJugador()->getMano()->voltearCarta();
	while (tmp->getJugador()->getMano()->getPuntos() < 17) {
		tmp->getJugador()->getMano()->agregarCartaMazo(baraja);
	}
}


void Juego::salir()
{
	baraja->borrar();
	lista->Eliminar();
}
bool Juego::Guardar()
{
	if (lista->guardarLista() == true && lista->guardarManoJ() == true && GuardarMazo() == true) {
		return true;
	}
	else {
		return false;
	}
}
bool Juego::Cargar()
{

	if (lista->cargarLista() == true && lista->CargarManoJ() == true && CargarMazo() == true) {
		baraja->Barajar();
		return true;
	}
	else {
		return false;
	}
}

bool Juego::GuardarMazo()
{
	std::ofstream file;
	std::string nickname;
	//para facilidad de recuperacion y separacion se crea un archivo por cada mano de jugador
	nickname = "../Mazo.txt"; //Se crea el nombre del archivo junto con el nombre de cada jugador 
	file.open(nickname, std::ios::out); //se abre el archivo
	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
		return false;
	}
	baraja->guardarMazo(file);
	file.close(); //se cierra el archivo 

	return true;
}
bool Juego::CargarMazo()
{
	std::ifstream file;
	std::string nickname;
	nickname = "../Mazo.txt";
	file.open(nickname); //se abre el archivo
	if (!file.is_open()) {
		std::cout << "Error al abrir el archivo...\n";
		return false;
	}
	baraja->cargarMazo(file);
	file.close(); //se cierra el archivo
	return true;
}
int Juego::CantidadeJugadores()
{
	return lista->cantidadJugadores();
}

// para saber el nombre del usario 
std::string Juego::Nombre(int posicion)
{
	std::stringstream s;
	Nodo* tmp = lista->buscar(posicion);
	s << tmp->getJugador()->getNickname() << std::endl;
	return s.str();
}

std::string  Juego::toString()
{
	std::stringstream s;
	s << lista->toString() << std::endl;
	return s.str();
}

std::string Juego::toStringJ(int posicion)
{
	std::stringstream s;
	Nodo* tmp = lista->buscar(posicion);
	Nodo* tmp1 = lista->buscar(0);
	s << tmp1->getJugador()->toString() << std::endl;
	s << tmp->getJugador()->toString() << std::endl;
	return s.str();
}

