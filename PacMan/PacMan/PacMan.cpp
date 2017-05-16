#include "PacMan.h"


void PacMan::zmiana_pozycji(float czas_od_oststniej_klatki, int gdzie)
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

void PacMan::zmiana_pozycji(float czas_od_oststniej_klatki)
{
	zmiana_pozycji(czas_od_oststniej_klatki, kierunek);
}

void PacMan::zmiana_pozycji(int xx, int yy)
{
	x = xx;
	y = yy;
}

void PacMan::zmiana_kierunku(int nowy_kier)
{
	if (nowy_kier > 0 && nowy_kier < 5)
	{
		kierunek_w_buforze = nowy_kier;
		//kierunek = nowy_kier; //testowy, do usuniêcia
	}
	else
		std::cout << "podano zly kierunek ///pac_man.cpp//void zmiana_kierunku()" << std::endl;
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
	usta = true; // usta otwarte
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
		if (usta)
		{
			zmien_teksture(USTA_ZAMKNIETE);
			usta = false;
		}
		else
		{
			zmien_teksture(kierunek_ust);
			usta = true;
		}
	}
	else
	{
		zmien_teksture(kierunek_ust);
	}
}

PacMan::PacMan(int ile, float pre, int kier, float xx, float yy, bool port, bool u_usta) : Postac(pre, kier)
{
	ile_zyc = ile;
	portal = port;

	x = xx + 261;
	y = yy + 441;

	usta = u_usta;
	kierunek_ust = kierunek;

	bohater.setRadius(15);
	bohater.setFillColor(Color::Yellow);
	//bohater.setOutlineColor(Color::Red);
	if (!tekstura.loadFromFile("cialo_tekstL.png"))
		std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;
	bohater.setTexture(&tekstura);
	//bohater.setFillColor(Color::Yellow);
	//bohater.setOutlineThickness(5);
	bohater.setPosition(x, y);
	cialo = &bohater;

}


PacMan::~PacMan()
{
	//ile_istnieje--;
}


