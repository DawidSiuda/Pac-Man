#pragma once

#include "Postac.h"
#include "Kolizja.h"
#include "PacMan.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

class Duch :
	public Postac
{
public:
	
	
	virtual void zmienZwrotJesliMozliwe(); //zmienia kierunek ruchu postaci naprzeciwko jesli w buforze kierunku takie polecnie sie znajduje
	virtual void obsluzKolizjeZMmapa(int, Kolizja *);
	void zmianaPozycji(float, int);
	void zmianaPozycji(float, float);
	void AI(PacMan*, float);
	void zmiana_kier(int);
	float dajPredkosc();
	int smierc();
	int ladowanie_na_mape();
	int dajKierunek();
	Wektor dajXY();

	RectangleShape *cialo;

	Duch(string, int, int, float, int = 100);
	~Duch();

	friend class Kolizja;

private:
	static bool inicjalizujLosowosc;
	const short granicaStartLewo;
	const short granicaStartPrawo;
	const float odlegloscKolizjiOtoczenia;
	bool poscig; // true - poscig; false - ucieczka
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	bool obsluzWyjscie;
	float x;
	float y;
	float czasStartu;
	int kierunek;
	int predkosc;
	RectangleShape bohater;
	Texture tekstura;

};


