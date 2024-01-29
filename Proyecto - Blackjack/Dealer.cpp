#include "Dealer.h"

Dealer::Dealer()
{
	nickname = "Dealer";
	mano = new Mano;
}
Dealer::Dealer(std::string n)
{
	nickname = n;
	mano = new Mano;
}
Dealer::~Dealer() {}

//Metodos gets y sets de los atributos de la clase
void Dealer::setNickname(std::string nic) { nickname = nic; }
std::string Dealer::getNickname() { return nickname; }
Mano* Dealer::getMano() { return mano; }


//Metodos 
void Dealer::pedirCartaM(Mazo* n)
{

	mano->agregarCartaMazo(n);

}

// Para saber cuando se pasa de 21
bool Dealer::sePaso(JugadorGenerico* n)
{
	if (n->getMano()->getPuntos() > 21) {
		return true;
	}
	return false;
}

//Mostar los cartas de cada jugador 
std::string Dealer::toString()
{
	std::stringstream s;
	s << "\t" << nickname << std::endl << std::endl;
	s << mano->toString() << std::endl;
	s << "Los puntos del jugador son: " << mano->getPuntos() << std::endl;
	return s.str();
}








