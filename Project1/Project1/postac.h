#pragma once

#include "lista_zmiennych_stalych.cpp"

class postac
{
public:
	postac(float = 0, int = LEWO);
	~postac();

protected:
	float predkosc; // piksel/sekunde
	int kierunek; // 1 - g�ra, 2 - lewo, 3 - d�, 4 - lewo
	int kierunek_w_buforze; // 1 - g�ra, 2 - lewo, 3 - d�, 4 - lewo
							// kierunek w kt�rym p�jdzie kiedy bedzie mia� tak� mo�liwo��


};

