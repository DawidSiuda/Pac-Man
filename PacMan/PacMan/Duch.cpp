#include "Duch.h"

int Duch::smierc()
{
	return 0;
}

int Duch::ladowanie_na_mape()
{
	return 0;
}

void Duch::rysuj()
{
}

void Duch::zmienZwrotJesliMozliwe()
{
		if (kierunek != kierunek_w_buforze)
	{
		//////////////////////////////////////////////////////////
		// obs³uga  buforu z kierunkami przeciwnymi do aktualnych
		if (kierunek == GORA && kierunek_w_buforze == DOL)
		{
			zmiana_kier(DOL);
		}
		else
		if (kierunek == DOL && kierunek_w_buforze == GORA)
		{
			zmiana_kier(GORA);
		}
		else
		if (kierunek == LEWO && kierunek_w_buforze == PRAWO)
		{
			zmiana_kier(PRAWO);
		}
		else
		if (kierunek == PRAWO && kierunek_w_buforze == LEWO)
		{
			zmiana_kier(LEWO);
		}
	}
}

void Duch::obsluzKolizjeZMmapa(int ile_kolizji, Kolizja *mapaKolizji)
{
}

void Duch::zmiana_kier(int)
{
}

Duch::Duch()
{
}


Duch::~Duch()
{
}
