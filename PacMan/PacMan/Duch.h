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
	Duch();
	~Duch();

	friend class Kolizja;
private:
	static int ile_istnieje;
	bool poscig; // true - poscig; false - ucieczka
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu

};


