#pragma once

#include "postac.h"	
#include "lista_zmiennych_stalych.cpp"

#include <SFML/Graphics.hpp>

using namespace sf;

class pac_man : private postac
{
public:

	pac_man(int ile_zyc = 3,
		int predkosc = 1,
		int kierunek = PRAWO,
		int xx = 331,
		int yy = 507,
		bool port = false);
	~pac_man();
	CircleShape bohater;

private:
	float x;
	float y;
	unsigned short ile_zyc;
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	//static int ile_istnieje; // ile egzempla¿y pac-mana istnieje 
	const int kolor;
};

