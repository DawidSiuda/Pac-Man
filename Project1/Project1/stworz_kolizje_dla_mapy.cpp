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
	//1
	kolizja[0] = Tablica[0];
	kolizja[0].daj_wsp(72,77);
	kolizja[0].stworz(); // aktualizacja wspó³¿êdnych kolizji, ustalanie wielkoœci i koloru
	//std::cout << kolizja[0].x << " "<< kolizja[0].y << std::endl; // wypisanie srodka kolizji

	//2
	kolizja[1] = Tablica[7];
	kolizja[1].daj_wsp(165, 77);
	kolizja[1].stworz();

	//3
	kolizja[3] = Tablica[2];
	kolizja[3].daj_wsp(280, 77);
	kolizja[3].stworz();

	//64
	kolizja[1] = Tablica[6];
	kolizja[1].daj_wsp(72, 500);
	kolizja[1].stworz();

	//std::cout << "hej to ja" << std::endl;
	//std::cout << Tablica[0].x << std::endl;

}

void rysuj_kolizje(int ile, Kolizja *kolizja, RenderWindow *okno)
{
	for (int i = 0; i < ile; i++)
	{
		okno->draw(kolizja[i].pole_kolizji);
	}
}