#pragma once

#include<string>
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class NoweOknoKomunikatu
{
public:
	void wyswietl();

	NoweOknoKomunikatu(string = "komunikat");
	NoweOknoKomunikatu(string, RenderWindow *);
	~NoweOknoKomunikatu();
private:
	bool oknoWindows; //true - obiekt to nowe okno windows, false- obiekt to komunikat wyswietlany w nadrzednym oknie
	string napis;
};

