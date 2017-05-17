#pragma once

#include "Postac.h"
#include "Kolizja.h"

class Duch :
	public Postac
{
public:
	int smierc();
	int ladowanie_na_mape();
	void rysuj();
	virtual void zmienZwrotJesliMozliwe(); //zmienia kierunek ruchu postaci naprzeciwko jesli w buforze kierunku takie polecnie sie znajduje
	virtual void obsluzKolizjeZMmapa(int, Kolizja *);
	void zmiana_kier(int);
	Duch();
	~Duch();

	friend class Kolizja;

private:

	bool poscig; // true - poscig; false - ucieczka
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu

};


