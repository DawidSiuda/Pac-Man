#include "pac_man.h"


void pac_man::zmiana_pozycji(float czas_od_oststniej_klatki,int gdzie)
{
	switch (gdzie)
	{
	case LEWO:
		x = x -predkosc * czas_od_oststniej_klatki;
		break;
	case PRAWO:
		x = x +predkosc * czas_od_oststniej_klatki;
		break;
	case GORA:
		y = y -predkosc * czas_od_oststniej_klatki;
		break;
	case DOL:
		y = y +predkosc * czas_od_oststniej_klatki;
		break;
	case STOJ:
		break;
	default:
		std::cout << "zly kierunek pac-mana: " << gdzie <<  std::endl;
	}
	//std::cout << x << " " << y << std::endl;
	cialo->setPosition((int)x, (int)y);
}

void pac_man::zmiana_pozycji(float czas_od_oststniej_klatki)
{
	zmiana_pozycji(czas_od_oststniej_klatki,kierunek);
}

void pac_man::zmiana_pozycji(int xx, int yy)
{
	x = xx;
	y = yy;
}

void pac_man::zmiana_kierunku(int nowy_kier)
{
	if (nowy_kier > 0 && nowy_kier < 5)
	{
		kierunek_w_buforze = nowy_kier;
		//kierunek = nowy_kier; //testowy, do usuniêcia
	}
	else
		std::cout << "podano zly kierunek ///pac_man.cpp//void zmiana_kierunku()" << std::endl;
}

int pac_man::daj_kierunek()
{
	return kierunek;
}

int pac_man::daj_kier_w_bufor()
{
	return kierunek_w_buforze;
}

Wektor pac_man::daj_xy()
{
		Wektor pozycja;
		pozycja.x = x+15;
		pozycja.y = y+15;
		return pozycja;
}

pac_man::pac_man(int ile, float pre, int kier,float xx, float yy, bool port ): kolor(zolty), postac(pre, kier)
{
	ile_zyc = ile;
	portal = port;
	
	x = xx + 261; 
	y = yy + 441;
	bohater.setRadius(15);
	bohater.setFillColor(Color::Yellow);
	//bohater.setOutlineColor(Color::Red);
	if (!tekstura.loadFromFile("cialo_tekst.png"))
		std::cout << "nie mozna zaladowac rekstury pac-mana" << std::endl;
	bohater.setTexture(&tekstura);
	//bohater.setFillColor(Color::Yellow);
	//bohater.setOutlineThickness(5);
	bohater.setPosition(x, y);
	cialo = &bohater;

}


pac_man::~pac_man()
{
	//ile_istnieje--;
}

void pac_man::zmiana_kier(int nowy)
{
	kierunek = nowy;
}

void pac_man::zmiana_kier(int k, float xx, float yy)
{
	zmiana_pozycji((int)xx, (int)yy);
	zmiana_kier(k);
}

