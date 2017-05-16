#pragma once 

struct Wektor
{
	float x;
	float y;
};

struct DostepnyKierunek
{
	bool G; //góra
	bool P; //prawo
	bool D; //dó³
	bool L; //lewo
};

struct PobraneUstawieniaMapy 
{
	const float StartBohateraX;
	const float StartBohateraY;
	PobraneUstawieniaMapy(float x, float y) :StartBohateraX(x), StartBohateraY(y)
	{
	}
};