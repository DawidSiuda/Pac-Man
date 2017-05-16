#pragma once

#include "Kolizja.h"


#include "Lista_zmiennych_stalych.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

PobraneUstawieniaMapy MapaPodstawowa(110, 110);

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
	Kolizja(1,0,0,1,0,0,WIELKOSC),	/*	LG		*/

	Kolizja(0,0,0,0,0,0,WIELKOSC),			/*  STOJ PORTAL	*/
	Kolizja(0,1,0,1,0,0,WIELKOSC)		/* LP BRAMA DUCHY*/
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
	kolizja[0].daj_wsp(68, 77);
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
	kolizja[3].daj_wsp(340, 77);
	kolizja[3].stworz();

	//4
	kolizja[4] = Tablica[1];
	kolizja[4].daj_wsp(455, 77);
	kolizja[4].stworz();

	//5
	kolizja[5] = Tablica[2];
	kolizja[5].daj_wsp(553, 77);
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
	kolizja[8].daj_wsp(223, 153);
	kolizja[8].stworz();

	//9
	kolizja[9] = Tablica[7];
	kolizja[9].daj_wsp(280, 153);
	kolizja[9].stworz();

	//10
	kolizja[10] = Tablica[7];
	kolizja[10].daj_wsp(340, 153);
	kolizja[10].stworz();

	//11
	kolizja[11] = Tablica[1];
	kolizja[11].daj_wsp(398, 153);
	kolizja[11].stworz();

	//12
	kolizja[12] = Tablica[4];
	kolizja[12].daj_wsp(455, 153);
	kolizja[12].stworz();

	//13
	kolizja[13] = Tablica[5];
	kolizja[13].daj_wsp(553, 153);
	kolizja[13].stworz();

	//14
	kolizja[14] = Tablica[6];
	kolizja[14].daj_wsp(68, 210);
	kolizja[14].stworz();

	//15
	kolizja[15] = Tablica[5];
	kolizja[15].daj_wsp(165, 210);
	kolizja[15].stworz();

	//16
	kolizja[16] = Tablica[6];
	kolizja[16].daj_wsp(223, 210);
	kolizja[16].stworz();

	//17
	kolizja[17] = Tablica[2];
	kolizja[17].daj_wsp(280, 210);
	kolizja[17].stworz();

	//18
	kolizja[18] = Tablica[0];
	kolizja[18].daj_wsp(340, 210);
	kolizja[18].stworz();

	//19
	kolizja[19] = Tablica[8];
	kolizja[19].daj_wsp(398, 210);
	kolizja[19].stworz();

	//20
	kolizja[20] = Tablica[3];
	kolizja[20].daj_wsp(455, 210);
	kolizja[20].stworz();

	//21
	kolizja[21] = Tablica[8];
	kolizja[21].daj_wsp(553, 210);
	kolizja[21].stworz();

	//22
	kolizja[22] = Tablica[0];
	kolizja[22].daj_wsp(223, 269);
	kolizja[22].stworz();

	//23
	kolizja[23] = Tablica[7];
	kolizja[23].daj_wsp(280, 269);
	kolizja[23].stworz();

	//24
	kolizja[24] = Tablica[7];
	kolizja[24].daj_wsp(340, 269);
	kolizja[24].stworz();

	//25
	kolizja[25] = Tablica[2];
	kolizja[25].daj_wsp(398, 269);
	kolizja[25].stworz();

	//26
	kolizja[26] = Tablica[4];
	kolizja[26].daj_wsp(165, 326);
	kolizja[26].stworz();

	//27
	kolizja[27] = Tablica[5];
	kolizja[27].daj_wsp(223, 326);
	kolizja[27].stworz();

	//28
	kolizja[28] = Tablica[3];
	kolizja[28].daj_wsp(398, 326);
	kolizja[28].stworz();

	//29
	kolizja[29] = Tablica[4];
	kolizja[29].daj_wsp(455, 326);
	kolizja[29].stworz();

	//30
	kolizja[30] = Tablica[3];
	kolizja[30].daj_wsp(223, 385);
	kolizja[30].stworz();

	//31
	kolizja[31] = Tablica[5];
	kolizja[31].daj_wsp(398, 385);
	kolizja[31].stworz();

	//32
	kolizja[32] = Tablica[0];
	kolizja[32].daj_wsp(68, 442);
	kolizja[32].stworz();

	//33
	kolizja[33] = Tablica[4];
	kolizja[33].daj_wsp(165, 442);
	kolizja[33].stworz();

	//34
	kolizja[34] = Tablica[7];
	kolizja[34].daj_wsp(223, 442);
	kolizja[34].stworz();

	//35
	kolizja[35] = Tablica[2];
	kolizja[35].daj_wsp(280, 442);
	kolizja[35].stworz();

	//36
	kolizja[36] = Tablica[0];
	kolizja[36].daj_wsp(340, 442);
	kolizja[36].stworz();

	//37
	kolizja[37] = Tablica[7];
	kolizja[37].daj_wsp(398, 442);
	kolizja[37].stworz();

	//38
	kolizja[38] = Tablica[4];
	kolizja[38].daj_wsp(455, 442);
	kolizja[38].stworz();

	//39
	kolizja[39] = Tablica[2];
	kolizja[39].daj_wsp(553, 442);
	kolizja[39].stworz();

	//40
	kolizja[40] = Tablica[6];
	kolizja[40].daj_wsp(68, 501);
	kolizja[40].stworz();

	//41
	kolizja[41] = Tablica[2];
	kolizja[41].daj_wsp(108, 501);
	kolizja[41].stworz();

	//42
	kolizja[42] = Tablica[3];
	kolizja[42].daj_wsp(165, 501);
	kolizja[42].stworz();

	//43
	kolizja[43] = Tablica[1];
	kolizja[43].daj_wsp(223, 501);
	kolizja[43].stworz();

	//44
	kolizja[44] = Tablica[7];
	kolizja[44].daj_wsp(280, 501);
	kolizja[44].stworz();

	//45
	kolizja[45] = Tablica[7];
	kolizja[45].daj_wsp(340, 501);
	kolizja[45].stworz();

	//46
	kolizja[46] = Tablica[1];
	kolizja[46].daj_wsp(398, 501);
	kolizja[46].stworz();

	//47
	kolizja[47] = Tablica[5];
	kolizja[47].daj_wsp(455, 501);
	kolizja[47].stworz();


	//48
	kolizja[48] = Tablica[0];
	kolizja[48].daj_wsp(513, 501);
	kolizja[48].stworz();

	//49
	kolizja[49] = Tablica[8];
	kolizja[49].daj_wsp(553, 501);
	kolizja[49].stworz();

	//50
	kolizja[50] = Tablica[0];
	kolizja[50].daj_wsp(68, 558);
	kolizja[50].stworz();

	//51
	kolizja[51] = Tablica[7];
	kolizja[51].daj_wsp(108, 558);
	kolizja[51].stworz();

	//52
	kolizja[52] = Tablica[8];
	kolizja[52].daj_wsp(165, 558);
	kolizja[52].stworz();

	//53
	kolizja[53] = Tablica[6];
	kolizja[53].daj_wsp(223, 558);
	kolizja[53].stworz();

	//54
	kolizja[54] = Tablica[2];
	kolizja[54].daj_wsp(280, 558);
	kolizja[54].stworz();

	//55/////////////////////////////////////////////////////////
	kolizja[55] = Tablica[0];
	kolizja[55].daj_wsp(340, 558);
	kolizja[55].stworz();

	//56
	kolizja[56] = Tablica[8];
	kolizja[56].daj_wsp(398, 558);
	kolizja[56].stworz();

	//57
	kolizja[57] = Tablica[6];
	kolizja[57].daj_wsp(455, 558);
	kolizja[57].stworz();

	//58
	kolizja[58] = Tablica[7];
	kolizja[58].daj_wsp(513, 558);
	kolizja[58].stworz();

	//59
	kolizja[59] = Tablica[2];
	kolizja[59].daj_wsp(553, 558);
	kolizja[59].stworz();

	//60
	kolizja[60] = Tablica[6];
	kolizja[60].daj_wsp(68, 617);
	kolizja[60].stworz();

	//61
	kolizja[61] = Tablica[7];
	kolizja[61].daj_wsp(280, 617);
	kolizja[61].stworz();

	//62
	kolizja[62] = Tablica[7];
	kolizja[62].daj_wsp(340, 617);
	kolizja[62].stworz();

	//63
	kolizja[63] = Tablica[8];
	kolizja[63].daj_wsp(553, 617);
	kolizja[63].stworz();

	//64 //portal lewy
	kolizja[64] = Tablica[9];
	kolizja[64].daj_wsp(20, 326);
	kolizja[64].stworz();

	//65 //portal prawy
	kolizja[65] = Tablica[9];
	kolizja[65].daj_wsp(600, 326);
	kolizja[65].stworz();

	//66 //duchy wyjscie
	kolizja[66] = Tablica[10];
	kolizja[66].daj_wsp(310, 269);
	kolizja[66].stworz();

	//std::cout << "hej to ja" << std::endl;
	//std::cout << Tablica[0].x << std::endl;

}

void rysuj_kolizje(int ile, Kolizja *kolizja, RenderWindow *okno)
{
	for (int i = 0; i < 30; i++)
	{
		okno->draw(kolizja[i].pole_kolizji);
		//kolizja[i].
	}
}