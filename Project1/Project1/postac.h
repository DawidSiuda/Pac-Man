#pragma once

#include "lista_zmiennych_stalych.cpp"

class postac
{
public:
	postac(float = 0, int = LEWO);
	~postac();

private:
	float predkosc;
	int kierunek; // 1 - g�ra, 2 - lewo, 3 - d�, 4 - lewo


};

