#include "MapaPunktow.h"



void MapaPunktow::tworzMapePunktow(Kolizja *kolizja, int ile )
{
	for (int i = 0; i < ile; i++)
	{
		cout << i << ") " << kolizja[i].dajXY().x << " <---> " << kolizja[i].dajXY().y << endl;
	}
}

void MapaPunktow::rysuj(RenderWindow* okno)
{
	for (int i = 0; i < ileKropek; i++)
	{
		mapaKropek[i].rysuj(okno);
	}

}

MapaPunktow::MapaPunktow()
{
	mapaKropek = new BialyPunkt[1];
	mapaKropek[0].ustawXY(100, 100);
	mapaKropek[0].aktualizuj();
	ileKropek = 1;
}

MapaPunktow::~MapaPunktow()
{
	delete[] mapaKropek;
}
