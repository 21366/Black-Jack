#include "Mazo.h"

Mazo::Mazo()
{
	can = 0;
	tam = 52;
	vecar = new Carta * [tam];
	for (int i = 0; i < tam; i++) { // limpar el vector 
		vecar[i] = nullptr;
	}
}

Mazo::~Mazo()
{
	for (int i = 0; i < can; i++) {
		delete vecar[i];
	}
	delete[] vecar;
	can = 0;
	tam = 0;
}

// Inicaliza el mazo  con los diferentes valor 
void Mazo::Inicializa()
{
	if (can < tam) {
		for (int valor = 1; valor <= 14; ++valor) { // para los 13 valores de las cartas 
			for (const std::string& palo : { "Corazones", "Diamantes", "Treboles", "Picas" }) { // para los cuatro tipos de palo que tiene las cartas
				if (valor <= 10) // por si su valor es menor a 10 para el puntaje 
					vecar[can++] = new Carta(valor, palo, valor, false);
				else if (valor >= 12) {  // por si su valor es mayor a 12 para el puntaje sea 10 
					vecar[can++] = new Carta(valor, palo, 10, false);
				}
			}
		}
	}
}


/*Para barajar el mazo*/

void Mazo::Barajar()
{
	// Generador de números aleatorios
	// Distribución uniforme para generar índices aleatorios entre 0 y 51
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> aleatorios(0, can);
	// Bucle para recorrer todas las cartas del mazo
	for (int i = 0; i < can; i++) {
		// Obtener un índice aleatorio entre 0 y 51
		int j = aleatorios(rng);
		// Intercambiar las cartas en las posiciones i y j
		Carta* temp = vecar[i];
		vecar[i] = vecar[j];
		vecar[j] = temp;
	}
}

/*Para cuando el usario piede una carta*/
Carta* Mazo::TomarCarta()
{
	if (can > 0) {
		return vecar[--can];// Devuelve la última carta y decrementa can 
	}
	else {
		return nullptr; // El mazo está vacío
	}

}

/*Para cuando el usario piede cambiar sus As*/
void Mazo::cambiarAs()
{
	for (int i = 0; i < can; i++)
	{
		// si la carta tiene un valor de 1 lo cambio por 11 
		if (vecar[i]->getValor() == 1)
			vecar[i]->cambiarAs(11);
		// si la carta tiene un valor de 11 lo cambio por 1 
		else if (vecar[i]->getValor() == 11) {
			vecar[i]->cambiarAs(1);
		}
	}
}


/*Borrar el mazo */
void Mazo::borrar()
{
	for (int i = 0; i < can; i++)
	{
		vecar[i] = nullptr;

	}
	can = 0;

}


std::string Mazo::toString()
{
	std::stringstream s;
	if (can == 0)
	{
		s << "El mazo esta vacio" << std::endl;
	}
	else
	{
		for (int i = 0; i < can; i++)
		{
			s << vecar[i]->toString() << std::endl;
			s << can << std::endl;
		}
	}
	return s.str();
}


