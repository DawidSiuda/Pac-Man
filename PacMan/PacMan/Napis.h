#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Napis
{
public:
	void wyswietl(RenderWindow *, string tre);
	void wyswietl(RenderWindow *, int tre);

	Napis(int, int, int, Color color = Color(255, 255, 255), string czciaka = "smash.ttf");
	~Napis();
private:
	Font font;
	Text tresc;
};

