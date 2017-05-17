#pragma once

#define TEST //uruchamia funkcje przydatne przy tworzeniu gry docelowo niedostêpne w finalnej wersji

//rozmiary okna
#define WYSOKOSC_OKNA 800
#define SZEROKOSC_OKNA 650

//kierunki
#define GORA 1
#define PRAWO 2
#define DOL 3
#define LEWO 4
#define STOJ 0


#define WIELKOSC 15 // wielkosc rysowanego pola kolizji
#define ILE_KOLIZJI 67// ilosc kolizji na mapie
#define GRANICA_KOLIZJI 1 //odleg³oœæ (w px) w jakiej wykrywana jest kolizja w punktach kolizyjnych na mapie

//czestotliwosc zamykania ust przez pacmana
#define TIME_TO_CHANGE_MOUTH 0.1
#define USTA_ZAMKNIETE 5

/*
//rodzaje kolizji
(mo¿liwe obecne zmiany kierunków)
L - LEWO
P - PRAWO
G - GÓRA
D - DÓ£

#define DP 1	// dó³ prawo
#define LDP 2	// lweo dó³ prawo itp.
#define LD 3
#define GDP 4
#define LGDP 5
#define LGD 6
#define GP 7
#define LGP 8
#define LG 9
*/

/*
//kolory
#define zolty 1
*/