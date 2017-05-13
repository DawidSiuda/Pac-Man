#pragma once

#include "lista_zmiennych_stalych.cpp"

class postac
{
public:
	postac(float = 0, int = LEWO);
	~postac();

protected:
	float predkosc; // piksel/sekunde
	int kierunek; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
	int kierunek_w_buforze; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
							// kierunek w którym pójdzie kiedy bedzie mia³ tak¹ mo¿liwoœæ


};

