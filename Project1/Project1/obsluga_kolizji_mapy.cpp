#pragma once

#include "mapa.h"
#include "pac_man.h"
//#include "Kolizja.h"

#include "Struktury.cpp"

#include <iostream>


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
	}
	//////////////////////////////////////////////////////////
	//sprawdzanie czy pac-man nie znajduje sie w którymœ z punktów kolizyjnych
	for (int i = 0; i < ile_kolizji; i++)
	{
		if ((mapa_kolizji[i].x + GRANICA_KOLIZJI) > pozycja_pacmana.x && (mapa_kolizji[i].x - GRANICA_KOLIZJI) < pozycja_pacmana.x)
		{
			
			//std::cout << "KKolizja" << std::endl;
			std::cout << "pac_man" << pozycja_pacmana.x << " "<< pozycja_pacmana.y  << std::endl;
			//std::cout << "obiekt nr:"<< i << " " << mapa_kolizji[i].x << " " << mapa_kolizji[i].y << std::endl;
			
			if ((mapa_kolizji[i].y + GRANICA_KOLIZJI) > pozycja_pacmana.y && (mapa_kolizji[i].y - GRANICA_KOLIZJI) < pozycja_pacmana.y)
			{
				// POPRAWIC ROZPOZNAWANIE KIERUNKÓW
				if (kier_w_bufor == LEWO)
				{
					switch (mapa_kolizji[i].rodzaj)
					{
						case LDP: 
						case LD:
						case LGDP:
						case LGD:
						case LGP:
						case LG:	
							PacMan->zmiana_kier(LEWO);
							//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
							break;
						default:
							PacMan->zmiana_kier(STOJ);
							//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x-15, (int)mapa_kolizji[i].y-15);
					}
				}else
				if (kier_w_bufor == PRAWO)
				{
					switch (mapa_kolizji[i].rodzaj)
					{
					case DP:
					case LDP:
					case GDP:
					case LGDP:
					case GP:
					case LGP:
						PacMan->zmiana_kier(PRAWO);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
						break;
					default:
						PacMan->zmiana_kier(STOJ);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
					}
				}
				else
				if (kier_w_bufor == GORA)
				{
					switch (mapa_kolizji[i].rodzaj)
					{
					case GDP:
					case LGDP:
					case LGD:
					case GP:
					case LGP:
					case LG:
						PacMan->zmiana_kier(GORA);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
						break;
					default:
						PacMan->zmiana_kier(STOJ);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
					}
				}else
				if (kier_w_bufor == DOL)
				{
					switch (mapa_kolizji[i].rodzaj)
					{
					case DP:
					case LDP:
					case LD:
					case GDP:
					case LGDP:
					case LGD:
						PacMan->zmiana_kier(DOL);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
						break;
					default:
						PacMan->zmiana_kier(STOJ);
						//PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
					}
				}
			}
		}
		
	}
}