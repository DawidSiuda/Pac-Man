#include "PacMan.h"

void PacMan::zmiana_pozycji(float czas_od_oststniej_klatki, int gdzie, bool byTime)
{
	switch (gdzie)
	{
	case LEWO:
		x = x - predkosc * czas_od_oststniej_klatki;
		break;
	case PRAWO:
		x = x + predkosc * czas_od_oststniej_klatki;
		break;
	case GORA:
		y = y - predkosc * czas_od_oststniej_klatki;
		break;
	case DOL:
		y = y + predkosc * czas_od_oststniej_klatki;
		break;
	case STOJ:
		break;
	default:
		std::cout << "zly kierunek pac-mana: " << gdzie << std::endl;
	}
	//std::cout << x << " " << y << std::endl;
	cialo->setPosition((int)x, (int)y);
}

void PacMan::zmiana_pozycji(float ILEpx, int kierunek)
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
		std::cout << "zly kierunek pac-mana: " << kierunek << std::endl;
	}
	//std::cout << x << " " << y << std::endl;
	cialo->setPosition((int)x, (int)y);
}

void PacMan::zmiana_pozycji(int xx, int yy)
{
	x = xx;
	y = yy;
}

void PacMan::zmianaBuforowanegoKierunku(int nowyKierunek)
{
	if (nowyKierunek > 0 && nowyKierunek < 5)
	{
		kierunek_w_buforze = nowyKierunek;
	}
	else
	{
		std::cout << "podano zly kierunek ///pac_man.cpp//void zmiana_kierunku()" << std::endl;
	}
}

int PacMan::daj_kierunek()
{
	return kierunek;
}

int PacMan::daj_kier_w_bufor()
{
	return kierunek_w_buforze;
}

void PacMan::zmiana_kier(int nowy)
{
	kierunek = nowy;

	if (nowy >0 && nowy < 5)
		kierunek_ust = nowy;

	zmien_teksture(nowy);
	ustaZamkniete = true;
}

void PacMan::zmiana_kier(int k, float xx, float yy)
{
	zmiana_pozycji((int)xx, (int)yy);
	zmiana_kier(k);
}

Wektor PacMan::daj_xy()
{
	Wektor pozycja;
	pozycja.x = x + 15;
	pozycja.y = y + 15;
	return pozycja;
}

void PacMan::zmien_teksture(int kierunek)
{
	if (kierunek == LEWO)
	{
		if (!tekstura.loadFromFile("cialo_tekstL.png"))
			std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;
		else
			bohater.setTexture(&tekstura);
	}
	else
		if (kierunek == PRAWO)
		{
			if (!tekstura.loadFromFile("cialo_tekstP.png"))
				std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;
			else
				bohater.setTexture(&tekstura);
		}
		else
			if (kierunek == GORA)
			{
				if (!tekstura.loadFromFile("cialo_tekstG.png"))
					std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;
				else
					bohater.setTexture(&tekstura);
			}
			else
				if (kierunek == DOL)
				{
					if (!tekstura.loadFromFile("cialo_tekstD.png"))
						std::cout << "nie mozna zaladowac tekstury pac-mana" << std::endl;
					else
						bohater.setTexture(&tekstura);
				}
				else
					if (kierunek == USTA_ZAMKNIETE)
					{
						if (!tekstura.loadFromFile("cialo_tekstS.png"))
							std::cout << "nie mozna zaladowac tekstury pac-mana" << std::endl;
						else
							bohater.setTexture(&tekstura);
					}

}

void PacMan::zamknij_paszcze()
{
	if (kierunek != 0) // sprawdza czy pacman siê porusza
	{
		if (ustaZamkniete == true)
		{
			zmien_teksture(USTA_ZAMKNIETE);
			ustaZamkniete = false;
		}
		else
		{
			zmien_teksture(kierunek_ust);
			ustaZamkniete = true;
		}
	}
	else
	{
		zmien_teksture(kierunek_ust);
	}
}

void PacMan::zmienZwrotJesliMozliwe()
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

