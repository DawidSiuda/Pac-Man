#pragma once

#include "Postac.h"	
#include "Lista_zmiennych_stalych.cpp"
#include "Kolizja.h"
#include "Struktury.cpp"
//#include "ObsluzKolizje.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class PacMan : public Postac
{
public:
	Shape *cialo;

	void zmiana_pozycji(float, int);//przenosi bohatera o odpowiedni� odleg�o��(wzgledem czasu(float)) i w wybranym kierunku(int)
	void zmiana_pozycji(float); //przenosi bohatera o odpowiedni� odleg�o��
	void zmiana_pozycji(int, int); //przenosi bohatera w miejsce oznaczone (x,y)

	void zmiana_kierunku(int);//zmienie buforowany kierunek poruszania si� pacmana(kierunek zostanie trwale zmieniony po obs�udze kolizji)
	int daj_kierunek();// zwraca kierunek w kt�rym aktualnie pacman si� porusza 
	int daj_kier_w_bufor();// zwraca kierunek w kt�ry znajduje sie w buforze(kierunek pobrany z klawiatury ale i czekaj�cy na mo�liwo�� ustawienia go jako kierunku g��wnego) 
	Wektor daj_xy(); // zwraca �rodek(x,y) pac-mana 
	void zmien_teksture(int);
	void zamknij_paszcze();// ustawia pe�n� teksture pacmana(ustawia teksture bez wci�cia)


	PacMan(int ile_zyc ,
		float predkosc ,
		int kierunek = PRAWO,
		float xx = 110,
		float yy = 110,
		bool port = false,
		bool = true);
	~PacMan();

	friend class Kolizja;
	friend void obsluz_kolizje_mapy(Kolizja *, int, Wektor, int, int, PacMan*);

protected:
	void zmiana_kier(int); //zmienie kierunek poruszania si� pacmana
	void zmiana_kier(int, float, float); //zmienie kierunek poruszania si� pacmana,
										 //wraz z wyruwnaniem pozycji (wzgl�dem punktu kolizji) pacmana
private:
	Texture tekstura;
	CircleShape bohater;
	int kierunek_ust;
	float x;
	float y;
	unsigned short ile_zyc;
	bool portal; // true - posta� znajduje sie w portalu; false - postac nie znajduje sie w portalu
	bool usta; //true - usta zamkniete, false - usta otwarte
			   //static int ile_istnieje; // ile egzempla�y pac-mana istnieje 
			   //const int kolor;
};

