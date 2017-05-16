#pragma once

#include "Kolizja.h"
#include "PacMan.h"
#include "Struktury.cpp"

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Mapa
{
public:

	Kolizja *daj_mape_kolizji();// zwraca mape kolizji planszy
	Sprite rysuj(); //zwraca wielok¹t w którym wyswietlana jest mapa

	const short pozycja_x; // x w którym rozpoczyna siê mapa w oknie g³ównym
	const short pozycja_y; // y w którym rozpoczyna siê mapa w oknie g³ównym

	Mapa(std::string nazwa_bitmapy,
		int pozycja_poczatkowa_x = 0,
		int pozycja_poczatkowa_y = 0,
		int przesuniecie_w_dol = 0 // nie dzia³a
	);
	~Mapa();

	friend class Kolizja;
	friend void stworz_kolizje_dla_mapy(int, Kolizja*);
	friend void obsluz_kolizje_mapy(Kolizja*, int, Wektor, int, int, PacMan*);

private:

	Kolizja mapa_kolizji[ILE_KOLIZJI]; //tablica przechowuj¹ca mape kolizji danej mapy
	Sprite Obraz; //wielok¹t w którym wyswietlana jest mapa
	Texture tekstura;//obraz mapy pobierany z pliku jpg
};

