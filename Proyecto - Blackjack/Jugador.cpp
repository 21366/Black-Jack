#include "Jugador.h"

Jugador::Jugador()
{
	nickname = "Jugador";
	mano = new Mano;
}

Jugador::Jugador(std::string n)
{
	nickname = n;
	mano = new Mano;
}

Jugador::~Jugador(){}

//Metodos gets y sets de los atributos de la clase
void Jugador::setNickname(std::string nic) { nickname = nic; }
std::string Jugador::getNickname() { return nickname; }
Mano* Jugador::getMano() { return mano; }


void Jugador::pedirCartaM(Mazo* n)
{
	mano->agregarCartaMazo(n);
}

// Para saber cuando se pasa de 21
bool Jugador::sePaso(JugadorGenerico* n)
{
	if (n->getMano()->getPuntos() > 21) {
		return true;
	}
	return false;
}


//Mostar los cartas de cada jugador 
std::string Jugador::toString()
{
	std::stringstream s;
	s << "\t" << nickname << std::endl << std::endl;
	s << mano->toString() << std::endl;
	s << "Los puntos del jugador son: " << mano->getPuntos() << std::endl;
	return s.str();
}

void Jugador::guardarJuga(std::ofstream& file)
{
	file << nickname << '\n'; //Guarda el nombre del jugador
}

Jugador* Jugador::CargarJuga(std::string file)
{
	 return new Jugador(file); //crea y retorna un jugador
}





