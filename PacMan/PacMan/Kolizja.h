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

	DostepnyKierunek dajKierunki();
	Wektor dajXY();
	void usunKierunek(int);

	Kolizja& operator = (const Kolizja &);

	Kolizja(bool = 0, bool = 0, bool = 0, bool = 0, float x = 0, float y = 0, float wielkosc = 20);
	~Kolizja();

	friend void obsluz_kolizje_mapy(Kolizja *, int, Wektor, int, int, PacMan*);
	friend class Mapa;
	friend class PacMan;
	friend class Duch;


protected:
	void daj_wsp(float, float);
	void stworz();
	CircleShape pole_kolizji;
	float x; // wspó³rzêdne œrodka figury
	float y; // wspó³rzêdne œrodka figury

private:
	float pocz_x; // wspó³rzêdne lew. gór. rogu figury
	float pocz_y; // wspó³rzêdne lew. gór. rogu figury

	DostepnyKierunek DostKier;
	float wielkosc;
};

