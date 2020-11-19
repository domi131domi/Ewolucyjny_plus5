#include <iostream>
#include "Algorytm.h"
#include "Osobnik.h"
#include <random>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	try 
	{
		const unsigned int liczba = 50;
		//Init
		Osobnik* populacja[liczba];
		for (unsigned i = 0; i < liczba; ++i)
		{
			populacja[i] = new Punkt();
			dynamic_cast<Punkt*>(populacja[i])->x = (float)(rand()%50);
			dynamic_cast<Punkt*>(populacja[i])->y = (float)(rand()%50);
		}

		//wrzucamy tablice osobnikow startowych wraz z ich liczba
		Algorytm a(liczba, populacja);
		//ile osobnikow dopuszczonych do kopulacji
		a.liczbaSelekcji(liczba);
		//startujemy na 20 populacji
		a.start(20);

		//wynik
		std::cout << "t:" << a.nr_aktualna_populacja << std::endl;
		for (unsigned i = 0; i < liczba; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(populacja[i])->x << " y: " << dynamic_cast<Punkt*>(populacja[i])->y << " ocena: " << dynamic_cast<Punkt*>(populacja[i])->getOcena() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
