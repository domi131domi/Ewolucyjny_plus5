#include "Algorytm.h"
#include <iostream>


Algorytm::Algorytm(const unsigned rozmiar_populacji, Osobnik** populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
	this->oceny = new float[rozmiar_populacji];
	this->prawdopod = new Przedzial[rozmiar_populacji];
}
Algorytm::~Algorytm() noexcept
{
	delete[] oceny;
	delete[] prawdopod;
}

void Algorytm::ustawParametry(unsigned rozmiar_populacji, Osobnik** populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
	this->oceny = new float[rozmiar_populacji];
	this->prawdopod = new Przedzial[rozmiar_populacji];
}

void Algorytm::start(unsigned licznik_populacji)
{
	Osobnik** dzieci = new Osobnik * [rozmiar_populacji];
	for (unsigned i = 0; i < licznik_populacji; ++i)
	{
		ocen(populacja, rozmiar_populacji);
		std::cout << "pocz¹tek" << std::endl;
		for (unsigned i = 0; i < rozmiar_populacji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(populacja[i])->x << " y: " << dynamic_cast<Punkt*>(populacja[i])->y << " ocena: " << dynamic_cast<Punkt*>(populacja[i])->getOcena() << std::endl;
		}
		std::cout << std::endl;
		selekcja(populacja, rozmiar_populacji);
		krzyzowanie(dzieci);
		mutacja(dzieci);
		ocen(dzieci, rozmiar_populacji);
		std::cout << "rodzice" << std::endl;
		for (unsigned i = 0; i < rozmiar_populacji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(populacja[i])->x << " y: " << dynamic_cast<Punkt*>(populacja[i])->y << " ocena: " << dynamic_cast<Punkt*>(populacja[i])->getOcena() << std::endl;
		}
		std::cout << "dzieci" << std::endl;
		for (unsigned i = 0; i < rozmiar_populacji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(dzieci[i])->x << " y: " << dynamic_cast<Punkt*>(dzieci[i])->y << " ocena: " << dynamic_cast<Punkt*>(dzieci[i])->getOcena() << std::endl;
		}
		std::cout << std::endl;
		sukcesja(dzieci);
		std::cout << "nowe pokolenie" << std::endl;
		for (unsigned i = 0; i < rozmiar_populacji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(populacja[i])->x << " y: " << dynamic_cast<Punkt*>(populacja[i])->y << " ocena: " << dynamic_cast<Punkt*>(populacja[i])->getOcena() << std::endl;
		}
		std::cout << std::endl;
		++nr_aktualna_populacja;
		std::cout << nr_aktualna_populacja << std::endl;
	}
	delete[] dzieci;
}

void Algorytm::liczbaSelekcji(unsigned liczba_selekcji)
{
	this->liczba_selekcji = liczba_selekcji;
	this->liczba_dzieci = (unsigned)(liczba_selekcji / 2);
}

/* Selekcja tworzy tablicê z przedzia³ami, których d³ugoœci bêd¹ odpowiada³y prawdopodobieñstu reprodukcji danego osobnika
 * d³ugoœc przedzia³u to ocena / (suma ocen) */ 
void Algorytm::selekcja(Osobnik** populacja, unsigned rozmiar_populacji)
{
	float suma_ocen = 0.0f;
	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		suma_ocen += oceny[i];
	}

	prawdopod[0].pocz = 0;
	for (unsigned i = 0; i < rozmiar_populacji - 1; ++i)
	{
		prawdopod[i].kon = prawdopod[i].pocz + oceny[i] / suma_ocen;
		prawdopod[i + 1].pocz = prawdopod[i].kon;
	}
	prawdopod[rozmiar_populacji - 1].kon = 1;
}

void Algorytm::krzyzowanie(Osobnik** dzieci)
{
	Osobnik* rodzic1 = nullptr;
	Osobnik* rodzic2 = nullptr;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);

	for (unsigned i = 0; i < rozmiar_populacji / 2; ++i)
	{
		float los = (float)dis(gen);
		float los2 = (float)dis(gen);

		for (unsigned j = 0; j < rozmiar_populacji; ++j) // da³em for z break bo imo czytelniej wygl¹da ni¿ while z warunkami
		{
			if (los >= prawdopod[j].pocz && los < prawdopod[j].kon)
			{
				rodzic1 = populacja[j];
				break;
			}
		}
		for (unsigned j = 0; j < rozmiar_populacji; ++j)
		{
			if (los2 >= prawdopod[j].pocz && los2 < prawdopod[j].kon)
			{
				rodzic2 = populacja[j];
				break;
			}
		}

		dzieci[2 * i] = rodzic1->stworz_dziecko(rodzic2);
		dzieci[2 * i + 1] = rodzic1->stworz_dziecko(rodzic2);
	}
}

void Algorytm::mutacja(Osobnik** populacja_pomocnicza)
{
	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		populacja_pomocnicza[i]->mutuj();
	}
}

/* Tworzymy tablice z ocenami i skalujemy je na przedzia³ <0, 1>*/
void Algorytm::ocen(Osobnik** populacja, unsigned rozmiar_populacji)
{
	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		populacja[i]->setOcene(populacja[i]->oblicz_ocene());
	}
	std::sort(populacja, populacja + rozmiar_populacji, Algorytm::comp);

	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		oceny[i] = populacja[i]->getOcena();
	}

	/*
	float qmin = oceny[0];
	float qmax = oceny[rozmiar_populacji - 1];
	if (qmax != qmin)
	{
		for (unsigned i = 0; i < rozmiar_populacji; ++i)
		{
			oceny[i] = 1 - ((oceny[i] - qmin) / (qmax - qmin)); // Minimalizacja
			//oceny[i] =  (oceny[i] - qmin) / (qmax - qmin);	// Maksymalizacja
		}
	}
	*/


}

void Algorytm::sukcesja(Osobnik** populacja_pomocnicza)
{
	if (populacja[0]->getOcena() > populacja_pomocnicza[0]->getOcena())
	{
		delete populacja[0];
		populacja[0] = populacja_pomocnicza[0];
	}

	for (unsigned i = 1; i < rozmiar_populacji; ++i)
	{
		delete populacja[i];
		populacja[i] = populacja_pomocnicza[i];
	}

}

void Algorytm::selekcjaElitarna(Osobnik** populacja_pomocnicza)
{
	for (unsigned i = 0; i < liczba_selekcji; ++i)
	{
		populacja_pomocnicza[i] = populacja[i];
	}
}

bool Algorytm::comp(Osobnik* os1, Osobnik* os2)
{
	return os1->getOcena() < os2->getOcena();
}



