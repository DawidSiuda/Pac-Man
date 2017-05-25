#pragma once

#include "Struktury.cpp"
#include "Kolizja.h"

class BialyPunkt
{
public:
	/*
	static void dajIloscWektorow(int);
	int sprawdzKolizje(Wektor);
	void stworzPunkty();
	*/
	void usunPunkt();
	void aktualizuj();
	void ustawXY(int xx, int yy);
	Wektor dajXY();
	void rysuj(RenderWindow* okno);
	bool czyist();

	BialyPunkt(int = 0 ,int  = 0, bool = true);

	~BialyPunkt();

private:

	RectangleShape kropka;
	bool czIstnieje;
	int x;
	int y;
	int xSrodek;
	int ySrodek;
};

