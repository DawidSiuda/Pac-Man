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


