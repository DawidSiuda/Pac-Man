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
extern void obsluzKolizjeKropek(PacMan  *, BialyPunkt *, int , MapaPunktow *);
extern bool obsluzkolizjePacman_duchy(Wektor pacman, Wektor czerwony, Wektor niebieski, Wektor rozowy, Wektor pomaranczowy);
using namespace sf;

int main()
{
	bool czGraTrwa = true;
	do
	{
		////////////////////////////////////////////////////////////
		//tworzenie podstawowych obiektow

		Event event; // obiekt przechowuj¹cy wszystkie zdarzenia (naciœniêcia klawiszy itp.)
		Clock clock; // zerar pilnuj¹cy rysowania sceny wzgledem up³ynêtego czasu
		Clock zegar; // zegar pilnuj¹cy zamykania ust pacmana
		Clock zegarDuchy;// zegar pilnuj¹cy ruchu duchow
		RenderWindow okno(VideoMode(SZEROKOSC_OKNA, WYSOKOSC_OKNA), "Pac-Man");// tworzy okno

		//ekran wczytywania
		{
			okno.clear(); // czyszczenie ekranu
			NoweOknoKomunikatu komunikatLaduj("LOADING...", 220, 320, 40);// tworzy komunikat dla loading
			komunikatLaduj.wyswietl(&okno);
			okno.display(); // wyswietl wyrysowane okno
		}

		Mapa mapa(50, 60); //tworzy mape
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
		NoweOknoKomunikatu komunikatStart("Press Enter to Start", 190, 380, 20);// tworzy komunikat dla Start
		NoweOknoKomunikatu komunikatKoniecGry("GAME OVER", 200, 270, 40, " Space: Continue  Esc: Exit", 90, 380, 30 );// tworzy komunikat dla game over
		NoweOknoKomunikatu komunikatWygrales("VICTROY", 160, 270, 70, " Space: Continue  Esc: Exit", 90, 380, 30);// tworzy komunikat wygranej
		Napis kierunek(350, 680, 20, Color(255, 255, 255)); // tworzy napis przeznaczony do wyswietlania loga pac-mana
		Napis logo(230, 10, 35, Color(255, 255, 255), "PAC-FONT.TTF");// tworzy napis przeznaczony do wyswietlania kierunku u do³u ekranu gry
		Napis logoStartowe(70, 200, 90, Color(255, 255, 255), "PAC-FONT.TTF");// tworzy napis przeznaczony do wyswietlania napisu Pac-Man w menu startowym gry
		Napis iloscZyc(30, 680, 20, Color(255, 255, 255)); 
		Napis ileprocent(30, 710,20, Color(255, 255, 255));


		short pauza =2; // zmienna informuje czy rozgrywak, jest zatrzymana, trwa lub wyswietlany jest ekran startowy

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
						czGraTrwa = false;
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
							case(Keyboard::X):
							{
								cout << Pac_Man.daj_xy().x << " | " << Pac_Man.daj_xy().y<<endl;
								cout << czerwony.dajXY().x << " | " << czerwony.dajXY().y << endl;
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
								czGraTrwa = false;
								break;
							}
							}
						}
						else if (pauza == 2)
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
						else if (pauza == 3 || pauza == 4)
						{
							switch (event.key.code)
							{
							case(Keyboard::Escape):
							{
								okno.close();
								czGraTrwa = false;
								break;
							}
							case(Keyboard::Space):
							{
								okno.close();
								czGraTrwa =true;
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
				}//switch(event.type)
			} //while


			if (pauza == 1)
			{
				//liczenie nowej pozycji pacman
				float przesuniecie = Pac_Man.dajPredkosc() * clock.getElapsedTime().asSeconds();
				Pac_Man.zmiana_pozycji(przesuniecie, Pac_Man.daj_kierunek());
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
				obsluzKolizjeKropek(&Pac_Man, mapaPunktow.dajMape(), mapaPunktow.ilePunktow(), &mapaPunktow);


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

				////////////////////////////////////////////////////////////////////////////////////////
				//loczenie kolizji pacman - duchy

				if (obsluzkolizjePacman_duchy(Pac_Man.daj_xy(), czerwony.dajXY(), niebieski.dajXY(), rozowy.dajXY(), pomaranczowy.dajXY()))
				{
					Pac_Man.zabierzZycie();
					if (Pac_Man.dajLiczbeZyc() < 0)
					{
						Pac_Man.ustawIloscZycie(0);
						pauza = 3;
					}
					else
					{
						//acMan Pac_Man(100, mapa.dajStartPacMan());
						Pac_Man.zmiana_pozycji((int)mapa.dajStartPacMan().x, (int)mapa.dajStartPacMan().y);
						Pac_Man.ustawKierunek(LEWO);
						Pac_Man.zmien_teksture(LEWO);
						Pac_Man.zmianaBuforowanegoKierunku(LEWO);
					}


				}
				////////////////////////////////////////////////////////////////////////////////////////
				//sprawdzenie czy koniec gry (czy pacman zjad³ wszystkie kropki)

				if (mapaPunktow.dajProcent() == 100)
				{
					pauza = 4;
				}

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

				string zycie = to_string(Pac_Man.dajLiczbeZyc());
				iloscZyc.wyswietl(&okno, "lives: "+zycie);
				zycie = to_string(mapaPunktow.dajProcent());
				ileprocent.wyswietl(&okno,zycie+"%");

				okno.display();// wyswietl wyrysowane okno

			//rysowanie sceny
			//////////////////////////////////////////////////////////////////////

			}
			//ekran pauzy
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

				string zycie = to_string(Pac_Man.dajLiczbeZyc());
				iloscZyc.wyswietl(&okno, "lives: " + zycie);
				zycie = to_string(mapaPunktow.dajProcent());
				ileprocent.wyswietl(&okno, zycie + "%");

				//mapa.rysuj_kolizje(&okno);
				komunikatPauza.wyswietl(&okno);

				okno.display(); // wyswietl wyrysowane okno
			}
			//ekran rozpoczecia gry
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

				string zycie = to_string(Pac_Man.dajLiczbeZyc());
				iloscZyc.wyswietl(&okno, "lives: " + zycie);
				zycie = to_string(mapaPunktow.dajProcent());
				ileprocent.wyswietl(&okno, zycie + "%");

				//mapa.rysuj_kolizje(&okno);
				komunikatStart.wyswietl(&okno);
				logoStartowe.wyswietl(&okno, "PAC-MAN"); // rysuje logo

				okno.display(); // wyswietl wyrysowane okno
			}
			//ekran konca gry (game over)
			else if (pauza == 3)
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

				string zycie = to_string(Pac_Man.dajLiczbeZyc());
				iloscZyc.wyswietl(&okno, "lives: " + zycie);
				zycie = to_string(mapaPunktow.dajProcent());
				ileprocent.wyswietl(&okno, zycie + "%");
				//mapa.rysuj_kolizje(&okno);

				komunikatKoniecGry.wyswietl(&okno);

				okno.display(); // wyswietl wyrysowane okno
			}
			//ekraz konca gry (victory)
			else if (pauza == 4)
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

				string zycie = to_string(Pac_Man.dajLiczbeZyc());
				iloscZyc.wyswietl(&okno, "lives: " + zycie);
				zycie = to_string(mapaPunktow.dajProcent());
				ileprocent.wyswietl(&okno, zycie + "%");
				//mapa.rysuj_kolizje(&okno);

				komunikatWygrales.wyswietl(&okno);

				okno.display(); // wyswietl wyrysowane okno
			}
		}
	}while (czGraTrwa);
	return 0;
}