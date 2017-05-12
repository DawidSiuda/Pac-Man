#pragma once

class postac
{
public:
	void ruch();

	postac();
	~postac();

private:
	int wybierz_kolor();
	int predkosc;
	const int kolor;
	int kierunek;


};

