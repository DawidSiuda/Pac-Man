#include "Kolizja.h"

DostepnyKierunek Kolizja::dajKierunki()
{ 
	return DostKier;
}

Wektor Kolizja::dajXY()
{
	Wektor wynik;
	wynik.x = x;
	wynik.y = y;
	return wynik;
}

void Kolizja::usunKierunek(int jaki)
{
	switch (jaki)
	{
	case GORA: DostKier.G = false;
		break;
	case PRAWO:DostKier.P = false;
		break;
	case DOL:DostKier.D = false;
		break;
	case LEWO:DostKier.L = false;
		break;
	}
}

Kolizja & Kolizja::operator=(const Kolizja &kolizja)
{

	if (&kolizja == this)return *this;

	DostKier.G = kolizja.DostKier.G;
	DostKier.P = kolizja.DostKier.P;
	DostKier.D = kolizja.DostKier.D;
	DostKier.L = kolizja.DostKier.L;

	pocz_x = kolizja.pocz_x;
	pocz_y = kolizja.pocz_y;

	x = kolizja.x;
	y = kolizja.y;

	wielkosc = kolizja.wielkosc;

}

Kolizja::Kolizja(bool gora, bool prawo, bool dol, bool lewo, float xx, float yy, float wwielkosc)
{
	pocz_x = xx;
	pocz_y = yy;
	x = (int)(pocz_x + (WIELKOSC));
	y = (int)(pocz_y + (WIELKOSC));
	DostKier.G = gora;
	DostKier.P = prawo;
	DostKier.D = dol;
	DostKier.L = lewo;
	wielkosc = wwielkosc;
}

Kolizja::~Kolizja()
{

}

void Kolizja::daj_wsp(float xx, float yy)
{
	pocz_x = xx;
	pocz_y = yy;
	x = (int)(pocz_x + (WIELKOSC));
	y = (int)(pocz_y + (WIELKOSC));
}

void Kolizja::stworz()
{
	Color kolor(0, 255, 255, 50);
	pole_kolizji.setRadius(wielkosc);
	pole_kolizji.setFillColor(kolor);
	pole_kolizji.setPosition(Vector2f(pocz_x, pocz_y));
}
