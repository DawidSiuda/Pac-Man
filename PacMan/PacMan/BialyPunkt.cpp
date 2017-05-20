#include "BialyPunkt.h"



void BialyPunkt::aktualizuj()
{
	kropka.setPosition(Vector2f(x, y));
}

void BialyPunkt::ustawXY(int xx, int yy)
{
	x = xx;
	y = yy;
}

void BialyPunkt::rysuj(RenderWindow* okno)
{
	okno->draw(kropka);
}

BialyPunkt::BialyPunkt(int xx, int yy, bool czyIst)
{
	int x = xx;
	int y = yy;
	czIstnieje = czyIst;
	kropka.setSize(Vector2f(5, 5));
	kropka.setFillColor(Color(255, 255, 255, 255));
}

BialyPunkt::~BialyPunkt()
{
}
