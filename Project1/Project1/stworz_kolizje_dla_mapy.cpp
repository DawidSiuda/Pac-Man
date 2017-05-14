#pragma once

#include "Kolizja.h"


#include "lista_zmiennych_stalych.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;



Kolizja Tablica[] =
{
	Kolizja(0,1,1,0,0,0,WIELKOSC),			/*	LD		*/
		Kolizja(0,1,1,1,0,0,WIELKOSC),		/*	LDP		*/
			Kolizja(0,0,1,1,0,0,WIELKOSC),	/*	LD		*/

	Kolizja(1,1,1,0,0,0,WIELKOSC),			/*	GDP		*/
		Kolizja(1,1,1,1,0,0,WIELKOSC),		/*	LGDP	*/
			Kolizja(1,0,1,1,0,0,WIELKOSC),	/*	LGD		*/

	Kolizja(1,1,0,0,0,0,WIELKOSC),			/*	GP		*/
		Kolizja(1,1,0,1,0,0,WIELKOSC),		/*	LGP		*/
			Kolizja(1,0,0,1,0,0,WIELKOSC)	/*	LG		*/
};


void stworz_kolizje_dla_mapy(int ile, Kolizja *kolizja)
{
	/*wzór

	//
	kolizja[] = Tablica[];
	kolizja[].daj_wsp(,);
	kolizja[].stworz();

	*/

	//0
	kolizja[0] = Tablica[0];
	kolizja[0].daj_wsp(68,77);
	kolizja[0].stworz(); // aktualizacja wspó³¿êdnych kolizji, ustalanie wielkoœci i koloru
	//std::cout << kolizja[0].x << " "<< kolizja[0].y << std::endl; // wypisanie srodka kolizji

	//1
	kolizja[1] = Tablica[1];
	kolizja[1].daj_wsp(165, 77);
	kolizja[1].stworz();

	//2
	kolizja[2] = Tablica[2];
	kolizja[2].daj_wsp(280, 77);
	kolizja[2].stworz();

	//3
	kolizja[3] = Tablica[0];
	kolizja[3].daj_wsp(340,77);
	kolizja[3].stworz();

	//4
	kolizja[4] = Tablica[1];
	kolizja[4].daj_wsp(455, 77);
	kolizja[4].stworz();

	//5
	kolizja[5] = Tablica[2];
	kolizja[5].daj_wsp(553,77);
	kolizja[5].stworz();

	//6
	kolizja[6] = Tablica[3];
	kolizja[6].daj_wsp(68, 153);
	kolizja[6].stworz();

	//7
	kolizja[7] = Tablica[4];
	kolizja[7].daj_wsp(165, 153);
	kolizja[7].stworz();

	//8
	kolizja[8] = Tablica[1];
	kolizja[8].daj_wsp(223,153);
	kolizja[8].stworz();

	//9
	kolizja[9] = Tablica[7];
	kolizja[9].daj_wsp(280,153);
	kolizja[9].stworz();

	//10
	kolizja[10] = Tablica[7];
	kolizja[10].daj_wsp(340,153);
	kolizja[10].stworz();

	//11
	kolizja[11] = Tablica[1];
	kolizja[11].daj_wsp(398,153);
	kolizja[11].stworz();

	//12
	kolizja[12] = Tablica[4];
	kolizja[12].daj_wsp(455,153);
	kolizja[12].stworz();

	//13
	kolizja[13] = Tablica[5];
	kolizja[13].daj_wsp(553,153);
	kolizja[13].stworz();

	//14
	kolizja[14] = Tablica[6];
	kolizja[14].daj_wsp(68, 210);
	kolizja[14].stworz();

	//15
	kolizja[15] = Tablica[5];
	kolizja[15].daj_wsp(165, 210);
	kolizja[15].stworz();

	//20
	kolizja[20] = Tablica[3];
	kolizja[20].daj_wsp(455,210);
	kolizja[20].stworz();

	//21
	kolizja[21] = Tablica[8];
	kolizja[21].daj_wsp(553,210);
	kolizja[21].stworz();

	//26
	kolizja[26] = Tablica[4];
	kolizja[26].daj_wsp(165, 326);
	kolizja[26].stworz();

	//32
	kolizja[32] = Tablica[0];
	kolizja[32].daj_wsp(68, 442);
	kolizja[32].stworz();

	//40
	kolizja[40] = Tablica[6];
	kolizja[40].daj_wsp(68, 501);
	kolizja[40].stworz();
	
	//42
	kolizja[42] = Tablica[3];
	kolizja[42].daj_wsp(165, 501);
	kolizja[42].stworz();

	//44
	kolizja[44] = Tablica[7];
	kolizja[44].daj_wsp(280,501);
	kolizja[44].stworz();

	//45
	kolizja[45] = Tablica[7];
	kolizja[45].daj_wsp(340,501);
	kolizja[45].stworz();

	//46
	kolizja[46] = Tablica[1];
	kolizja[46].daj_wsp(398,501);
	kolizja[46].stworz();

	//47
	kolizja[47] = Tablica[5];
	kolizja[47].daj_wsp(455, 501);
	kolizja[47].stworz();

	//52
	kolizja[40] = Tablica[8];
	kolizja[40].daj_wsp(165, 558);
	kolizja[40].stworz();

	//55
	kolizja[55] = Tablica[0];
	kolizja[55].daj_wsp(340,558);
	kolizja[55].stworz();

	//56
	kolizja[56] = Tablica[8];
	kolizja[56].daj_wsp(398,558);
	kolizja[56].stworz();

	//62
	kolizja[62] = Tablica[7];
	kolizja[62].daj_wsp(340,617);
	kolizja[62].stworz();

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