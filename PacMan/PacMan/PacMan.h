#pragma once

#include "Postac.h"	
#include "Lista_zmiennych_stalych.cpp"
#include "Kolizja.h"
#include "Struktury.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class PacMan : public Postac
{
public:
	Shape *cialo;

	void zmiana_pozycji(float czas, int kierunek, bool byTime);	//przenosi bohatera o odpowiedni¹ odleg³oœæ(wzgledem czasu(float)) i w wybranym kierunku(int)
	void zmiana_pozycji(float ILEpx, int kierunek);				//przenosi bohatera o odpowiedni¹ odleg³oœæ w px
	void zmiana_pozycji(int x, int y);							//przenosi bohatera w miejsce oznaczone (x,y)
	void zmien_teksture(int);
	void zmianaBuforowanegoKierunku(int);	//zmienie buforowany kierunek poruszania siê pacmana(kierunek zostanie trwale zmieniony po obs³udze kolizji)	
	void zamknij_paszcze();					// ustawia pe³n¹ teksture pacmana(ustawia teksture bez wciêcia)
	Wektor daj_xy();						// zwraca œrodek(x,y) pac-mana
	virtual void zmienZwrotJesliMozliwe();	//zmienia kierunek ruchu postaci naprzeciwko jesli w buforze kierunku takie polecnie sie znajduje
	virtual void obsluzKolizjeZMmapa(int, Kolizja *);
	int daj_kierunek();						// zwraca kierunek w którym aktualnie pacman siê porusza 
	int daj_kier_w_bufor();					// zwraca kierunek w który znajduje sie w buforze(kierunek pobrany z klawiatury ale i czekaj¹cy na mo¿liwoœæ ustawienia go jako kierunku g³ównego) 
	int dajLiczbeZyc();
	void zabierzZycie();
	void ustawIloscZycie(int);
	void ustawKierunek(int);

	PacMan(
		float predkosc,
		float xStartuWeza,
		float yStartuWeza,
		bool port = false,
		bool usta = true,
		int ile_zyc = 3,
		int kierunek = LEWO);
	PacMan(	
		float predkosc,
		Wektor miejsceStartuPacmana,
		bool port = false,
		bool usta = true,
		int ile_zyc = 3,
		int kierunek = LEWO);
	~PacMan();

	friend class Kolizja;
	friend void obsluz_kolizje_mapy(Kolizja *, int, Wektor, int, int, PacMan*);

protected:
	void zmiana_kier(int);					//zmienie kierunek poruszania siê pacmana
	void zmiana_kier(int, float, float);	//zmienie kierunek poruszania siê pacmana,

private:
	int kierunek_ust;
	float x;
	float y;
	short ile_zyc;
	bool ustaZamkniete;					//true - usta zamkniete, false - usta otwarte
	Texture tekstura;
	CircleShape bohater;

	//ZMIENNE W KLASIE POSTAC:
	//	float predkosc; // piksel/sekunde
	//	int kierunek; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
	//	int kierunek_w_buforze; // 1 - góra, 2 - lewo, 3 - dó³, 4 - lewo
};

