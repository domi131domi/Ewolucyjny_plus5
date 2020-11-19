#include "Algorytm.h"
#include <iostream>


Algorytm::Algorytm(const unsigned rozmiar_populacji, Osobnik** populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
}
Algorytm::~Algorytm() noexcept
{
}

void Algorytm::ustawParametry(unsigned rozmiar_populacji, Osobnik** populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
}

void Algorytm::start(unsigned licznik_populacji)
{
	ocen(populacja, rozmiar_populacji);
	Osobnik** rodzice = new Osobnik* [liczba_selekcji];
	Osobnik** dzieci = new Osobnik* [liczba_dzieci];
	for (unsigned i = 0; i < licznik_populacji; ++i)
	{
		
		selekcjaElitarna(rodzice);
		krzyzowanie(rodzice,dzieci);
		mutacja(dzieci);
		ocen(dzieci, liczba_dzieci);
		++nr_aktualna_populacja;
		std::cout << nr_aktualna_populacja << std::endl;
		std::cout << "rodzice" << std::endl;
		for (unsigned i = 0; i < liczba_selekcji; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(rodzice[i])->x << " y: " << dynamic_cast<Punkt*>(rodzice[i])->y << " ocena: " << dynamic_cast<Punkt*>(rodzice[i])->getOcena() << std::endl;
		}
		std::cout << "dzieci" << std::endl;
		for (unsigned i = 0; i < liczba_dzieci; ++i)
		{
			std::cout << "x: " << dynamic_cast<Punkt*>(dzieci[i])->x << " y: " << dynamic_cast<Punkt*>(dzieci[i])->y << " ocena: " << dynamic_cast<Punkt*>(dzieci[i])->getOcena() << std::endl;
		}
		sukcesja(dzieci);
	}
}

void Algorytm::liczbaSelekcji(unsigned liczba_selekcji)
{
	this->liczba_selekcji = liczba_selekcji;
	this->liczba_dzieci = (unsigned)(liczba_selekcji / 2);
}

void Algorytm::krzyzowanie(Osobnik** rodzice, Osobnik** dzieci)
{
	for (unsigned i = 0; i < liczba_dzieci; ++i)
	{
		dzieci[i] = rodzice[2*i]->stworz_dziecko(rodzice[2 * i + 1]);
	}
}

void Algorytm::mutacja(Osobnik** populacja_pomocnicza)
{
	for (unsigned i = 0; i < liczba_dzieci; ++i)
	{
		populacja_pomocnicza[i]->mutuj();
	}
}

void Algorytm::ocen(Osobnik** populacja, unsigned rozmiar_populacji)
{
	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		populacja[i]->setOcene(populacja[i]->oblicz_ocene());
	}
}

void Algorytm::sukcesja(Osobnik** populacja_pomocnicza)
{
	Osobnik** max_dziecko = std::min_element(populacja_pomocnicza, populacja_pomocnicza + liczba_dzieci, Algorytm::comp);
	Osobnik** min_populacja = std::max_element(populacja, populacja + rozmiar_populacji, Algorytm::comp);
	while ((*max_dziecko)->getOcena() < (*min_populacja)->getOcena())
	{
		std::swap<Osobnik*>(*max_dziecko, *min_populacja);
		max_dziecko = std::min_element(populacja_pomocnicza, populacja_pomocnicza + liczba_dzieci, Algorytm::comp);
		min_populacja = std::max_element(populacja, populacja + rozmiar_populacji, Algorytm::comp);
	}
}

void Algorytm::selekcjaElitarna(Osobnik** populacja_pomocnicza)
{
	std::sort(populacja, populacja + rozmiar_populacji, Algorytm::comp);
	for (unsigned i = 0; i < liczba_selekcji; ++i)
	{
		populacja_pomocnicza[i] = populacja[i];
	}
}

bool Algorytm::comp(Osobnik* os1, Osobnik* os2)
{
	return os1->getOcena() < os2->getOcena();
}



