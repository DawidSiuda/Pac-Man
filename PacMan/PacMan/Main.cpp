#include "Mapa.h"
#include "Duch.h"
#include "PacMan.h"
#include "Lista_zmiennych_stalych.cpp"
#include "NoweOknoKomunikatu.h"
#include "Napis.h"
#include "MapaPunktow.h"

#include <SFML/Graphics.hpp>
#include <iostream>

extern void obsluzBuforRuchu(Postac *);
extern void obsluzKolizjeMapy(Postac *, int, Kolizja *);
extern void obsluzKolizjeKropek(PacMan  *, BialyPunkt *, int );
using namespace sf;

int main()
{
	////////////////////////////////////////////////////////////
	//tworzenie podstawowych obiektow

	Event event; // obiekt przechowuj¹cy wszystkie zdarzenia (naciœniêcia klawiszy itp.)
	Clock clock; // zerar pilnuj¹cy rysowania sceny wzgledem up³ynêtego czasu
	Clock zegar; // zegar pilnuj¹cy zamykania ust pacmana
	Clock zegarDuchy;// zegar pilnuj¹cy ruchu duchow
	RenderWindow okno(VideoMode(SZEROKOSC_OKNA, WYSOKOSC_OKNA), "Pac-Man");// tworzy okno
	Mapa mapa(50, 60); //tworzy mape

	//ekran wczytywania
	{
		okno.clear(); // czyszczenie ekranu
		NoweOknoKomunikatu komunikatLaduj("LOADING...", 220, 320, 40);// tworzy komunikat dla loading
		komunikatLaduj.wyswietl(&okno);
		okno.display(); // wyswietl wyrysowane okno
	} 

	if (mapa.WczytanoMape() == false)
	{
		std::cout << "BLAD WCZYTANIA MAPY" << endl;
		NoweOknoKomunikatu blad("BLAD WCZYTANIA MAPY \n       Nacisnij Esc aby\n    zakonczyc program");
		blad.wyswietl();
		exit(0);
	}

	MapaPunktow mapaPunktow;
	mapaPunktow.tworzMapePunktow(mapa.dajMapeKolizji(), mapa.iloscKolizji());

	PacMan Pac_Man(100, mapa.dajStartPacMan());// tworzy pacmana

	Duch czerwony("czerwony.png", 275, 326, 1);// tworzy ducha
	Duch rozowy("rozowy.png", 347, 326, 5);// tworzy ducha
	Duch pomaranczowy("pomaranczowy.png", 300, 326, 10);// tworzy ducha
	Duch niebieski("niebieski.png", 325, 326, 15);// tworzy ducha

	NoweOknoKomunikatu komunikatPauza("PAUSE", 260, 320, 40, "Press Esc to Continue", 130, 380, 30);// tworzy komunikat dla pauzy
	NoweOknoKomunikatu komunikatStart( "Press Enter to Start", 190, 380, 20);// tworzy komunikat dla Start
	Napis kierunek(30,680, 20, Color(255, 255, 255)); // tworzy napis przeznaczony do wyswietlania loga pac-mana
	Napis logo(230, 10, 35, Color(255, 255, 255), "PAC-FONT.TTF");// tworzy napis przeznaczony do wyswietlania kierunku u do³u ekranu gry
	Napis logoStartowe(70, 200, 90, Color(255, 255, 255), "PAC-FONT.TTF");// tworzy napis przeznaczony do wyswietlania napisu Pac-Man w menu startowym gry

	short pauza = 2; // zmienna informuje czy rozgrywak, jest zatrzymana, trwa lub wyswietlany jest ekran startowy

	////////////////////////////////////////////////////////////
	//przygotowanie okna aplikacji

	okno.setFramerateLimit(60); // limit FPS 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	////////////////////////////////////////////////////////////
	//g³ówna pêtla aplikacji
	clock.restart();// czas mierzony od pocz¹tku

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
				if (pauza == 1)
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
						pauza = 0;
						break;
					}
					}
				}

				// obsluga klawiatury podczas pauzy, np.powrót do gry
				else if (pauza == 0)
				{
					switch (event.key.code)
					{
					case(Keyboard::Escape):
					{
						pauza = 1;
						clock.restart(); //zeruje czas który up³yn¹³ od ostatniej klatki
						zegarDuchy.restart();//zeruje czas który up³yn¹³ od ostatniej klatki
						break;
					}
					case(Keyboard::Space):
					{
						okno.close();
						break;
					}
					}
				}
				else if (pauza ==2)
				{
					switch (event.key.code)
					{
					case(Keyboard::Return):
					{
						pauza = 1;
						clock.restart(); //zeruje czas który up³yn¹³ od ostatniej klatki
						zegarDuchy.restart();//zeruje czas który up³yn¹³ od ostatniej klatki
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


		if (pauza == 1)
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
			obsluzKolizjeKropek(&Pac_Man, mapaPunktow.dajMape(), mapaPunktow.ilePunktow());


			////////////////////////////////////////////////////////////////////////////////////////
			//loczenie kolizji dochow z mapa

			obsluzKolizjeMapy(&czerwony, mapa.iloscKolizji(), mapa.dajMapeKolizji());
			obsluzKolizjeMapy(&pomaranczowy, mapa.iloscKolizji(), mapa.dajMapeKolizji());
			obsluzKolizjeMapy(&rozowy, mapa.iloscKolizji(), mapa.dajMapeKolizji());
			obsluzKolizjeMapy(&niebieski, mapa.iloscKolizji(), mapa.dajMapeKolizji());

			////////////////////////////////////////////////////////////////////////////////////////
			//obsluga  AI duchow

			czerwony.AI(&Pac_Man, zegarDuchy.getElapsedTime().asSeconds());
			rozowy.AI(&Pac_Man, zegarDuchy.getElapsedTime().asSeconds());
			pomaranczowy.AI(&Pac_Man, zegarDuchy.getElapsedTime().asSeconds());
			niebieski.AI(&Pac_Man, zegarDuchy.getElapsedTime().asSeconds());

			////////////////////////////////////////////////////////////////////////////////////////
			//loczenie nowej pozycji duchow
			float przemieszczenie = czerwony.dajPredkosc() * zegarDuchy.getElapsedTime().asSeconds();

			czerwony.zmianaPozycji(przemieszczenie, czerwony.dajKierunek());
			pomaranczowy.zmianaPozycji(przemieszczenie, pomaranczowy.dajKierunek());
			rozowy.zmianaPozycji(przemieszczenie, rozowy.dajKierunek());
			niebieski.zmianaPozycji(przemieszczenie, niebieski.dajKierunek());

			zegarDuchy.restart();// czas mierzony od pocz¹tku

			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny
			
				okno.clear(); // czyszczenie ekranu

				logo.wyswietl(&okno, "PAC-MAN"); // rysuje logo

				okno.draw(mapa.rysuj()); // rysuj mape

				mapaPunktow.rysuj(&okno); // rysuje bia³ê punkty

				okno.draw(*Pac_Man.cialo);// rysuj pacmana

				okno.draw(*czerwony.cialo);// rysuj ducha
				okno.draw(*niebieski.cialo);// rysuj ducha
				okno.draw(*pomaranczowy.cialo);// rysuj ducha
				okno.draw(*rozowy.cialo);// rysuj ducha


				//mapa.rysuj_kolizje(&okno); // rysuj obszary kolizyjne

				switch (Pac_Man.daj_kier_w_bufor())
				{
				case 1: kierunek.wyswietl(&okno, "Next direction: Up"); break;
				case 2: kierunek.wyswietl(&okno, "Next direction: Right"); break;
				case 3: kierunek.wyswietl(&okno, "Next direction: Down"); break;
				case 4: kierunek.wyswietl(&okno, "Next direction: Left"); break;
				}

				okno.display();// wyswietl wyrysowane okno

			//rysowanie sceny
			//////////////////////////////////////////////////////////////////////

		}
		else if (pauza == 0)
		{
			okno.clear(); // czyszczenie ekranu

			logo.wyswietl(&okno, "PAC-MAN"); // rysuje logo
			okno.draw(mapa.rysuj()); // rysuj mape
			mapaPunktow.rysuj(&okno); // rysuje bia³ê punkty
			okno.draw(*Pac_Man.cialo); // rysuj pacmana

			okno.draw(*czerwony.cialo);// rysuj ducha
			okno.draw(*niebieski.cialo);// rysuj ducha
			okno.draw(*pomaranczowy.cialo);// rysuj ducha
			okno.draw(*rozowy.cialo);// rysuj ducha
			
			//mapa.rysuj_kolizje(&okno);
			komunikatPauza.wyswietl(&okno);

			okno.display(); // wyswietl wyrysowane okno
		}
		else if (pauza == 2)
		{
			okno.clear(); // czyszczenie ekranu

			//logo.wyswietl(&okno, "PAC-MAN"); // rysuje logo
			okno.draw(mapa.rysuj()); // rysuj mape
			mapaPunktow.rysuj(&okno); // rysuje bia³ê punkty
			okno.draw(*Pac_Man.cialo); // rysuj pacmana

			okno.draw(*czerwony.cialo);// rysuj ducha
			okno.draw(*niebieski.cialo);// rysuj ducha
			okno.draw(*pomaranczowy.cialo);// rysuj ducha
			okno.draw(*rozowy.cialo);// rysuj ducha

									   //mapa.rysuj_kolizje(&okno);
			komunikatStart.wyswietl(&okno);
			logoStartowe.wyswietl(&okno, "PAC-MAN"); // rysuje logo

			okno.display(); // wyswietl wyrysowane okno
		}
	}
	return 0;
}