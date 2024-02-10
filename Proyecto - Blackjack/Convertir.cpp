#include "Convertir.h"


int convertir(std::string aux) {
	std::stringstream s(aux);
	int v;
	s >> v;
	return v;
}

bool convertirBool(std::string aux) {
	std::stringstream a(aux);
	int j;
	a >> j;
	return j;
}
