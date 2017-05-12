#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class mapa
{
public:
	//void laduj_nowa();
	//void rysuj();
	//void pasuza();
	Sprite Obraz;
	Texture tekstura;

	mapa(std::string nazwa_bitmapy,
		int pozycja_poczatkowa_x = 0,
		int pozycja_poczatkowa_y = 0,
		int przesuniecie_w_dol = 0 // nie dzia³a
		);
	~mapa();

private:
	//int 
	//bool pauza; // true - pauza; false - trwa rozgrywka
	//int wysokosc;//px
	//int szerokosc; //px
	//int ile_kulek;
};

