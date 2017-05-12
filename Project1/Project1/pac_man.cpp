#include "pac_man.h"


pac_man::pac_man(int ile, int pre, int kier,int xx, int yy, bool port ): kolor(zulty), postac(pre, kier)
{
	ile_zyc = ile;
	portal = port;
	
	x = xx; 
	y = yy;
	bohater.setRadius(10);
	bohater.setOutlineColor(Color::Red);
	bohater.setOutlineThickness(5);
	bohater.setPosition(x, y);

}


pac_man::~pac_man()
{
	//ile_istnieje--;
}

