#include "Mapa.h"


int Mapa::wczytajMapeZPliku(std::string nazwaPliku)
{
	fstream plik;
	string scieszka = "./maps/";
	scieszka += nazwaPliku;
	int licznik = 0, licznikDodatkowy = 0;
	plik.open(".\\maps\\mapa.txt", ios::in);

	string linia;

	if (plik.good())
	{
		cout << "plik mapy jest dostepny" << endl;
		/*while (! plik.eof())
		{
			licznik++;
		}
		//plik.clear();
		/*
		cout << "plik mapy jest dostepny" << endl;
		plik.seekg(0, ios::beg);
		cout << "plik mapy jest dostepny" << endl;
		*/

		plik.close();
	}
	else
		cout << "blad mapy" << endl;
	return 0;
}
 
Kolizja * Mapa::daj_mape_kolizji()
{
	return mapa_kolizji;
}

Sprite Mapa::rysuj()
{
	return Obraz;
}

Mapa::Mapa(std::string nazwa_bitmapy, Wektor pobMapa, int pozycja_poczatkowa_x, int pozycja_poczatkowa_y, int przesuniecie_w_dol)
	:pozycja_x(pozycja_poczatkowa_x),
	pozycja_y(pozycja_poczatkowa_y),
	StartBohateraX(pobMapa.x),
	StartBohateraY(pobMapa.y)
{
	tekstura.loadFromFile(nazwa_bitmapy);
	Obraz.setTexture(tekstura);
	Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));

	stworz_kolizje_dla_mapy(65, mapa_kolizji);

	//mapaKolizjiZPliku = new Kolizja[1];// mapa z pusta kokizja

	//Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));
}

Mapa::~Mapa()
{
	//delete[] mapaKolizjiZPliku;
}
