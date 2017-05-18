#include "Mapa.h"
#include "Duch.h"
#include "PacMan.h"
#include "Lista_zmiennych_stalych.cpp"
#include "NoweOknoKomunikatu.h"
#include "Napis.h"

#include <SFML/Graphics.hpp>
#include <iostream>

extern void obsluzBuforRuchu(Postac *);
extern void obsluzKolizjeMapy(Postac *, int, Kolizja *);
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
		NoweOknoKomunikatu blad("BLAD WCZYTANIA MAPY \n       Nacisnij Esc aby\n    zakonczyc program");
		blad.wyswietl();
		exit(0);
	}

	PacMan Pac_Man(100, mapa.dajStartPacMan());// tworzy pacmana
	NoweOknoKomunikatu komunikatPauza("PAUSE", 260, 320, 40, "Press Esc to Continue", 130, 380, 30);// tworzy komunikat dla pauzy
	Napis kierunek(30,680, 20, Color(255, 255, 255)); // tworzy napis przeznaczony do wyswietlania loga pac-mana
	Napis logo(230, 10, 35, Color(255, 255, 255), "PAC-FONT.TTF");// tworzy napis przeznaczony do wyswietlania kierunku u do³u ekranu gry

	bool pauza = false; // zmienna informuje czy rozgrywaka nie jest zatrzymana

	////////////////////////////////////////////////////////////
	//przygotowanie okna aplikacji

	okno.setFramerateLimit(60); // limit FPS 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	////////////////////////////////////////////////////////////
	//g³ówna pêtla aplikacji

	while (okno.isOpen()) 
	{

		// petla obs³ugi wydarzeñ
		while (okno.pollEvent(event))// petla obs³ugi wydarzeñ
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

			//otwieranie i zamykanie ust pac-mana
			if (zegar.getElapsedTime().asSeconds() > TIME_TO_CHANGE_MOUTH)
			{
				Pac_Man.zamknij_paszcze();
				zegar.restart();
			}

			//sprawdzanie kolizji pac-mana z map¹
			obsluzBuforRuchu(&Pac_Man);
			obsluzKolizjeMapy(&Pac_Man, mapa.iloscKolizji(), mapa.dajMapeKolizji());

			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny
			
				okno.clear(); // czyszczenie ekranu

				logo.wyswietl(&okno, "PAC-MAN"); // rysuje logo

				okno.draw(mapa.rysuj()); // rysuj mape

				okno.draw(*Pac_Man.cialo);// rysuj pacmana

				//mapa.rysuj_kolizje(&okno); // rysuj obszary kolizyjne

				switch (Pac_Man.daj_kier_w_bufor())
				{
				case 1: kierunek.wyswietl(&okno, "kolejny kierunek: GÓRA"); break;
				case 2: kierunek.wyswietl(&okno, "kolejny kierunek: PRAWO"); break;
				case 3: kierunek.wyswietl(&okno, "kolejny kierunek: DÓL"); break;
				case 4: kierunek.wyswietl(&okno, "kolejny kierunek: LEWO"); break;
				}

				okno.display();// wyswietl wyrysowane okno

			//rysowanie sceny
			//////////////////////////////////////////////////////////////////////

		}
		else if (pauza == true)
		{
			okno.clear(); // czyszczenie ekranu

			logo.wyswietl(&okno, "PAC-MAN"); // rysuje logo
			okno.draw(mapa.rysuj()); // rysuj mape
			okno.draw(*Pac_Man.cialo); // rysuj pacmana
			//mapa.rysuj_kolizje(&okno);
			komunikatPauza.wyswietl(&okno);

			okno.display(); // wyswietl wyrysowane okno
		}
	}
	return 0;
}