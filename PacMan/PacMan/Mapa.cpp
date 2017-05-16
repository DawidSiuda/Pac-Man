#include "Mapa.h"


Kolizja * Mapa::daj_mape_kolizji()
{
	return mapa_kolizji;
}

Sprite Mapa::rysuj()
{
	return Obraz;
}

Mapa::Mapa(std::string nazwa_bitmapy, int pozycja_poczatkowa_x, int pozycja_poczatkowa_y, int przesuniecie_w_dol)
	:pozycja_x(pozycja_poczatkowa_x),
	pozycja_y(pozycja_poczatkowa_y)
{
	tekstura.loadFromFile(nazwa_bitmapy);
	Obraz.setTexture(tekstura);
	Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));

	stworz_kolizje_dla_mapy(65, mapa_kolizji);

	//Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));
}

Mapa::~Mapa()
{
}
