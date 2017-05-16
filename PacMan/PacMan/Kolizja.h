#pragma once

#include "lista_zmiennych_stalych.cpp"
#include "Struktury.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>

extern class PacMan;

using namespace sf;

class Kolizja
{
public:

	Kolizja& operator = (const Kolizja &);

	Kolizja(bool = 0, bool = 0, bool = 0, bool = 0, float x = 0, float y = 0, float wielkosc = 20);
	~Kolizja();

	friend void obsluz_kolizje_mapy(Kolizja *, int, Wektor, int, int, PacMan*);
	friend void stworz_kolizje_dla_mapy(int, Kolizja *);
	friend void rysuj_kolizje(int, Kolizja *, RenderWindow *);


protected:
	void daj_wsp(float, float);
	void stworz();
	CircleShape pole_kolizji;
	float x; // wsp�rz�dne �rodka figury
	float y; // wsp�rz�dne �rodka figury

private:
	float pocz_x; // wsp�rz�dne lew. g�r. rogu figury
	float pocz_y; // wsp�rz�dne lew. g�r. rogu figury

	DostepnyKierunek DostKier;
	float wielkosc;
};
