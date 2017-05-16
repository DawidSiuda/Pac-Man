#include "Mapa.h"
#include "Duch.h"
#include "PacMan.h"
#include "Lista_zmiennych_stalych.cpp"


//#include "stworz_kolizje_dla_mapy.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include <Windows.h>

using namespace sf;

int main()
{
	////////////////////////////////////////////////////////////
	//tworzenie podstawowych obiektow
	Event event; // obiekt przechowuj�cy wszystkie zdarzenia (naci�ni�cia klawiszy itp.)
	Clock clock; // zerar pilnuj�cy rysowania sceny wzgledem up�yn�tego czasu
	Clock zegar; // zegar pilnuj�cy zamykania ust pacmana
	RenderWindow okno(VideoMode(SZEROKOSC_OKNA, WYSOKOSC_OKNA), "Pac-Man");// tworzy okno

	Mapa mapa("mapa.jpg", Mapa::dajMape(), 50, 60); //tworzy mape
	PacMan Pac_Man(3, 100, LEWO, mapa.pozycja_x, mapa.pozycja_y, false);// tworzy pacmana
	mapa.wczytajMapeZPliku();
	bool pauza = false; // zmienna informuje czy rozgrywaka nie jest zatrzymana

						////////////////////////////////////////////////////////////
						//przygotowanie okna aplikacji
	okno.setFramerateLimit(60); // limit FPS 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow�



									  ////////////////////////////////////////////////////////////
									  //USUN�C
#ifdef TEST

	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "blad wczytania font-u" << std::endl;
	}
	Text napis;
	napis.setFont(font);
	napis.setPosition(Vector2f(200, 700));
	napis.setCharacterSize(24);
#endif // TEST
	//USUN�C
	//////////////////////////////////////////////////////////

	while (okno.isOpen()) //g��wna p�tla gry
	{

		while (okno.pollEvent(event)) // petla obs�ugi wydarze�
		{
			switch (event.type)
			{
			case (Event::Closed):	//obs�uga przycisku zamkni�cia okna
			{
				okno.close();
				break;
			}
			case (Event::KeyPressed): // obs�uga klawiszy klawiatury
			{
				// obsluga klawiatury podczas gry, np.strza�ek
				if (pauza == false)
				{
					switch (event.key.code)
					{
					case(Keyboard::Left):
					{
						Pac_Man.zmiana_kierunku(LEWO);
						break;
					}
					case(Keyboard::Right):
					{
						Pac_Man.zmiana_kierunku(PRAWO);
						break;
					}
					case(Keyboard::Up):
					{
						Pac_Man.zmiana_kierunku(GORA);
						break;
					}
					case(Keyboard::Down):
					{
						Pac_Man.zmiana_kierunku(DOL);
						break;
					}
					case(Keyboard::Escape):
					{
						pauza = true;
						break;
					}
					}
				}

				// obsluga klawiatury podczas pauzy, np.powr�t do gry
				else if (pauza == true)
				{
					switch (event.key.code)
					{
					case(Keyboard::Escape):
					{
						pauza = false;
						clock.restart(); //zeruje czas kt�ry up�yn�� od ostatniej klatki
						break;
					}
					}
				}
				break;
			}
			case(Event::MouseButtonPressed)://obs�uga lewego przycisku myszy
			{
				std::cout << Mouse::getPosition(okno).x << " " << Mouse::getPosition(okno).y << std::endl;
				break;
			}

			}
		} //while


		if (pauza == false)
		{
			//////////////////////////////////////////////////////////////////////
			//liczenie nowej pozycji pacman
			//bior�c pod uwage czasu kt�ry up�yn�� od oststniej klatki

			//	float przemieszczenie_pacmana = pac_man.dajPredkosc() * czas_od_oststniej_klatki;

			Pac_Man.zmiana_pozycji(clock.getElapsedTime().asSeconds());

			//std::cout << Clock.getElapsedTime().asSeconds() << std::endl; // czas od ostatniej klatki
			clock.restart();// czas mierzony od pocz�tku

							//liczenie nowej pozycji pacman 
							//bior�c pod uwage czasu kt�ry up�yn�� od oststniej klatki
							//////////////////////////////////////////////////////////////////////

							//////////////////////////////////////////////////////////////////////
							//sprawdzanie kolizji pacmana z mapa
			obsluz_kolizje_mapy(mapa.daj_mape_kolizji(),
				ILE_KOLIZJI,
				Pac_Man.daj_xy(),
				Pac_Man.daj_kierunek(),
				Pac_Man.daj_kier_w_bufor(),
				&Pac_Man);
			//sprawdzanie kolizji pacmana z mapa
			//////////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////////
			//otwieranie i zamykanie ust pac-mana
			if (zegar.getElapsedTime().asSeconds() > CZESTOTLIWOSC)
			{
				// std::cout << zegar.getElapsedTime().asSeconds() << std::endl;
				Pac_Man.zamknij_paszcze();
				zegar.restart();
			}
			//otwieranie i zamykanie ust pac-mana
			//////////////////////////////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny
			okno.clear(); // czyszczenie ekranu

			okno.draw(mapa.rysuj()); // rysuj mape

			okno.draw(*Pac_Man.cialo);// rysuj pacmana

									  //rysuj_kolizje(ILE_KOLIZJI, Mapa.daj_mape_kolizji(), &okno); // rysuj obszary kolizyjne

									  ////////////////////////////////////////////////////////////
									  //USUN�C
#ifdef TEST
			okno.draw(napis);
			switch (Pac_Man.daj_kier_w_bufor())
			{
			case 1: napis.setString("G�RA"); break;
			case 2: napis.setString("PRAWO"); break;
			case 3: napis.setString("D�L"); break;
			case 4: napis.setString("LEWO"); break;
			}
#endif // TEST
			//USUN�C
			////////////////////////////////////////////////////////////

			okno.display();// wyswietl wyrysowane okno
						   //rysowanie sceny
						   //////////////////////////////////////////////////////////////////////

		}
		else if (pauza == true)
		{
			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny

			okno.clear();
			okno.draw(mapa.rysuj());
			okno.draw(*Pac_Man.cialo);

			//rysuj_kolizje(ILE_KOLIZJI, Mapa.daj_mape_kolizji(), &okno);

			////////////////////////////////////////////////////////////
			//USUN�C
#ifdef TEST
			switch (pauza)
			{
			case true: napis.setString("PAUZA"); break;

			}
			okno.draw(napis);
#endif // TEST
			//USUN�C
			////////////////////////////////////////////////////////////

			////////////////////////////////////////////////////////////
			//zrobic okno pauzy
			////////////////////////////////////////////////////////////
			okno.display();

			//rysowanie sceny
			//////////////////////////////////////////////////////////////////////
		}
	}
	return 0;
}