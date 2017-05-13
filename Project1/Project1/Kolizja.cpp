#include "Kolizja.h"

Kolizja & Kolizja::operator=(const Kolizja &kolizja)
{
	//std::cout << "hej to ja" << std::endl;
	if (&kolizja == this)return *this;
	//std::cout << "hej to ja" << std::endl;
	rodzaj = kolizja.rodzaj;
	//std::cout << "hej to ja" << std::endl;
	wielkosc = kolizja.wielkosc;
	//std::cout << "hej to ja" << std::endl;
}

Kolizja::Kolizja(float xx, float yy, int rrodzaj, float wwielkosc)
{
	pocz_x = xx;
	pocz_y = yy;
	x = (int)(pocz_x + (WIELKOSC ));
	y = (int)(pocz_y + (WIELKOSC ));
	rodzaj = rrodzaj;
	wielkosc = wwielkosc;
}

Kolizja::~Kolizja()
{

}

void Kolizja::daj_wsp(float xx, float yy)
{
	pocz_x = xx;
	pocz_y = yy;
	x = (int)(pocz_x + (WIELKOSC ));
	y = (int)(pocz_y + (WIELKOSC ));
}

void Kolizja::stworz()
{
	Color kolor(0, 255, 255,100);
	pole_kolizji.setRadius(wielkosc);
	pole_kolizji.setFillColor(kolor);
	pole_kolizji.setPosition(Vector2f(pocz_x, pocz_y));
}
