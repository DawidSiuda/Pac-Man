#pragma once

#include "PacMan.h"

extern class Kolizja;

void obsluzBuforRuchu(Postac* postac)
{
	postac->zmienZwrotJesliMozliwe();
}

void obsluzKolizjeMapy(Postac * postac, int ilosc, Kolizja *mapa)
{
	postac->obsluzKolizjeZMmapa(ilosc, mapa);
}
