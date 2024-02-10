#include "Interfaz.h"

Interfaz::Interfaz()
{
	jue = new Juego;
}

Interfaz::~Interfaz()
{
	delete jue;
}

void Interfaz::bienvenida()
{
	// Mostrar el mensaje de bienvenida con las cartas
	std::cout << "\t""Bienvenido al emocionante juego de Blackjack\n\n";
	std::cout << " _________     _________     _________     _________\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|    2    |   |    J    |   |    7    |   |    A    |\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|    \x1b[31m\x3\x1b[0m    |   |    \x5    |   |    \x1b[31m\x4\x1b[0m    |   |    \x6    |\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|_________|   |_________|   |_________|   |_________|\n\n";

	// Dormir durante 3 segundos 
	std::this_thread::sleep_for(std::chrono::seconds(3));;
	// Limpiar la pantalla
	system("cls");

}

void Interfaz::salida()
{
	// Mostrar el mensaje de bienvenida con las cartas
	std::cout << "\t""¡Gracias por jugar Blackjack!\n\n";
	std::cout << " _________     _________     _________     _________\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|    Q    |   |    4    |   |    8    |   |    K    |\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|    \x1b[31m\x3\x1b[0m    |   |    \x5    |   |    \x1b[31m\x4\x1b[0m    |   |    \x6    |\n";
	std::cout << "|         |   |         |   |         |   |         |\n";
	std::cout << "|_________|   |_________|   |_________|   |_________|\n\n";

	// Dormir durante 3 segundos 
	std::this_thread::sleep_for(std::chrono::seconds(3));;
	// Limpiar la pantalla
	system("cls");
}

void Interfaz::menuPrincipal()
{

	const std::string azul = "\033[1;34m";
	const std::string blanco = "\033[0m";
	std::cout << azul << "======================" << blanco << std::endl;
	std::cout << "   MENU PRINCIPAL" << std::endl;
	std::cout << azul << "======================" << blanco << std::endl;
	std::cout << "[1] Nueva partida" << std::endl;
	std::cout << "[2] Cargar partida" << std::endl;
	std::cout << "[3] Salir" << std::endl;
	std::cout << azul << "======================" << blanco << std::endl;


}

void Interfaz::inicio()
{
	int opcion = 0;
	bienvenida();
	while (opcion != 3)
	{
		menuPrincipal();
		opcion = opPS();
		menuPSol(opcion);
		system("cls");
	}
}


int Interfaz::opPS()
{
	int aux = 0;
	bool valido = false;
	std::string input;

	while (!valido) {
		std::cout << "Ingrese una opcion: ";
		std::cin >> input;
		std::stringstream ss(input);
		if (ss >> aux && ss.eof()) {
			if (aux > 0 && aux <= 3) {
				valido = true;
			}
			else {
				std::cout << "Opcion fuera de rango. Debe elegir entre 1 y 3." << std::endl;
			}
		}
		else {
			std::cout << "Entrada no valida. Debe ingresar un numero entre 1 y 3." << std::endl;
		}
	}
	return aux;
}

int Interfaz::opSec()
{
	int aux = 0;
	bool valido = false;
	std::string input;

	while (!valido) {
		std::cout << "Ingrese una opcion: ";
		std::cin >> input;
		std::stringstream ss(input);
		if (ss >> aux && ss.eof()) {
			if (aux > 0 && aux <= 5) {
				valido = true;
				std::cout << "aux "<<aux;
			}
			else {
				std::cout << "Opcion fuera de rango. Debe elegir entre 1 y 5." << std::endl;
			}
		}
		else {
			std::cout << "Entrada no valida. Debe ingresar un numero entre 1 y 5." << std::endl;
		}
	}
	return aux;
}

int Interfaz::opJ()
{
	int aux = 0;
	bool valido = false;
	std::string input;
	while (!valido) {
		std::cout << "Cuantos jugadores quieren unirse a la partida? (Maximo 6) ";
		std::cin >> input;
		std::stringstream ss(input);
		if (ss >> aux && ss.eof()) {
			if (aux > 0 && aux <= 6) {
				valido = true;
			}
			else {
				std::cout << "Opcion fuera de rango. Debe elegir entre 1 y 5." << std::endl;
			}
		}
		else {
			std::cout << "Entrada no valida. Debe ingresar un numero entre 1 y 5." << std::endl;
		}
	}
	return aux;
}


void Interfaz::menuPSol(int op)
{
	switch (op) {
	case 1:
		pCase1();
		system("pause");
		break;
	case 2:
		Cargar();
		system("pause");
		break;
	case 3:
		system("cls");
		salida();
		break;
	}
}

void Interfaz::Reglas()

{
	const std::string azul = "\033[1;34m";
	const std::string blanco = "\033[0m";
	std::cout << azul << "=======================================================" << blanco << std::endl;
	std::cout << "\t""\t" "Hola a todos " << std::endl;
	std::cout << "Antes de empezar, vamos a repasar las reglas del juego:" << std::endl;
	std::cout << azul << "=======================================================" << blanco << std::endl << std::endl;

	std::cout << "- Hay un maximo de 6 jugadores por partida." << std::endl;
	std::cout << "- Cada jugador debe tener un apodo unico." << std::endl;
	std::cout << "- Para saber quien gana, todos los jugadores deben terminar su turno." << std::endl;

}

