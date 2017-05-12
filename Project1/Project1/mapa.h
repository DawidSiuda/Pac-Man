#pragma once

class mapa
{
public:
	void laduj_nowa();
	void rysuj();
	void pasuza();

	mapa();
	~mapa();

private:
	bool pauza; // true - pauza; false - trwa rozgrywka
	int wysokosc;//px
	int szerokosc; //px
	int ile_kulek;
};

