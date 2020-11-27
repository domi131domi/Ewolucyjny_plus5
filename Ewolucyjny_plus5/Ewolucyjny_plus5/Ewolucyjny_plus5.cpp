#include <iostream>
#include "Algorytm.h"
#include "Osobnik.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	try 
	{
		const unsigned Rozmiar_Populacji = 50;
		const float P_Mutacji = 0.3;
		const float Odchyl = 1.0;
		const unsigned Ilosc_Populacji = 100;
		Osobnik** populacja = new Osobnik*[Rozmiar_Populacji];
		for (unsigned i = 0; i < Rozmiar_Populacji; ++i)
		{
			populacja[i] = new Punkt(P_Mutacji, Odchyl);
			dynamic_cast<Punkt*>(populacja[i])->x = (float)(rand()%50);
			dynamic_cast<Punkt*>(populacja[i])->y = (float)(rand()%50);
		}

		//wrzucamy tablice osobnikow startowych wraz z ich liczba
		Algorytm a(Rozmiar_Populacji, populacja);
		//startujemy na 20 populacji
		a.start(Ilosc_Populacji);

		//wynik
		std::cout << "t:" << a.nr_aktualna_populacja << std::endl;
		for (unsigned i = 0; i < Rozmiar_Populacji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(populacja[i])->x << " y: " << dynamic_cast<Punkt*>(populacja[i])->y << " ocena: " << dynamic_cast<Punkt*>(populacja[i])->getOcena() << std::endl;
			delete populacja[i];
		}

		delete[] populacja;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
