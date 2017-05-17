#include "Mapa.h"


int Mapa::wczytajMapeZPliku(std::string nazwaPliku)
{
	Kolizja TablicaPodstKolizji[] =
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

	fstream plik;
	string scieszka = ".\\maps\\";
	scieszka += nazwaPliku;
	int licznik = 0;
	int licznikDodatkowy = 0;

	plik.open(scieszka, ios::in);

	string linia;

	if (plik.good())
	{
		try  // w instrukcjach poni¿ej mo¿e coœ siê nie udaæ
		{
			cout << "--> plik mapy jest dostepny" << endl;
			while (!plik.eof() )
			{
				getline(plik, linia);

				if(linia.substr(0,2)=="//")
					licznik++;
			}

			ileKolizji = licznik;

			#ifdef TEST
				cout <<"--> W pliku wykryto "<< licznik << " kolizji" << endl;
			#endif // TEST

			// tworzenie w³asciwej mapy kolizji
			delete[] mapaKolizjiZPliku;
			mapaKolizjiZPliku = new Kolizja[licznik];

			//ustawianie wskaznika w pliku na pocz¹tek
			plik.clear();
			plik.seekg(0, ios::beg);

			while (!plik.eof())
			{
				if (licznikDodatkowy == 0)
				{
					getline(plik, nazwaMapy);
					#ifdef TEST
					cout << "--> nazwa pliku z mapa: " << nazwaMapy << endl;
					#endif TEST
				}	
				else
				if (licznikDodatkowy == 1)
				{
					getline(plik, linia);
					std::string::size_type sz;
					rozmiarMapyX= std::stoi(linia, &sz);
					#ifdef TEST
					cout << "--> szerokosc mapy: " << rozmiarMapyX << "px" << endl;
					#endif TEST
				}
				else
				if (licznikDodatkowy == 2)
				{
					getline(plik, linia);
					std::string::size_type sz;
					rozmiarMapyY = std::stoi(linia, &sz);
					#ifdef TEST
					cout << "--> wysokosc mapy: " << rozmiarMapyY << "px" << endl;
					#endif TEST
				}
				else
				if (licznikDodatkowy == 3)
				{
					getline(plik, linia);
					std::string::size_type sz;
					string pomoc = linia.substr(0, 3);
					StartBohateraX = std::stoi(pomoc, &sz);
					#ifdef TEST
					cout << "--> start x: " << pomoc << endl;
					#endif TEST
				}
				else
				if (licznikDodatkowy == 4)
				{
					getline(plik, linia);
					std::string::size_type sz;
					string pomoc = linia.substr(0, 3);
					StartBohateraY = std::stoi(pomoc, &sz);
					#ifdef TEST
					cout << "--> start y: " << pomoc << endl;
					#endif TEST
				}
				else
				{
					int i = 0;// licznik kolizji
					while(!plik.eof())
					{		
						getline(plik, linia);

						if (linia.substr(0, 2) == "//")
						{
							if (!plik.eof()) //rodzaj kolizji 
							{
								getline(plik, linia);
								if (!sprawdzCzyliczba(linia))
								{
									string wyjatek = "-->1 Blad wczytywania z pliku ";
									throw wyjatek;
									return 0;
								}
								/*
								for(int i = 0 ; i< linia.length(); i++)//sprawdzanie poprawnosci zapisu danych w pliku txt
									if (linia.at(i) == '0' ||
										linia.at(i) == '1' ||
										linia.at(i) == '2' ||
										linia.at(i) == '3' ||
										linia.at(i) == '4' ||
										linia.at(i) == '5' ||
										linia.at(i) == '6' ||
										linia.at(i) == '7' ||
										linia.at(i) == '8' ||
										linia.at(i) == '9' ||
										linia.at(i) == ' ')
									{

									}else
									{
										string wyjatek = "-->1 Blad wczytywania z pliku ";
										throw wyjatek;
									}
										*/
								std::string::size_type sz;
								int pomoc = std::stoi(linia, &sz);
								if (pomoc >= 0 && pomoc <= 10)
								{
									mapaKolizjiZPliku[i] = TablicaPodstKolizji[pomoc];
								}
								
							}
							
							if (!plik.eof()) // wsp. kolizji
							{
								getline(plik, linia);
								if (!sprawdzCzyliczba(linia.substr(0, 3)))
								{
									string wyjatek = "-->2 Blad wczytywania z pliku ";
									throw wyjatek;
									return 0;
								}
								/*
								for (int i = 0; i< linia.substr(0, 3).length(); i++)//sprawdzanie poprawnosci zapisu danych w pliku txt
									if (linia.at(i) == '0' ||
										linia.at(i) == '1' ||
										linia.at(i) == '2' ||
										linia.at(i) == '3' ||
										linia.at(i) == '4' ||
										linia.at(i) == '5' ||
										linia.at(i) == '6' ||
										linia.at(i) == '7' ||
										linia.at(i) == '8' ||
										linia.at(i) == '9' ||
										linia.at(i) == ' '
										)
									{

									}
									else
									{
										string wyjatek = "-->2 Blad wczytywania z pliku linia: " + linia ;
										throw wyjatek;
									}*/
								if (!sprawdzCzyliczba(linia.substr(4, 4)))
								{
									string wyjatek = "-->3 Blad wczytywania z pliku ";
									throw wyjatek;
									return 0;
								}
								/*
								for (int i = 0; i< linia.substr(4, 4).substr(0, 3).length(); i++)//sprawdzanie poprawnosci zapisu danych w pliku txt
									if (linia.at(i) == '0' ||
										linia.at(i) == '1' ||
										linia.at(i) == '2' ||
										linia.at(i) == '3' ||
										linia.at(i) == '4' ||
										linia.at(i) == '5' ||
										linia.at(i) == '6' ||
										linia.at(i) == '7' ||
										linia.at(i) == '8' ||
										linia.at(i) == '9' ||
										linia.at(i) == ' '
										)
									{

									}
									else
									{
										string wyjatek = "-->2 Blad wczytywania z pliku linia: " + linia;
										throw wyjatek;
									}
									*/

								std::string::size_type sz;
								int pomocI = std::stoi(linia.substr(0, 3), &sz);
								int pomocII = std::stoi(linia.substr(4, 4), &sz);

								//cout << i << " " <<pomocI << " "<< pomocII << endl;
								mapaKolizjiZPliku[i].daj_wsp(pomocI, pomocII);
								mapaKolizjiZPliku[i].stworz(); // aktualizacja wspó³¿êdnych kolizji, ustalanie wielkoœci i koloru

							}
							i++;
						}
						
					}
					break;
				}
				//break;
				licznikDodatkowy++;
			}
		}
		catch (std::string blad)
		{
			cout << blad << endl;
			bool zamknij = 1;
			return 1;
		}
		plik.close();
	}
	else
		cout << "blad mapy" << endl;
	return 0;
}

