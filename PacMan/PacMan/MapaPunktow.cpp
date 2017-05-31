#include "MapaPunktow.h"

void MapaPunktow::tworzMapePunktow(Kolizja *kol, int ile )
{
	Kolizja *kolizja = new Kolizja[ile];

	for (int i = 0; i < ile; i++)
	{
		kolizja[i] = kol[i];
	}
	int licznik = 0;
	int buforX;
	int buforY;
	for (int i = 0; i < ile; i++) //////////zmienic 1 na "ile"
	{
		buforX = kolizja[i].dajXY().x;
		buforY = kolizja[i].dajXY().y;

		if (kolizja[i].dajKierunki().P == true)
		{
			int kroki = buforX;
			for (int k = 0; k < 800; k++)
			{
				
				for (int j = 0; j < ile; j++)
				{
					if (j == i)
					{
						continue;
					}

					if (kroki == kolizja[j].dajXY().x && buforY == kolizja[j].dajXY().y)
					{
						robPunkty(buforX, buforY, kolizja[j].dajXY().x, kolizja[j].dajXY().y);
						//cout << i << " hujj) " << kolizja[j].dajXY().x << " <---> " << kolizja[j].dajXY().y << endl;
						kolizja[j].usunKierunek(LEWO);
						kolizja[i].usunKierunek(PRAWO);
						k = 800;
					}


				}
				kroki++;
			}
		}
		if (kolizja[i].dajKierunki().L == true)
		{
			int kroki = buforX;
			for (int k = 800; k >0; k--)
			{
				
				for (int j = 0; j < ile; j++)
				{
					if (j == i)
					{
						continue;
					}

					if (kroki == kolizja[j].dajXY().x && buforY == kolizja[j].dajXY().y)
					{
						robPunkty( kolizja[j].dajXY().x, kolizja[j].dajXY().y, buforX, buforY );
						//robPunkty(buforX, buforY, kolizja[j].dajXY().x, kolizja[j].dajXY().y);
						//cout << i << " hujj) " << kolizja[j].dajXY().x << " <---> " << kolizja[j].dajXY().y << endl;
						kolizja[j].usunKierunek(PRAWO);
						kolizja[i].usunKierunek(LEWO);
						k = 0;
					}


				}
				kroki--;
			}
		}
		if (kolizja[i].dajKierunki().D == true)
		{
			int kroki = buforY;
			for (int k = 0; k < 800; k++)
			{

				for (int j = 0; j < ile; j++)
				{
					if (j == i)
					{
						continue;
					}

					//if (kroki == kolizja[j].dajXY().x && buforY == kolizja[j].dajXY().y)
					if (buforX == kolizja[j].dajXY().x && kroki == kolizja[j].dajXY().y)
					{
						robPunkty(buforX, buforY, kolizja[j].dajXY().x, kolizja[j].dajXY().y);
						//cout << i << " hujj) " << kolizja[j].dajXY().x << " <---> " << kolizja[j].dajXY().y << endl;
						kolizja[j].usunKierunek(GORA);
						kolizja[i].usunKierunek(DOL);
						k = 800;
					}


				}
				kroki++;
			}
		}
		if (kolizja[i].dajKierunki().G == true)
		{
			int kroki = buforY;
			for (int k = 800; k >0; k--)
			{

				for (int j = 0; j < ile; j++)
				{
					if (j == i)
					{
						continue;
					}

					//if (kroki == kolizja[j].dajXY().x && buforY == kolizja[j].dajXY().y)
					if (buforX == kolizja[j].dajXY().x && kroki == kolizja[j].dajXY().y)
					{
						robPunkty(kolizja[j].dajXY().x, kolizja[j].dajXY().y, buforX, buforY);
						//robPunkty(buforX, buforY, kolizja[j].dajXY().x, kolizja[j].dajXY().y);
						cout << i << " hujj) " << kolizja[j].dajXY().x << " <---> " << kolizja[j].dajXY().y << endl;
						kolizja[j].usunKierunek(DOL);
						kolizja[i].usunKierunek(GORA);
						k = 0;
					}


				}
				kroki--;
			}
		}
	}
	delete[] kolizja;
}

void MapaPunktow::rysuj(RenderWindow* okno)
{
	for (int i = 0; i < ileKropek; i++)
	{
		mapaKropek[i].rysuj(okno);
	}

}

BialyPunkt * MapaPunktow::dajMape()
{
	return mapaKropek;
}

int MapaPunktow::ilePunktow()
{
	return ileKropek;
}

int MapaPunktow::dajProcent()
{

	int pomoc = (100.0 / ileKropek)*ileKropekZjadl;
	if (ileKropek == ileKropekZjadl)pomoc == 0;
	return pomoc;
}

void MapaPunktow::zmiejszLiczbeKropek(int ile)
{
	ileKropekZjadl = ileKropekZjadl + ile;

}

MapaPunktow::MapaPunktow()
{
	mapaKropek = new BialyPunkt[1];
	mapaKropek[0].ustawXY(100, 100);
	mapaKropek[0].aktualizuj();
	mapaKropek[0].usunPunkt();
	ileKropek = 1; 
	ileKropekZjadl = 1;
	procentDoKonca=0;
}

MapaPunktow::~MapaPunktow()
{
	delete[] mapaKropek;
}

void MapaPunktow::robPunkty(int Ix, int Iy, int IIx, int IIy)
{
	int przetworzona_Ix = Ix;
	int przetworzona_Iy = Iy;
	int przetworzona_IIx = IIx;
	int przetworzona_IIy = IIy;
	int odstepy = 17;

	if (Ix == IIx)
	{
		int odleglosc = Iy - IIy;

		if (odleglosc < 0)
		{
			odleglosc *= (-1);
		}

		int ile = odleglosc / odstepy;

		int nowaWielkosc = ileKropek + ile;

		BialyPunkt *wskNowy = new BialyPunkt[ileKropek + ile];
		for (int i = 0; i < (ileKropek); i++)
		{
			wskNowy[i] = mapaKropek[i];
		}

		delete[] mapaKropek;
		mapaKropek = wskNowy;

		for (int i = ileKropek; i < nowaWielkosc; i++)
		{
			mapaKropek[i].ustawXY(przetworzona_Ix  , przetworzona_Iy);
			mapaKropek[i].aktualizuj();
			przetworzona_Iy += odstepy;
		}

		//cout << " )" << ile << endl;
		//delete[] wskNowy;
		ileKropek = nowaWielkosc;
	} // poprawiæ
	else
	if (Iy == IIy)
	{
		 int odleglosc = Ix - IIx;
		 if(odleglosc < 0)
		 {
			 odleglosc *= (-1);
		 }

		 int ile = odleglosc / odstepy;

		 int nowaWielkosc = ileKropek + ile;

		 BialyPunkt *wskNowy = new BialyPunkt[ileKropek + ile];
		 for (int i = 0; i < (ileKropek); i++)
		 {
			 wskNowy[i] = mapaKropek[i];
		 }

		 delete [] mapaKropek;
		 mapaKropek = wskNowy;

		 for (int i = ileKropek; i < nowaWielkosc; i++)
		 {
			 mapaKropek[i].ustawXY(przetworzona_Ix, Iy);
			 mapaKropek[i].aktualizuj();
			 przetworzona_Ix += odstepy;
		 }
		 
		// << " )" << ile << endl;
		//delete[] wskNowy;
		ileKropek = nowaWielkosc;
	}
}
