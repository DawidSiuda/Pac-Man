#pragma once

#include "PacMan.h"
#include "BialyPunkt.h"
#include "MapaPunktow.h"

extern class Kolizja;

void obsluzBuforRuchu(Postac* postac)
{
	postac->zmienZwrotJesliMozliwe();
}

void obsluzKolizjeMapy(Postac * postac, int ilosc, Kolizja *mapa)
{
	postac->obsluzKolizjeZMmapa(ilosc, mapa);
}

void obsluzKolizjeKropek(PacMan * pacman, BialyPunkt *mapaKropek, int ileKropek , MapaPunktow *mapaPunktow)
{
	int pacmanX = pacman->daj_xy().x;
	int pacmanY = pacman->daj_xy().y;
	//std::cout << ileKropek << std::endl;
	for (int i = 0; i < ileKropek; i++)
	{
		if (mapaKropek[i].dajXY().y < pacmanY + 5 && mapaKropek[i].dajXY().y > pacmanY - 5)
		{
			if (mapaKropek[i].dajXY().x < pacmanX + 5 && mapaKropek[i].dajXY().x > pacmanX - 5)
			{
				if (mapaKropek[i].czyist() == true)
				{
					//std::cout << " I ate it ";
					
					mapaKropek[i].usunPunkt();
					mapaPunktow->zmiejszLiczbeKropek(1);
				}
				
			}
		}
	}
}

bool obsluzkolizjePacman_duchy(Wektor pacman, Wektor czerwony, Wektor niebieski, Wektor rozowy, Wektor pomaranczowy)
{
	if (pacman.x  + WIELKOSC > czerwony.x +15  && pacman.x  - WIELKOSC  < czerwony.x+15)
	{
		if (pacman.y + WIELKOSC > czerwony.y+15  && pacman.y  - WIELKOSC  < czerwony.y +15)
		{
			//cout << "smierc" << endl;
			return true;
		}
			
	}

	return false;
}