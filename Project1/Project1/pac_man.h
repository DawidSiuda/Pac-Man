#pragma once

#include "postac.h"	
#include "lista_zmiennych_stalych.cpp"
#include "Kolizja.h"
#include "struktury.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class pac_man : public postac
{
public:
	Shape *cialo;

	void zmiana_pozycji(float,int);
	void zmiana_pozycji(float);
	void zmiana_pozycji(int, int);
	void zmiana_kierunku(int);//zmienie buforowany kierunek poruszania siê pacmana(kierunek zostanie trwale zmieniony po obs³udze kolizji)
	int daj_kierunek();
	int daj_kier_w_bufor();
	Wektor daj_xy(); // zwraca œrodek pac-mana
	void zmien_teksture(int);
	void zamknij_paszcze();

	
	pac_man(int ile_zyc = 3,
			float predkosc = 1,
			int kierunek = PRAWO,
			float xx = 110,
			float yy = 110,
			bool port = false,
			bool = true);
	~pac_man();

	friend class Kolizja;
	friend void obsluz_kolizje_mapy(Kolizja *, int, Wektor, int, int, pac_man*);

protected:
	void zmiana_kier(int); //zmienie kierunek poruszania siê pacmana
	void zmiana_kier(int, float, float); //zmienie kierunek poruszania siê pacmana,
										 //wraz z wyruwnaniem pozycji (wzglêdem punktu kolizji) pacmana
private:
	Texture tekstura;
	CircleShape bohater;
	int kierunek_ust;
	float x;
	float y;
	unsigned short ile_zyc;
	bool portal; // true - postaæ znajduje sie w portalu; false - postac nie znajduje sie w portalu
	bool usta; //true - usta zamkniete, false - usta otwarte
	//static int ile_istnieje; // ile egzempla¿y pac-mana istnieje 
	const int kolor;
};

