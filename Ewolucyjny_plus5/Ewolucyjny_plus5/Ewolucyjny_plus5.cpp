#include <iostream>
#include "Algorytm.h"
#include "Osobnik.h"
#include <random>
#include <time.h>
#include "test_optimization.hpp"
#include "Punkt.h"
#include <fstream>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	try 
	{
		const unsigned Rozmiar_Populacji = 50;
		const float P_Mutacji = 0.3;
		const float Odchyl = 1.0;
		const unsigned Ilosc_Populacji = 200;
		const string Plik = "nazwa_algorytmu";
		const int D = 2;
		double a[D], b[D];	//zakres przeszukiwan
		const int liczba_testow = 50;
		p05_ab(D, a, b);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis1(a[0],a[1]);
		std::uniform_real_distribution<> dis2(b[0],b[1]);
		for (int numer_testu = 1; numer_testu <= liczba_testow; ++numer_testu)
		{
			Osobnik** populacja = new Osobnik * [Rozmiar_Populacji];
			for (unsigned i = 0; i < Rozmiar_Populacji; ++i)
			{
				populacja[i] = new Punkt(P_Mutacji, Odchyl);
				dynamic_cast<Punkt*>(populacja[i])->x = (float)dis1(gen);
				dynamic_cast<Punkt*>(populacja[i])->y = (float)dis2(gen);
			}

			//wrzucamy tablice osobnikow startowych wraz z ich liczba
			Algorytm algorytm(Rozmiar_Populacji, populacja);
			//startujemy na 20 populacji
			algorytm.start(Ilosc_Populacji);

			//wynik
			std::ofstream file(Plik,std::ofstream::app);
			file << "TEST: " << numer_testu << "X: " << dynamic_cast<Punkt*>(populacja[0])->x << "Y: " << dynamic_cast<Punkt*>(populacja[0])->y << endl;
			for (unsigned i = 0; i < Rozmiar_Populacji; ++i)
			{
				delete populacja[i];
			}

			delete[] populacja;
			file.close();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
