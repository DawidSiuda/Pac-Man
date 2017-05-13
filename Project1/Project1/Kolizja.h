#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class Kolizja
{
public:

	Kolizja operator = (const Kolizja &);

	Kolizja(float x = 0, float y=00, int rodzaj = 0, float wielkosc=0);
	~Kolizja();

	friend void stworz_kolizje_dla_mapy(int , Kolizja *);

protected:
	void daj_wsp(float, float);
	void stworz();
	CircleShape pole_kolizji;

private:
	float x;
	float y;
	int rodzaj;
	float wielkosc;
	
};

