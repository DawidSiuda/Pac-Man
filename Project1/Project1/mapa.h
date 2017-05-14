#pragma once

#include "Kolizja.h"
#include "pac_man.h"
#include "Struktury.cpp"

#include <SFML/Graphics.hpp>
#include <string>



using namespace sf;

class mapa
{
public:

	Kolizja *daj_mape_kolizji();// zwraca mape kolizji planszy

	Sprite rysuj();
	const short pozycja_x;
	const short pozycja_y;

	mapa(std::string nazwa_bitmapy,
		int pozycja_poczatkowa_x = 0,
		int pozycja_poczatkowa_y = 0,
		int przesuniecie_w_dol = 0 // nie dzia³a
		);
	~mapa();

	friend class Kolizja;
	friend void stworz_kolizje_dla_mapy(int, Kolizja*);
	friend void obsluz_kolizje_mapy(Kolizja*, int , Wektor , int , int, pac_man*);

private:

	Kolizja mapa_kolizji[ILE_KOLIZJI];
	Sprite Obraz;
	Texture tekstura;
};

