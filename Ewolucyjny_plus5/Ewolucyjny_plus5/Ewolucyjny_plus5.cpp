#include <iostream>
#include "Algorytm.h"
#include "Osobnik.h"
#include <random>
#include <time.h>
#include "Punkt.h"

int main()
{
	srand((unsigned)time(NULL));
	try 
	{
		Punkt b;
		b.x = 1;
		b.y = 1;
		Osobnik* g = &b;
		g->oblicz_ocene();
		const unsigned liczba = 4;
		Punkt populacja[liczba];
		for (unsigned i = 0; i < liczba; ++i)
		{
			populacja[i].x = (float)i;
			populacja[i].y = (float)i;
		}
		for(unsigned i = 0; i < liczba; ++i)
		{
			std::cout << "x: " << populacja[i].x << " y: " << populacja[i].y << std::endl;
		}
		Algorytm a(liczba, populacja);
		a.liczbaSelekcji(liczba);
		a.start(50);
		for (unsigned i = 0; i < liczba; ++i)
		{
			std::cout << "x: " << populacja[i].x << " y: " << populacja[i].y << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
