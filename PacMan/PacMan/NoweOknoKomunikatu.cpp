#include "NoweOknoKomunikatu.h"



void NoweOknoKomunikatu::wyswietl()
{
		RenderWindow okno(VideoMode(300, 200), "ERROR");// tworzy okno
		Event event;
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
			tekst.setString(napisI);

			okno.clear(); // czyszczenie ekranu
			okno.draw(tekst);
			okno.display();
		}
}

void NoweOknoKomunikatu::wyswietl(RenderWindow *okno)
{
	//t³o
	RectangleShape szareTlo(Vector2f(okno->getSize().x, okno->getSize().y));
	szareTlo.setFillColor(Color(0, 0, 0, 200));
	okno->draw(szareTlo);

	//napis
	Font font;
	if (!font.loadFromFile("smash.ttf"))
	{
		std::cout << "blad wczytania font-u" << std::endl;
	}

	Text napis;
	napis.setFont(font);

	//1
	if (napisI_rozmiar != 0)
	{
		napis.setCharacterSize(napisI_rozmiar);
		napis.setPosition(Vector2f(napisI_x, napisI_y));
		napis.setString(napisI);
		okno->draw(napis);
	}
	
	//2
	if (napisII_rozmiar != 0)
	{
		napis.setCharacterSize(napisII_rozmiar);
		napis.setPosition(Vector2f(napisII_x, napisII_y));
		napis.setString(napisII);
		okno->draw(napis);
	}
	
	//3
	if (napisIII_rozmiar != 0)
	{
		napis.setCharacterSize(napisIII_rozmiar);
		napis.setPosition(Vector2f(napisIII_x, napisIII_y));
		napis.setString(napisIII);
		okno->draw(napis);
	}
	
}

NoweOknoKomunikatu::NoweOknoKomunikatu(string komunikat1, int Ix, int Iy, int Ipx, string komunikat2, int IIx, int IIy, int IIpx, string komunikat3, int IIIx, int IIIy, int IIIpx)
{
	napisI = komunikat1;
	napisI_x = Ix;
	napisI_y = Iy;
	napisI_rozmiar = Ipx;

	napisII = komunikat2;
	napisII_x = IIx;
	napisII_y = IIy;
	napisII_rozmiar = IIpx;

	napisIII = komunikat3;
	napisIII_x = IIIx;
	napisIII_y = IIIy;
	napisIII_rozmiar = IIIpx;
}

NoweOknoKomunikatu::~NoweOknoKomunikatu()
{
}
