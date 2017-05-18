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
	void wyswietl(RenderWindow *);

	NoweOknoKomunikatu(string = "komunikat",int=0 ,int = 0,int = 10, string = "", int = 0, int = 0, int = 10, string = "", int = 0, int = 0, int = 10 );
	~NoweOknoKomunikatu();

private:
	//bool oknoWindows; //true - obiekt to nowe okno windows, false- obiekt to komunikat wyswietlany w nadrzednym oknie
	string napisI;
	int napisI_x;
	int napisI_y;
	int napisI_rozmiar;

	string napisII;
	int napisII_x;
	int napisII_y;
	int napisII_rozmiar;

	string napisIII;
	int napisIII_x;
	int napisIII_y;
	int napisIII_rozmiar;
};

