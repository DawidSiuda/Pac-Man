#include "mapa.h"
#include "ghost.h"
#include "pac_man.h"
#include "fnkcje_SFML.cpp"
#include "lista_zmiennych_stalych.cpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;

int main()
{
	RenderWindow okno(VideoMode(SZEROKOSC_OKNA ,WYSOKOSC_OKNA), "Pac-Man");// tworzy okno

	okno.setFramerateLimit(60); // limit klatek 60
	okno.setVerticalSyncEnabled(true);// czekaj na synchronizacje pionow¹

	mapa Mapa("mapa.jpg",50,60);


	pac_man Pac_Man(3, 1, LEWO, 331,507,false);
	while (okno.isOpen()) //g³ówna pêtla gry
	{
		system("cls");
		Event event;
		while (okno.pollEvent(event)) // petla obs³ugi wydarzeñ
		{
			switch (event.type)
			{
			case Event::Closed:
			{
				okno.close();
			}
			
			}
		} //while

		okno.clear(); // czyszczenie ekranu

		//////////////////////////////////////////////////////////////////////
		//rysowanie sceny

		okno.draw(Mapa.Obraz);
		
		Vector2f wsp =	Mapa.Obraz.getPosition();
		std::cout << wsp.x << " " << wsp.y;
		okno.draw(Pac_Man.bohater);

		okno.display();
	}
	return 0;
}