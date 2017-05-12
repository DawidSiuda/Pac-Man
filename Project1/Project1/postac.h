#pragma once

#include "lista_zmiennych_stalych.cpp"

class postac
{
public:
	postac(float = 0, int = LEWO);
	~postac();

private:
	float predkosc;
	int kierunek; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo


};

