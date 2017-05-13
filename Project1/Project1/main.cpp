#include "mapa.h"
#include "ghost.h"
#include "pac_man.h"
#include "fnkcje_SFML.cpp"
#include "lista_zmiennych_stalych.cpp"
//#include "stworz_kolizje_dla_mapy.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include <Windows.h>

using namespace sf;

int main()
{
	bool pauza = false; // zmienna informuje czy rozgrywaka nie jest zatrzymana
	RenderWindow okno(VideoMode(SZEROKOSC_OKNA ,WYSOKOSC_OKNA), "Pac-Man");// tworzy okno

	//okno.setFramerateLimit(60); // limit FPS 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	mapa Mapa("mapa.jpg",50,60); //tworzy mape
	pac_man Pac_Man(3, 50, LEWO, Mapa.pozycja_x,Mapa.pozycja_y,false);// tworzy pacmana
	Clock Clock; // zerar pilnuj¹cy rysowania sceny wzgledem up³ynêtego czasu
	
	////////////////////////////////////////////////////////////
	//USUN¥C
			Font font;
			if (!font.loadFromFile("arial.ttf"))
			{
				std::cout << "blad wczytania font-u" << std::endl;
			}
			Text napis;
			napis.setFont(font);
			//napis.setString("Hello world");
			napis.setPosition(Vector2f(200, 700));
			napis.setCharacterSize(24);
			//napis.setColor(Color::Green);
	//USUN¥C
	//////////////////////////////////////////////////////////

	while (okno.isOpen()) //g³ówna pêtla gry
	{
		
		Event event;
		while (okno.pollEvent(event)) // petla obs³ugi wydarzeñ
		{
			switch (event.type)
			{
				case (Event::Closed):
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

					// obsluga klawiatury podczas pauzy, np.powrót do gry
					else if (pauza == true)
					{
						switch (event.key.code)
						{
							case(Keyboard::Escape):
							{
								pauza = false;
								Clock.restart(); //zeruje czas który up³yn¹³ od ostatniej klatki
								break;
							}
						}
					}
					// event.key.code == Keyboard::Escape
					//std::cout << "wcisnieto klawisz" << std::endl;
					break;
				}
				case(Event::MouseButtonPressed):
				{
					std::cout << Mouse::getPosition(okno).x << " " << Mouse::getPosition(okno).y  << std::endl;
					break;
				}
			
			}
		} //while
		
		
		if (pauza == false)
		{
			Pac_Man.zmiana_pozycji(Clock.getElapsedTime().asSeconds());

				//std::cout << Clock.getElapsedTime().asSeconds() << std::endl; // czas od ostatniej klatki
			Clock.restart();// czas mierzony od pocz¹tku
			obsluz_kolizje_mapy(Mapa.daj_mape_kolizji(),
								ILE_KOLIZJI,
								Pac_Man.daj_xy(),
								Pac_Man.daj_kierunek(),
								Pac_Man.daj_kier_w_bufor(),
								&Pac_Man);
			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny
				okno.clear(); // czyszczenie ekranu

				okno.draw(Mapa.rysuj()); // rysuj mape

				okno.draw(*Pac_Man.cialo);// rysuj pacmana

				//rysuj_kolizje(ILE_KOLIZJI, Mapa.daj_mape_kolizji(), &okno); // rysuj obszary kolizyjne

				////////////////////////////////////////////////////////////
				//USUN¥C
					okno.draw(napis);
					switch (Pac_Man.daj_kier_w_bufor())
					{
					case 1: napis.setString("GÓRA"); break;
					case 2: napis.setString("PRAWO"); break;
					case 3: napis.setString("DÓL"); break;
					case 4: napis.setString("LEWO"); break;
					}
				//USUN¥C
				////////////////////////////////////////////////////////////

				okno.display();// wyswietl wyrysowane okno
			//rysowanie sceny
			//////////////////////////////////////////////////////////////////////
						   
		}
		else if (pauza == true)
		{
			okno.clear();
			okno.draw(Mapa.rysuj());
			okno.draw(*Pac_Man.cialo);

			rysuj_kolizje(ILE_KOLIZJI, Mapa.daj_mape_kolizji(), &okno);

			/////////////////////////////////////////////
			//zrobic okno pauzy
			/////////////////////////////////////////////
			okno.display();
		}
	}
	return 0;
}