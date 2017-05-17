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
	~NoweOknoKomunikatu();
private:
	string napis;
};

