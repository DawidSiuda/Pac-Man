#pragma once

#include "postac.h"
#include "Kolizja.h"

class ghost : public postac 
{
public:
	int smierc();
	int ladowanie_na_mape();
	void rysuj();
	ghost();
	~ghost();

	friend class Kolizja;
private:
	static int ile_istnieje;
	bool poscig; // true - poscig; false - ucieczka
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu

};

