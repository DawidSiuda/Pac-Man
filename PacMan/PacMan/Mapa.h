#pragma once

#include "Kolizja.h"
#include "PacMan.h"
#include "Struktury.cpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace sf;
using namespace std;

class Mapa
{
public:

	const short pozycja_x; // x w którym rozpoczyna siê mapa w oknie g³ównym
	const short pozycja_y; // y w którym rozpoczyna siê mapa w oknie g³ównym

	int wczytajMapeZPliku(string = "mapa.txt");
	int iloscKolizji();						//zwraca ilosc kolizji zdefiniowanych na mapie
	void rysuj_kolizje(RenderWindow *okno); //rysuje punkty kolizyjne mapy, w oknie do którego podano mu wska¿nik
	bool WczytanoMape();					//zwraca wartosc bool "WczytywanieZakonczonePowodzeniem"
	Kolizja *dajMapeKolizji();				//zwraca mape kolizji planszy
	Sprite rysuj();							//zwraca wielok¹t w którym wyswietlana jest mapa
	Wektor dajStartPacMan();				//zwraca pozycje startow¹ pacmana pobrana z pliku .txt z mapa

	Mapa(int pozycja_poczatkowa_x = 0,
		int pozycja_poczatkowa_y = 0);
	~Mapa();

	friend class Kolizja;
	

private:

	int rozmiarMapyX;
	int rozmiarMapyY;
	int ileKolizji;
	float StartBohateraX;
	float StartBohateraY;
	bool WczytywanieZakonczonePowodzeniem;
	
	Sprite Obraz; //wielok¹t w którym wyswietlana jest mapa
	Texture tekstura;//obraz mapy pobierany z pliku jpg
	string nazwaMapy;
	Kolizja *mapaKolizjiZPliku;

	bool sprawdzCzyliczba(string);//sprawdza czy string przechowuje liczbe
};

