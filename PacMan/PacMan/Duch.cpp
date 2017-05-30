#include "Duch.h"

bool Duch::inicjalizujLosowosc = false;

int Duch::smierc()
{
	return 0;
}

float Duch::dajPredkosc()
{
	return predkosc;
}

void Duch::zmianaPozycji(float ILEpx, int kierunek)
{
	switch (kierunek)
	{
	case LEWO:
		x = x - ILEpx;
		break;
	case PRAWO:
		x = x + ILEpx;
		break;
	case GORA:
		y = y - ILEpx;
		break;
	case DOL:
		y = y + ILEpx;
		break;
	case STOJ:
		break;
	default:
		std::cout << "zly kierunek ducha: " << kierunek << std::endl;
	}
	//std::cout << x << " " << y << std::endl;
	cialo->setPosition((int)x, (int)y);
}

void Duch::zmianaPozycji(float xx , float yy )
{
	x = xx;
	y = yy;
}

int Duch::dajKierunek()
{
	return kierunek;
}

void Duch::AI(PacMan *, float czas)
{
	// kolizje na starcie
	if (y == 326 && kierunek == STOJ && x == granicaStartLewo)//stoj¹ na starcie
	{
			kierunek = PRAWO;
			zmianaPozycji((float)granicaStartLewo + odlegloscKolizjiOtoczenia + 1, (float)326.0);
			
	}else
	if (y == 326 && kierunek == STOJ && x == granicaStartPrawo)//stoj¹ na starcie
	{
		zmianaPozycji((float)(granicaStartPrawo - odlegloscKolizjiOtoczenia - 1), (float)326.0);
		kierunek = LEWO;
	}

	//wyjscie z startu
	{
		czasStartu -= czas;
		if (czasStartu + 10000 < 0)
		{
			czasStartu = (-1);
		}
		if (czasStartu < 0 && obsluzWyjscie == true)
		{

			if ((int)x + odlegloscKolizjiOtoczenia > 305 && (int)x - odlegloscKolizjiOtoczenia < 305 && (kierunek == LEWO || kierunek == PRAWO))
			{
				cout << (int)x << endl;
				zmianaPozycji((float)305, (float)326);
				kierunek = GORA;
			}
			if ((int)y + odlegloscKolizjiOtoczenia > 269 && (int)y - odlegloscKolizjiOtoczenia < 269)
			{
				zmianaPozycji((float)305, (float)269);
				int losujKierunek = (std::rand() % 2);
				if (losujKierunek == 1)
				{
					kierunek = PRAWO;
				}
				else
				{
					kierunek = LEWO;
				}

				obsluzWyjscie = false;
			}
		}
	}

	//chodzenie po mapie;

	if (kierunek == STOJ)
	{

		int losujKierunek = (std::rand() % 4);

		switch (losujKierunek)
		{
		case 0:
			kierunek_w_buforze = 1;
			break;
		case 1:
			kierunek_w_buforze = 2;
			break;
		case 2:
			kierunek_w_buforze = 3;
			break;
		case 3:
			kierunek_w_buforze = 4;
			break;
		}
	}
}

void Duch::zmiana_kier(int kier)
{
	kierunek = kier;
}

int Duch::ladowanie_na_mape()
{
	return 0;
}

void Duch::zmienZwrotJesliMozliwe()
{
	if (kierunek != kierunek_w_buforze)
	{
		//////////////////////////////////////////////////////////
		// obs³uga  buforu z kierunkami przeciwnymi do aktualnych
		if (kierunek == GORA && kierunek_w_buforze == DOL)
		{
			zmiana_kier(DOL);
		}
		else
		if (kierunek == DOL && kierunek_w_buforze == GORA)
		{
			zmiana_kier(GORA);
		}
		else
		if (kierunek == LEWO && kierunek_w_buforze == PRAWO)
		{
			zmiana_kier(PRAWO);
		}
		else
		if (kierunek == PRAWO && kierunek_w_buforze == LEWO)
		{
			zmiana_kier(LEWO);
		}
	}
}

