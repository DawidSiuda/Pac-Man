#pragma once

#include "Kolizja.h"


#include "lista_zmiennych_stalych.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;



Kolizja Tablica[] =
{
	Kolizja(0,0,DP,WIELKOSC),		Kolizja(0,0,LDP,WIELKOSC),	Kolizja(0,0,LD,WIELKOSC),
	Kolizja(0,0,GDP,WIELKOSC),		Kolizja(0,0,LGDP,WIELKOSC),	Kolizja(0,0,LGD,WIELKOSC),
	Kolizja(0,0,GP,WIELKOSC),		Kolizja(0,0,LGP,WIELKOSC),	Kolizja(0,0,LG,WIELKOSC)
};


void stworz_kolizje_dla_mapy(int ile, Kolizja *kolizja)
{
	//kolizja[0] = Tablica[0];
	//kolizja[0].daj_wsp(10,10);
	//kolizja[0].stworz();
	std::cout << "hej to ja" << std::endl;
	std::cout << kolizja << std::endl;

}

//void rysuj_kolizje();