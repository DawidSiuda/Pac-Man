#include "mapa.h"



mapa::mapa(std::string nazwa_bitmapy, int pozycja_poczatkowa_x, int pozycja_poczatkowa_y, int przesuniecie_w_dol)
{
	tekstura.loadFromFile(nazwa_bitmapy);
	Obraz.setTexture(tekstura);
	Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));
	//Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));
}

mapa::~mapa()
{
}
