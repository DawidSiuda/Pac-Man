#include "Duch.h"

bool Duch::inicjalizujLosowosc = false;

int Duch::smierc()
{
	return 0;
}

float Duch::dajPredkosc()
{
	return predkosc;
}

void Duch::zmianaPozycji(float ILEpx, int kierunek)
{
	switch (kierunek)
	{
	case LEWO:
		x = x - ILEpx;
		break;
	case PRAWO:
		x = x + ILEpx;
		break;
	case GORA:
		y = y - ILEpx;
		break;
	case DOL:
		y = y + ILEpx;
		break;
	case STOJ:
		break;
	default:
		std::cout << "zly kierunek ducha: " << kierunek << std::endl;
	}
	//std::cout << x << " " << y << std::endl;
	cialo->setPosition((int)x, (int)y);
}

void Duch::zmianaPozycji(float xx , float yy )
{
	x = xx;
	y = yy;
}

int Duch::dajKierunek()
{
	return kierunek;
}

void Duch::AI(PacMan *)
{
	if (y == 326 && kierunek == STOJ && x == granicaStartLewo)//stoj¹ na starcie
	{
			kierunek = PRAWO;
			zmianaPozycji((float)granicaStartLewo + odlegloscKolizjiOtoczenia + 1, (float)326.0);
			
	}
	if (y == 326 && kierunek == STOJ && x == granicaStartPrawo)//stoj¹ na starcie
	{
		zmianaPozycji((float)(granicaStartPrawo - odlegloscKolizjiOtoczenia - 1), (float)326.0);
		kierunek = LEWO;
	}
}

int Duch::ladowanie_na_mape()
{
	return 0;
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
	if ((int)x+ odlegloscKolizjiOtoczenia > granicaStartLewo && (int)x - odlegloscKolizjiOtoczenia < granicaStartLewo)
	{
		//cout << (int)x << endl;
		//cout << (int)y << endl;
		if ((int)y == 326)
		{
			kierunek = STOJ;
			x = granicaStartLewo;
		}

	}else
	if ((int)x + odlegloscKolizjiOtoczenia > granicaStartPrawo && (int)x - odlegloscKolizjiOtoczenia < granicaStartPrawo)
	{
		//cout << (int)x << endl;
		//cout << (int)y << endl;
		if ((int)y == 326)
		{
			kierunek = STOJ;
			x = granicaStartPrawo;
		}

	}
	
}

void Duch::zmiana_kier(int)
{
}



Duch::Duch(string teks, int startX, int startY, float czasSt, int pred) 
	:granicaStartLewo(270),
	granicaStartPrawo(350),
	odlegloscKolizjiOtoczenia(3)
{
	if (inicjalizujLosowosc == false)
	{
		srand(time(NULL));
		inicjalizujLosowosc = true;
	}

	x = startX;
	y = startY;
	czasStartu = czasSt;
	bohater.setSize(Vector2f(30, 30));
	//bohater.setFillColor(Color::Yellow);

	if (!tekstura.loadFromFile(teks))
		std::cout << "nie mozna zaladowac rekstury " << teks << std::endl;

	bohater.setTexture(&tekstura);
	bohater.setPosition(x, y);
	cialo = &bohater;
	//clock.restart();
	int losujKierunek = (std::rand() % 2);
	if (losujKierunek == 1)
	{
		kierunek = PRAWO;
	}
	else
	{
		kierunek = LEWO;
	}
	predkosc = pred;
}

Duch::~Duch()
{
}
