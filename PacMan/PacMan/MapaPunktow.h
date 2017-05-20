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

	MapaPunktow();
	~MapaPunktow();

private:
	BialyPunkt *mapaKropek;
	int ileKropek;
};

