#include "BialyPunkt.h"



void BialyPunkt::usunPunkt()
{
	czIstnieje = false;
}

void BialyPunkt::aktualizuj()
{
	kropka.setPosition(Vector2f(x, y));
}

void BialyPunkt::ustawXY(int xx, int yy)
{
	x = xx;
	y = yy;
	xSrodek = xx;// +5;
	ySrodek = yy;// +5;
}

Wektor BialyPunkt::dajXY()
{
	Wektor kierunki;
	kierunki.x = x;
	kierunki.y = y;
	return kierunki;
}

void BialyPunkt::rysuj(RenderWindow* okno)
{
	if (czIstnieje == true)
	{
		okno->draw(kropka);
	}
}

bool BialyPunkt::czyist()
{
	return czIstnieje;
}

BialyPunkt::BialyPunkt(int xx, int yy, bool czyIst)
{
	int x = xx;
	int y = yy;
	czIstnieje = czyIst;
	kropka.setSize(Vector2f(3, 3));
	//kropka.setRadius(1.5);
	kropka.setFillColor(Color(155, 155, 155, 255));
}

BialyPunkt::~BialyPunkt()
{
}
