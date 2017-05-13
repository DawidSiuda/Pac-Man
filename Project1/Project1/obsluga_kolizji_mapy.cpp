#pragma once

#include "mapa.h"
#include "pac_man.h"
//#include "Kolizja.h"

#include "Struktury.cpp"

#include <iostream>
/*
void obsluz_kolizje_mapy(Kolizja *,
	int ,
	Wektor ,
	int ,
	int ,
	pac_man* = NULL);
*/

void obsluz_kolizje_mapy(Kolizja *mapa_kolizji,
						int ile_kolizji,
						Wektor pozycja_pacmana,
						int kierunek,
						int kier_w_bufor,
						pac_man *PacMan)
{
	if (kierunek != kier_w_bufor)
	{
		//////////////////////////////////////////////////////////
		// obs³uga  buforu z kierunkami przeciwnymi do aktualnych
		if (kierunek == GORA && kier_w_bufor == DOL)
		{
			PacMan->zmiana_kier(DOL);
		}
		else
		if (kierunek == DOL && kier_w_bufor == GORA)
		{
			PacMan->zmiana_kier(GORA);
		}
		else
		if (kierunek == LEWO && kier_w_bufor == PRAWO)
		{
			PacMan->zmiana_kier(PRAWO);
		}
		else
		if (kierunek == PRAWO && kier_w_bufor == LEWO)
		{
			PacMan->zmiana_kier(LEWO);
		}
		
		//////////////////////////////////////////////////////////
		//sprawdzanie czy pac-man nie znajduje sie w którymœ z punktów kolizyjnych
		for (int i = 0; i < ile_kolizji; i++)
		{
			//int a = mapa_kolizji[i].x;
		}
	}
}