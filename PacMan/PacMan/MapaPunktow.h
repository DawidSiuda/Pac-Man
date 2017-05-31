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
	void zmiejszLiczbeKropek(int);
	int ilePunktow();
	int dajProcent();
	BialyPunkt *dajMape();

	MapaPunktow();
	~MapaPunktow();

private:
	void robPunkty(int, int, int, int);
	float procentDoKonca;
	int ileKropek;
	int ileKropekZjadl;
	BialyPunkt *mapaKropek;
};