void Interfaz::Opciones1()
{
	std::cout << "[1] Pedir Carta   -   [2] Pasar   -  [3] Cambiar valor de A   -  [4] Guardar Partida  -  [5] Salir " << std::endl << std::endl;
}

void Interfaz::pCase1()
{
	system("cls");
	int aux = 0;
	int aux1 = 0;
	int conta = 1;
	std::string nickname = "";
	bool valido = false;

	jue->salir();
	jue->Inicializarbaraja();
	jue->ingresarDealer();
	Reglas();
	system("Pause");
	system("cls");
	aux = opJ();
	for (int i = 0; i < aux; i++) {
		std::cout << " Jugador " << i + 1 << ", introduce tu nickname: ";
		std::cin >> nickname;
		while (jue->ingresarJugadores(nickname) == false) {
			std::cout << "El nickname ya esta en uso. Por favor, elige otro: ";
			std::cin >> nickname;
		}
	}
	do {
		std::cout << jue->toStringJ(conta) << std::endl;
		Opciones1();
		aux1 = opSec();
		system("cls");
		if (aux1 == 1) {
			jue->agregarCarta(conta);
			std::cout << jue->toStringJ(conta) << std::endl;
		}
		if (aux1 == 2) {
			if (conta < aux) {
				conta++;
				std::cout << "Es tu turno, " << jue->Nombre(conta) << std::endl;
			}
			else if (conta = aux) {
				system("cls");
				std::cout << "La partida esta completa." << std::endl;
				std::cout << "A continuacion, se mostraran los resultados de la partida:" << std::endl;
				system("pause");
				resultado(aux);
				system("pause");
				system("cls");
				aux1 = 5;
			}
		}
		if (aux1 == 3) {
			if (jue->cambiarAs(conta) == true) {
				system("cls");
				std::cout << "Cambio realizado con éxito." << std::endl;
			}
			else if (jue->cambiarAs(conta) == false) {
				std::cout << "No tienes As" << std::endl;
			}
		}
		if (aux1 == 4) {
			if (jue->Guardar() == true) {
				std::cout << "Guardado con exito" << std::endl;
			}
			else {
				std::cout << "Guardado sin exito" << std::endl;
			}
		}
		if (aux1 == 5) {
			std::cout << "Gracias por jugar!" << std::endl;
			jue->salir();
		}
	} while (aux1 != 5);

}

void Interfaz::Cargar()
{
	system("cls");
	int aux = 0;
	int aux1 = 0;
	int conta = 1;
	bool valido = false;
	jue->salir();
	if (jue->Cargar() == true) {
		Reglas();
		system("Pause");
		system("cls");
		aux = jue->CantidadeJugadores() - 1;
		do {
			std::cout << jue->toStringJ(conta) << std::endl;
			Opciones1();
			aux1 = opSec();
			system("cls");
			if (aux1 == 1) {
				jue->agregarCarta(conta);
				std::cout << jue->toStringJ(conta) << std::endl;
			}
			if (aux1 == 2) {
				if (conta < aux) {
					conta++;
					std::cout << "Es tu turno, " << jue->Nombre(conta) << std::endl;
				}
				else if (conta = aux) {
					system("cls");
					std::cout << "La partida esta completa." << std::endl;
					std::cout << "A continuacion, se mostraran los resultados de la partida:" << std::endl;
					system("pause");
					resultado(aux);
					system("pause");
					system("cls");
					aux1 = 5;
				}
			}
			if (aux1 == 3) {
				if (jue->cambiarAs(conta) == true) {
					system("cls");
					std::cout << "Cambio realizado con éxito." << std::endl;
				}
				else if (jue->cambiarAs(conta) == false) {
					std::cout << "No tienes As" << std::endl;
				}
			}
			if (aux1 == 4) {
				if (jue->Guardar() == true) {
					std::cout << "Guardado con exito" << std::endl;
				}
				else {
					std::cout << "Guardado sin exito" << std::endl;
				}
			}
			if (aux1 == 5) {
				std::cout << "Gracias por jugar!" << std::endl;
				jue->salir();
			}
		} while (aux1 != 5);
	}
	else {
		std::cout << "No es posible cargar una partida" << std::endl;
	}
}

void Interfaz::resultado(int aux)
{

	jue->resultado();
	system("cls");
	std::cout << jue->toString() << std::endl;
	for (int i = 1; i <= aux; i++) {
		if (jue->perder(i) == true) {
			std::cout << "Jugador: " << jue->Nombre(i);
			std::cout << "Perdiste, tus puntos son mayores a 21." << std::endl << std::endl << std::endl;
		}
		else if (jue->empate(i) == true) {
			std::cout << "Jugador: " << jue->Nombre(i);
			std::cout << "Empate." << std::endl;
		}
		else if (jue->ganar(i) == true) {
			std::cout << "Jugador: " << jue->Nombre(i);
			std::cout << " Felicidades, ganaste." << std::endl << std::endl;
		}
		else if (jue->ganar(i) == false) {
			std::cout << "Jugador: " << jue->Nombre(i);
			std::cout << "Lo siento, perdiste. Tienes menos puntos que el dealer." << std::endl << std::endl;
		}
	}
}