void Duch::obsluzKolizjeZMmapa(int ile_kolizji, Kolizja *mapa_kolizji)
{
	if ((int)x+ odlegloscKolizjiOtoczenia > granicaStartLewo && (int)x - odlegloscKolizjiOtoczenia < granicaStartLewo)
	{
		//cout << (int)x << endl;
		//cout << (int)y << endl;
		if ((int)y == 326)
		{
			kierunek = STOJ;
			x = granicaStartLewo;
		}

	}else
	if ((int)x + odlegloscKolizjiOtoczenia > granicaStartPrawo && (int)x - odlegloscKolizjiOtoczenia < granicaStartPrawo)
	{
		//cout << (int)x << endl;
		//cout << (int)y << endl;
		if ((int)y == 326)
		{
			kierunek = STOJ;
			x = granicaStartPrawo;
		}

	}
	
	
	/////////////////////////////////////////////
	/////////////////////////////////////////////
	for (int i = 0; i < ile_kolizji; i++)
	{
		if ((mapa_kolizji[i].pocz_x + GRANICA_KOLIZJI) > x && (mapa_kolizji[i].pocz_x - GRANICA_KOLIZJI) < x)
		{
			if ((mapa_kolizji[i].pocz_y + GRANICA_KOLIZJI) > y && (mapa_kolizji[i].pocz_y - GRANICA_KOLIZJI) < y)
			{
				////////////////////////////////////////////
				//wyruwnywanie pacmana 
				//(wyrównanie pac-mana podczas zmiany kierunku tak, aby szed³ dok³adnie po wyznaczonym torze)
				if (kierunek != kierunek_w_buforze)
				{
					zmianaPozycji((float)mapa_kolizji[i].pocz_x, (float)mapa_kolizji[i].pocz_y);
				}

				////////////////////////////////////////////
				//sprawdzanie kolizji w punktach kolizyjnych
					// sprawdzanie czy pacman znajduje sie w portalu
				if (mapa_kolizji[i].DostKier.G == false && mapa_kolizji[i].DostKier.P == false &&
					mapa_kolizji[i].DostKier.D == false && mapa_kolizji[i].DostKier.L == false)
				{
					//std::cout << "pac_man " << x << " " << y << std::endl;
					if ((x + 1) > 20 && (x - 1) < 20)
						zmianaPozycji((float)598, (float)326);
					if ((x + 1) > 600 && (x - 1) < 600)
						zmianaPozycji((float)22, (float)326);
				}
				else
				{
					///////////////////////////////////////////////////
					// if-y s¹ aby pacman nie zatrzymwa³ sie na rozwidleniach 
					// gdy kierunek w buforze powoduje kolizje

					if (kierunek_w_buforze == GORA && mapa_kolizji[i].DostKier.G == true)
					{
						kierunek = GORA;
					}
					else
						if (kierunek_w_buforze == LEWO && mapa_kolizji[i].DostKier.L == true)
						{
							kierunek = LEWO;
						}
						else
							if (kierunek_w_buforze == PRAWO && mapa_kolizji[i].DostKier.P == true)
							{
								kierunek =PRAWO;
							}
							else
								if (kierunek_w_buforze == DOL && mapa_kolizji[i].DostKier.D == true)
								{
									kierunek = DOL;
								}/*
								else
					if (kierunek == GORA && mapa_kolizji[i].DostKier.G == true)
					{
					}
					else if (kierunek == DOL && mapa_kolizji[i].DostKier.D == true)
					{
					}
					else if (kierunek == LEWO && mapa_kolizji[i].DostKier.L == true)
					{
					}
					else if (kierunek == PRAWO && mapa_kolizji[i].DostKier.P == true)
					{
					}*/
					else
					{
						zmiana_kier(STOJ);
						
					}

				}
			}

		}
	}
//////////////////////////////////////////////////////////////////////////////////
}

Wektor Duch::dajXY()
{
	Wektor pomoc;
	pomoc.x = x;
	pomoc.y = y;
	
	return pomoc;
}

Duch::Duch(string teks, int startX, int startY, float czasSt, int pred) 
	:granicaStartLewo(270),
	granicaStartPrawo(350),
	odlegloscKolizjiOtoczenia(3)
{
	if (inicjalizujLosowosc == false)
	{
		srand(time(NULL));
		inicjalizujLosowosc = true;
	}

	x = startX;
	y = startY;
	czasStartu = czasSt;
	bohater.setSize(Vector2f(30, 30));
	//bohater.setFillColor(Color::Yellow);

	if (!tekstura.loadFromFile(teks))
		std::cout << "nie mozna zaladowac rekstury " << teks << std::endl;

	bohater.setTexture(&tekstura);
	bohater.setPosition(x, y);
	cialo = &bohater;
	//clock.restart();
	int losujKierunek = (std::rand() % 2);
	if (losujKierunek == 1)
	{
		kierunek = PRAWO;
	}
	else
	{
		kierunek = LEWO;
	}
	predkosc = pred;
	obsluzWyjscie = true;
}

Duch::~Duch()
{
}
