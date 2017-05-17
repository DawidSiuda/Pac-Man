#include "NoweOknoKomunikatu.h"



void NoweOknoKomunikatu::wyswietl()
{
	RenderWindow okno(VideoMode(300, 200), "ERROR");// tworzy okno
	Event event;
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
						
						case(Keyboard::Escape):
						{
							okno.close();
							break;
						}
				}
			}
		}
		Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
			std::cout << "blad wczytania font-u" << std::endl;
		}
		Text tekst;
		tekst.setFont(font);
		tekst.setPosition(Vector2f(10, 50));
		tekst.setCharacterSize(24);
		tekst.setString(napis);

		okno.clear(); // czyszczenie ekranu
		okno.draw(tekst);
		okno.display();
	}
}

NoweOknoKomunikatu::NoweOknoKomunikatu(string komunikat)
{
	napis = komunikat;
}


NoweOknoKomunikatu::~NoweOknoKomunikatu()
{
}
