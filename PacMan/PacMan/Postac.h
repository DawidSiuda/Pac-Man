#pragma once

#include "Lista_zmiennych_stalych.cpp"

extern class Mapa;
extern class Kolizja;

class Postac
{
public:
	float dajPredkosc();
	virtual void zmienZwrotJesliMozliwe() = 0;
	virtual void obsluzKolizjeZMmapa(int, Kolizja *) = 0;
	Postac(float = 0, int = LEWO);
	~Postac();

protected:
	float predkosc; // piksel/sekunde
	int kierunek; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
	int kierunek_w_buforze; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
							// kierunek w którym pójdzie kiedy bedzie mia³ tak¹ mo¿liwoœæ


};
