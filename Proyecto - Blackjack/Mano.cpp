#include "Mano.h"
Mano::Mano() //METODO CONSTRUCTOR
{
	can = 0;
	tam = 52;
	vecmano = new Carta * [tam];
	for (int i = 0; i < tam; i++) {
		vecmano[i] = nullptr;
	}
}

Mano::~Mano()
{
	delete[] vecmano;
}

/*Metodos de la clase*/
/*Agrega una carta del mazo y cantidad aumenta  */
void Mano::agregarCartaMazo(Mazo* mazo)
{
	if (can < tam) {
		vecmano[can++] = mazo->TomarCarta();
	}
}


void Mano::borrar() // limpiar la mano 
{
	for (int i = 0; i < can; i++)
	{
		vecmano[i] = nullptr;
	}
	can = 0;
}

int Mano::getPuntos() // Para saber la el numero de el puntos que tiene cada carta
{
	int puntos = 0;
	for (int i = 0; i < can; i++)
	{
		if (vecmano[i]->getBocaAbajo() == false)
			puntos = puntos + vecmano[i]->getPuntos();
	}
	return puntos;
}

//Para que la carta del dealer quede boca abajo
void Mano::voltearCarta()
{
	vecmano[1]->voltear();
}


/*Para cambiar el As y saber que lo tiene 
Si si tiene As retorna true */
bool Mano::CambiarAs()
{
	for (int i = 0; i < can; i++)
	{
		if (vecmano[i]->getValor() == 1)
		{
			vecmano[i]->cambiarAs(11);
			return true;
		}
		else if (vecmano[i]->getValor() == 11) {
			vecmano[i]->cambiarAs(1);
			return true;
		}
	}
	return false;
}

std::string Mano::toString()
{
	std::stringstream s;
	if (can == 0)
	{
		return "La mano esta vacia";
	}
	for (int i = 0; i < can; i++)
	{
		s << vecmano[i]->toString();
	}
	return s.str();
}




