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

	const short pozycja_x; // x w kt�rym rozpoczyna si� mapa w oknie g��wnym
	const short pozycja_y; // y w kt�rym rozpoczyna si� mapa w oknie g��wnym

	int wczytajMapeZPliku(string = "mapa.txt");
	int iloscKolizji();						//zwraca ilosc kolizji zdefiniowanych na mapie
	void rysuj_kolizje(RenderWindow *okno); //rysuje punkty kolizyjne mapy, w oknie do kt�rego podano mu wska�nik
	bool WczytanoMape();					//zwraca wartosc bool "WczytywanieZakonczonePowodzeniem"
	Kolizja *dajMapeKolizji();				//zwraca mape kolizji planszy
	Sprite rysuj();							//zwraca wielok�t w kt�rym wyswietlana jest mapa
	Wektor dajStartPacMan();				//zwraca pozycje startow� pacmana pobrana z pliku .txt z mapa

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
	
	Sprite Obraz; //wielok�t w kt�rym wyswietlana jest mapa
	Texture tekstura;//obraz mapy pobierany z pliku jpg
	string nazwaMapy;
	Kolizja *mapaKolizjiZPliku;

	bool sprawdzCzyliczba(string);//sprawdza czy string przechowuje liczbe
};

