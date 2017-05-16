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

	void zmiana_pozycji(float, int);//przenosi bohatera o odpowiedni¹ odleg³oœæ(wzgledem czasu(float)) i w wybranym kierunku(int)
	void zmiana_pozycji(float); //przenosi bohatera o odpowiedni¹ odleg³oœæ
	void zmiana_pozycji(int, int); //przenosi bohatera w miejsce oznaczone (x,y)

	void zmiana_kierunku(int);//zmienie buforowany kierunek poruszania siê pacmana(kierunek zostanie trwale zmieniony po obs³udze kolizji)
	int daj_kierunek();// zwraca kierunek w którym aktualnie pacman siê porusza 
	int daj_kier_w_bufor();// zwraca kierunek w który znajduje sie w buforze(kierunek pobrany z klawiatury ale i czekaj¹cy na mo¿liwoœæ ustawienia go jako kierunku g³ównego) 
	Wektor daj_xy(); // zwraca œrodek(x,y) pac-mana 
	void zmien_teksture(int);
	void zamknij_paszcze();// ustawia pe³n¹ teksture pacmana(ustawia teksture bez wciêcia)


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
			   //const int kolor;
};

