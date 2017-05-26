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
	RectangleShape *cialo;

	int smierc();
	float dajPredkosc();
	void zmianaPozycji(float, int);
	void zmianaPozycji(float, float);
	int dajKierunek();
	void AI(PacMan*);

	int ladowanie_na_mape();
	virtual void zmienZwrotJesliMozliwe(); //zmienia kierunek ruchu postaci naprzeciwko jesli w buforze kierunku takie polecnie sie znajduje
	virtual void obsluzKolizjeZMmapa(int, Kolizja *);
	void zmiana_kier(int);

	Duch(string, int, int, float, int = 100);
	~Duch();

	friend class Kolizja;

private:
	static bool inicjalizujLosowosc;
	const short granicaStartLewo;
	const short granicaStartPrawo;
	bool poscig; // true - poscig; false - ucieczka
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	RectangleShape bohater;
	Texture tekstura;
	float x;
	float y;
	float czasStartu;
	//Clock clock;
	int kierunek;
	int predkosc;
	const float odlegloscKolizjiOtoczenia;

};


