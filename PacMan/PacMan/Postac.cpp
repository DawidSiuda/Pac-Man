#include "Postac.h"


float Postac::dajPredkosc()
{
	return predkosc;
}

Postac::Postac(float pre, int kier)
{
	predkosc = pre;
	kierunek = kier;
	kierunek_w_buforze = kier;
}


Postac::~Postac()
{
}

