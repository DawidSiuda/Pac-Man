#pragma once

#include "mapa.h"
#include "pac_man.h"

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
			//std::cout << "pac_man " << pozycja_pacmana.x << " "<< pozycja_pacmana.y  << std::endl;
			//std::cout << "obiekt nr:"<< i << " " << mapa_kolizji[i].x << " " << mapa_kolizji[i].y << std::endl;
			

				if ((mapa_kolizji[i].y + GRANICA_KOLIZJI) > pozycja_pacmana.y && (mapa_kolizji[i].y - GRANICA_KOLIZJI) < pozycja_pacmana.y)
				{

					////////////////////////////////////////////
					//wyruwnywanie pacmana 
					//(wyrównanie pac-mana podczas zmiany kierunku tak, aby szed³ dok³adnie po wyznaczonym torze)
						if (kierunek != kier_w_bufor)
							{
								PacMan->zmiana_pozycji((int)mapa_kolizji[i].x - 15, (int)mapa_kolizji[i].y - 15);
							}

					////////////////////////////////////////////
					//sprawdzanie kolizji w punktach kolizyjnych
						if (kier_w_bufor == LEWO && mapa_kolizji[i].DostKier.L == true)
							{

								PacMan->zmiana_kier(LEWO);

							}else
						if (kier_w_bufor == PRAWO && mapa_kolizji[i].DostKier.P == true)
							{
								PacMan->zmiana_kier(PRAWO);
							}else
						if (kier_w_bufor == DOL && mapa_kolizji[i].DostKier.D == true)
							{
								PacMan->zmiana_kier(DOL);
						}
						else
							if (kier_w_bufor == GORA && mapa_kolizji[i].DostKier.G == true)
							{
								PacMan->zmiana_kier(GORA);
							}
						else
						// sprawdzanie czy pacman znajduje sie w portalu
						if (mapa_kolizji[i].DostKier.G == false && mapa_kolizji[i].DostKier.P == false &&
									mapa_kolizji[i].DostKier.D == false && mapa_kolizji[i].DostKier.L == false)
							{
							std::cout << "pac_man " << pozycja_pacmana.x << " " << pozycja_pacmana.y << std::endl;
								if((pozycja_pacmana.x+1 )> 35 && (pozycja_pacmana.x - 1 )< 35)
									PacMan->zmiana_pozycji(598, 326);
								if ((pozycja_pacmana.x + 1)> 614 && (pozycja_pacmana.x - 1) <  614)
									PacMan->zmiana_pozycji(22, 326);
							}
						else
							{
								///////////////////////////////////////////////////
								// if-y s¹ aby pacman nie zatrzymwa³ sie na rozwidleniach 
								// gdy kierunek w buforze powoduje kolizje

								if (kierunek == GORA && mapa_kolizji[i].DostKier.G == true)
									{
									}
								else
								if (kierunek == DOL && mapa_kolizji[i].DostKier.D == true)
									{
									}
								else
								if (kierunek == LEWO && mapa_kolizji[i].DostKier.L == true)
									{
									}
								else
								if (kierunek == PRAWO && mapa_kolizji[i].DostKier.P == true)
									{
									}
								else
									{
										PacMan->zmiana_kier(STOJ);
									}
							}
				}
		}
		
	}
}