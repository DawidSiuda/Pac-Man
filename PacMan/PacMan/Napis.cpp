#include "Napis.h"

void Napis::wyswietl(RenderWindow * okno ,string tre)
{
	tresc.setString(tre);
	okno->draw(tresc);
}

Napis::Napis(int pozX, int pozY , int roz, Color color ,string czciaka)
{

	if (!font.loadFromFile(czciaka))
	{
		std::cout << "blad wczytania font-u" << std::endl;
	}

	tresc.setFont(font);
	tresc.setCharacterSize(roz);
	tresc.setPosition(Vector2f(pozX, pozY));
	tresc.setFillColor(color);

}

Napis::~Napis()
{
}