void Mapa::rysuj_kolizje(RenderWindow * okno)
{
	for (int i = 0; i < ileKolizji; i++)
	{
		okno->draw(mapaKolizjiZPliku[i].pole_kolizji);
		//cout << mapaKolizjiZPliku[i].pocz_x << " " << mapaKolizjiZPliku[i].pocz_y << endl;
	}
}

bool Mapa::WczytanoMape()
{
	return WczytywanieZakonczonePowodzeniem;
}
 
Kolizja * Mapa::dajMapeKolizji()
{
	return mapaKolizjiZPliku;
}

Sprite Mapa::rysuj()
{
	return Obraz;
}

Wektor Mapa::dajStartPacMan()
{
	Wektor moj_wektor;
	moj_wektor.x = StartBohateraX;
	moj_wektor.y = StartBohateraY;

	return moj_wektor;
}

bool Mapa::sprawdzCzyliczba(string linia)
{
	for (int i = 0; i < linia.length(); i++)//sprawdzanie poprawnosci zapisu danych w pliku txt
	{
		if (!(linia.at(i) == '0' ||
			linia.at(i) == '1' ||
			linia.at(i) == '2' ||
			linia.at(i) == '3' ||
			linia.at(i) == '4' ||
			linia.at(i) == '5' ||
			linia.at(i) == '6' ||
			linia.at(i) == '7' ||
			linia.at(i) == '8' ||
			linia.at(i) == '9' ||
			linia.at(i) == ' '))
		{
			return false;
		}
	}
	return true;
}

Mapa::Mapa(int pozycja_poczatkowa_x, int pozycja_poczatkowa_y)
	:pozycja_x(pozycja_poczatkowa_x),
	pozycja_y(pozycja_poczatkowa_y)
{

	mapaKolizjiZPliku = new Kolizja[1];// mapa z pusta kokizja
	WczytywanieZakonczonePowodzeniem = true;

	if (wczytajMapeZPliku())
	{
		WczytywanieZakonczonePowodzeniem = false;
	}

	tekstura.loadFromFile(nazwaMapy);
	Obraz.setTexture(tekstura);
	Obraz.setPosition(Vector2f(pozycja_poczatkowa_x, pozycja_poczatkowa_y));
}

Mapa::~Mapa()
{
	delete[] mapaKolizjiZPliku;
}


