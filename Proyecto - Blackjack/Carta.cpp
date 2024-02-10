#include "Carta.h"

Carta::Carta() : valor(0), palo(""), puntos(0), bocaAbajo(false) {}

Carta::Carta(int valor, std::string palo, int puntos, bool bocaAbajo) //METODO CONSTRUCTOR
{
    this->valor = valor;
    this->palo = palo;
    this->puntos = puntos;
    this->bocaAbajo = bocaAbajo;
}


Carta::~Carta() {} //METODO DESTRUCTOR 

//Metodos gets y sets de los atributos de la clase


int Carta::getValor() { return  valor; }
std::string Carta::getPalo() { return palo; }
int Carta::getPuntos() { return puntos; }
bool Carta::getBocaAbajo() { return bocaAbajo; }

void Carta::setValor(int v) { valor = v; }
void Carta::setPuntos(int pu) { puntos = puntos; }
void Carta::setPalo(std::string pa) { palo = palo; }
void Carta::setBocaAbajo(bool bocaAbajo) { bocaAbajo = bocaAbajo; }

/*Metodos de la clase*/
// Hace que cambie el estado de true a false o de false a true
void Carta::voltear()
{
    if (bocaAbajo == false) {
        bocaAbajo = true;
    }
    else if (bocaAbajo == true)
        bocaAbajo = false;

}

// Por si el jugador desea cambiar el valor de la carta A
void Carta::cambiarAs(int a)
{
    if (a == 1)
    {
        valor = 1;
        puntos = 1;
    }
    if (a == 11)
    {
        valor = 11;
        puntos = 11;
    }
}


// MUESTRA EL VALOR DEL PALO Y DE LA CARTA 
std::string Carta::toString()
{
    std::stringstream s;
    if (bocaAbajo == false) {
        // Construir la cadena
        s << "+--------+" << std::endl;
        s << "| " << toStringValor() << "  | " << toStringPalo() << " |" << std::endl;
        s << "|        |" << std::endl;
        s << "| " << toStringPalo() << "  | " << toStringValor() << " |" << std::endl;
        s << "+--------+" << std::endl;
    }
    else {
        // Construir la cadena
        s << "+--------+" << std::endl;
        s << "| " << "#" << "    " << "*" << " |" << std::endl;
        s << "|        |" << std::endl;
        s << "| " << "*" << "    " << "#" << " |" << std::endl;
        s << "+--------+" << std::endl;
    }
    return s.str();
}

/*Para mostrar la figura del palo */
std::string Carta::toStringPalo()
{
    std::stringstream s;
    if (palo == "Corazones") {
        s << "\x1b[31m\x3\x1b[0m";
    }
    else if (palo == "Diamantes") {
        s << "\x1b[31m\x4\x1b[0m";
    }
    else if (palo == "Treboles") {
        s << "\x5";
    }
    else if (palo == "Picas") {
        s << "\x6";
    }
    return s.str();

}

/*Mostra el valor de la carta */
std::string Carta::toStringValor()
{
    std::stringstream s;
    if (valor > 1 && valor < 11) {
        s << valor;
    }
    else if (valor == 1) {
        s << "As";
    }
    else if (valor == 11) {
        s << "As";
    }
    else if (valor == 12) {
        s << "J";
    }

    else if (valor == 13) {
        s << "Q";
    }

    else if (valor == 14) {
        s << "K";
    }
    return s.str();

}

Carta* Carta::cargarCarta(std::string va, std::string pal, std::string punts, bool bA)
{ //se transforman los strings que recupera el archivo a entenros y devuelve la carta que corresponde
    int valor2 = convertir(va);
    /*int palo2 = convertir(pal);*/
    int puntos2 = convertir(punts);
    return new Carta(valor2, pal, puntos2, bA);

}

