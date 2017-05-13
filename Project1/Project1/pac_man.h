#pragma once

#include "postac.h"	
#include "lista_zmiennych_stalych.cpp"
#include "Kolizja.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class pac_man : public postac
{
public:
	void zmiana_pozycji(float,int);
	void zmiana_pozycji(float);
	void zmiana_kierunku(int);
	Shape *cialo;

	pac_man(int ile_zyc = 3,
			float predkosc = 1,
			int kierunek = PRAWO,
			float xx = 110,
			float yy = 110,
			bool port = false);
	~pac_man();

	friend class Kolizja;

private:
	Texture tekstura;
	CircleShape bohater;
	float x;
	float y;
	unsigned short ile_zyc;
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	//static int ile_istnieje; // ile egzempla¿y pac-mana istnieje 
	const int kolor;
};

