#pragma once 

struct Wektor
{
	float x;
	float y;
};

struct DostepnyKierunek
{
	bool G; //g�ra
	bool P; //prawo
	bool D; //d�
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