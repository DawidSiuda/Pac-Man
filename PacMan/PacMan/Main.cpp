#include "Mapa.h"
#include "Duch.h"
#include "PacMan.h"
#include "Lista_zmiennych_stalych.cpp"
#include "NoweOknoKomunikatu.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	////////////////////////////////////////////////////////////
	//tworzenie podstawowych obiektow

	Event event; // obiekt przechowuj¹cy wszystkie zdarzenia (naciœniêcia klawiszy itp.)
	Clock clock; // zerar pilnuj¹cy rysowania sceny wzgledem up³ynêtego czasu
	Clock zegar; // zegar pilnuj¹cy zamykania ust pacmana
	RenderWindow okno(VideoMode(SZEROKOSC_OKNA, WYSOKOSC_OKNA), "Pac-Man");// tworzy okno
	Mapa mapa(50, 60); //tworzy mape
	if (mapa.WczytanoMape() == false)
	{
		std::cout << "BLAD WCZYTANIA MAPY" << endl;
		NoweOknoKomunikatu blad("BLAD WCZYTANIA MAPY \n      Press Esc to Exit");
		blad.wyswietl();
		exit(0);
	}

	PacMan Pac_Man(100, mapa.dajStartPacMan());// tworzy pacmana

	bool pauza = false; // zmienna informuje czy rozgrywaka nie jest zatrzymana

	////////////////////////////////////////////////////////////
	//przygotowanie okna aplikacji

	okno.setFramerateLimit(60); // limit FPS 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	//////////////////////////////////////////////////////////

	while (okno.isOpen()) //g³ówna pêtla gry
	{

		while (okno.pollEvent(event)) // petla obs³ugi wydarzeñ
		{
			switch (event.type)
			{
			case (Event::Closed):	//obs³uga przycisku zamkniêcia okna
			{
				okno.close();
				break;
			}
			case (Event::KeyPressed): // obs³uga klawiszy klawiatury
			{
				// obsluga klawiatury podczas gry, np.strza³ek
				if (pauza == false)
				{
					switch (event.key.code)
					{
					case(Keyboard::Left):
					{
						Pac_Man.zmianaBuforowanegoKierunku(LEWO);
						break;
					}
					case(Keyboard::Right):
					{
						Pac_Man.zmianaBuforowanegoKierunku(PRAWO);
						break;
					}
					case(Keyboard::Up):
					{
						Pac_Man.zmianaBuforowanegoKierunku(GORA);
						break;
					}
					case(Keyboard::Down):
					{
						Pac_Man.zmianaBuforowanegoKierunku(DOL);
						break;
					}
					case(Keyboard::Escape):
					{
						pauza = true;
						break;
					}
					}
				}

				// obsluga klawiatury podczas pauzy, np.powrót do gry
				else if (pauza == true)
				{
					switch (event.key.code)
					{
					case(Keyboard::Escape):
					{
						pauza = false;
						clock.restart(); //zeruje czas który up³yn¹³ od ostatniej klatki
						break;
					}
					}
				}
				break;
			}
			case(Event::MouseButtonPressed)://obs³uga lewego przycisku myszy
			{
				std::cout << Mouse::getPosition(okno).x << " " << Mouse::getPosition(okno).y << std::endl;
				break;
			}

			}
		} //while


		if (pauza == false)
		{ 
			//liczenie nowej pozycji pacman
			float przesuniecie = Pac_Man.dajPredkosc() * clock.getElapsedTime().asSeconds();
			Pac_Man.zmiana_pozycji(przesuniecie,Pac_Man.daj_kierunek());
			clock.restart();// czas mierzony od pocz¹tku


			//////////////////////////////////////////////////////////////////////
			//sprawdzanie kolizji pacmana z mapa
			obsluz_kolizje_mapy(mapa.dajMapeKolizji(),
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

			//mapa.rysuj_kolizje(&okno); // rysuj obszary kolizyjne

			////////////////////////////////////////////////////////////
			//USUN¥C
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
				okno.draw(napis);
				switch (Pac_Man.daj_kier_w_bufor())
				{
				case 1: napis.setString("GÓRA"); break;
				case 2: napis.setString("PRAWO"); break;
				case 3: napis.setString("DÓL"); break;
				case 4: napis.setString("LEWO"); break;
				}
			#endif // TEST
			//USUN¥C
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

			//mapa.rysuj_kolizje(&okno);

			////////////////////////////////////////////////////////////
			//USUN¥C
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
				switch (pauza)
				{
				case true: napis.setString("PAUZA"); break;

				}
				okno.draw(napis);
			#endif // TEST
			//USUN¥C
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