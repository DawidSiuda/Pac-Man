#pragma once

#include "Struktury.cpp"
#include "Kolizja.h"
#include "BialyPunkt.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class MapaPunktow
{
public:

	void tworzMapePunktow(Kolizja*, int);
	void rysuj(RenderWindow *);

	BialyPunkt *dajMape();
	int ilePunktow();

	MapaPunktow();
	~MapaPunktow();

private:
	void robPunkty(int, int, int, int);
	BialyPunkt *mapaKropek;
	int ileKropek;
};

