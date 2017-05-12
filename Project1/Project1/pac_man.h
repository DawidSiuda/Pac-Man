#pragma once
#include "postac.h"	

class pac_man : private postac
{
public:
	void rysuj();
	void obsluz_klawiature();
	void smierc();
	

	pac_man();
	~pac_man();

private:
	unsigned short ile_zyc;
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	static int ile_istnieje;

	int zjedz_ducha();
	int zjedz_kulke();
};

