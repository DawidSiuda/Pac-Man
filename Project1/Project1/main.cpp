#include "mapa.h"
#include "ghost.h"
#include "pac_man.h"
#include "fnkcje_SFML.cpp"
#include "lista_zmiennych_stalych.cpp"
//#include "stworz_kolizje_dla_mapy.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

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
				}
					
			
			}
		} //while
		
		
		if (pauza == false)
		{
			Pac_Man.zmiana_pozycji(Clock.getElapsedTime().asSeconds());
			//std::cout << Clock.getElapsedTime().asSeconds() << std::endl; // czas od ostatniej klatki
			Clock.restart();// czas mierzony od pocz¹tku

			okno.clear(); // czyszczenie ekranu

			//////////////////////////////////////////////////////////////////////
			//rysowanie sceny

			okno.draw(Mapa.rysuj()); // rysuj mape

			//system("cls");
			//Vector2f wsp =	Mapa.rysuj().getPosition();
			//std::cout << wsp.x << " " << wsp.y;

			okno.draw(*Pac_Man.cialo);// rysuj pacmana
			//okno.draw

			okno.display();
		}
		else if (pauza == true)
		{
			okno.clear();
			okno.draw(Mapa.rysuj());
			okno.draw(*Pac_Man.cialo);

			/////////////////////////////////////////////
			//zrobic okno pauzy
			/////////////////////////////////////////////
			okno.display();
		}
	}
	return 0;
}