void PacMan::obsluzKolizjeZMmapa(int ile_kolizji, Kolizja *mapa_kolizji)
{

	
	for (int i = 0; i < ile_kolizji; i++)
	{
		//std::cout << "KKolizja" << std::endl;
		//std::cout << y << std::endl;
		//std::cout << "KKolizja" << std::endl;
		//std::cout << "pac_man " << x << " "<< y  << std::endl;
		//if (i == 47) {
		//	std::cout << "pac_man " << x << " " << y << std::endl;
		//	std::cout << "obiekt nr:" << i << " " << mapa_kolizji[i].x << " " << mapa_kolizji[i].y << std::endl;
		//}
		//std::cout << "obiekt nr:------------"<<  mapa_kolizji[i].y << std::endl;

		if ((mapa_kolizji[i].pocz_x + GRANICA_KOLIZJI) > x && (mapa_kolizji[i].pocz_x - GRANICA_KOLIZJI) < x)
		{
			if ((mapa_kolizji[i].pocz_y + GRANICA_KOLIZJI) > y && (mapa_kolizji[i].pocz_y - GRANICA_KOLIZJI) < y)
			{
				////////////////////////////////////////////
				//wyruwnywanie pacmana 
				//(wyrównanie pac-mana podczas zmiany kierunku tak, aby szed³ dok³adnie po wyznaczonym torze)
				if (kierunek != kierunek_w_buforze)
				{
					zmiana_pozycji((int)mapa_kolizji[i].pocz_x, (int)mapa_kolizji[i].pocz_y );
				}

				////////////////////////////////////////////
				//sprawdzanie kolizji w punktach kolizyjnych
				if (kierunek_w_buforze == LEWO && mapa_kolizji[i].DostKier.L == true)
				{
					zmiana_kier(LEWO);
				}
				else if(kierunek_w_buforze == PRAWO && mapa_kolizji[i].DostKier.P == true)
				{
					zmiana_kier(PRAWO);
				}
				else if (kierunek_w_buforze == DOL && mapa_kolizji[i].DostKier.D == true)
				{
					zmiana_kier(DOL);
				}
				else if (kierunek_w_buforze == GORA && mapa_kolizji[i].DostKier.G == true)
				{
					zmiana_kier(GORA);
				}else
				// sprawdzanie czy pacman znajduje sie w portalu
				if (mapa_kolizji[i].DostKier.G == false && mapa_kolizji[i].DostKier.P == false &&
						mapa_kolizji[i].DostKier.D == false && mapa_kolizji[i].DostKier.L == false)
				{
					//std::cout << "pac_man " << x << " " << y << std::endl;
					if ((x + 1)> 20 && (x - 1)< 20)
					zmiana_pozycji(598, 326);
					if ((x + 1)> 600 && (x - 1) <  600)
					zmiana_pozycji(22, 326);
				}
				else
				{
					///////////////////////////////////////////////////
					// if-y s¹ aby pacman nie zatrzymwa³ sie na rozwidleniach 
					// gdy kierunek w buforze powoduje kolizje

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
					}
					else
					{
						zmiana_kier(STOJ);
					}
				}
			}
		}

	}
}

PacMan::PacMan(float predkosc, float  xStartuWeza, float yStartuWeza, bool port, bool u_usta, int ile, int kier) : Postac(predkosc, kier)
{
	ile_zyc = ile;
	//portal = port;

	x = xStartuWeza;
	y = yStartuWeza;

	ustaZamkniete = u_usta;
	kierunek_ust = kierunek;

	bohater.setRadius(15);
	bohater.setFillColor(Color::Yellow);

	if (!tekstura.loadFromFile("cialo_tekstL.png"))
		std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;

	bohater.setTexture(&tekstura);
	bohater.setPosition(x, y);
	cialo = &bohater;

}

PacMan::PacMan(float predkosc, Wektor miejsceStartuPacmana, bool port, bool u_usta, int ile, int kier) : Postac(predkosc, kier)
{
	ile_zyc = ile;
//	portal = port;

	x = miejsceStartuPacmana.x;
	y = miejsceStartuPacmana.y;

	ustaZamkniete = u_usta;
	kierunek_ust = kierunek;

	bohater.setRadius(15);
	bohater.setFillColor(Color::Yellow);

	if (!tekstura.loadFromFile("cialo_tekstL.png"))
		std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;

	bohater.setTexture(&tekstura);
	bohater.setPosition(x, y);
	cialo = &bohater;
}

PacMan::~PacMan()
{
}


