#include "Algorytm.h"
#include "Punkt.h"


Algorytm::Algorytm(unsigned rozmiar_populacji, Osobnik* populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
}
Algorytm::~Algorytm() noexcept
{
}

void Algorytm::ustawParametry(unsigned rozmiar_populacji, Osobnik* populacja) noexcept
{
	this->rozmiar_populacji = rozmiar_populacji;
	this->populacja = populacja;
}

void Algorytm::start(unsigned licznik_populacji)
{
	ocen(populacja, rozmiar_populacji);
	Osobnik* populacja_pomocnicza = new Osobnik[liczba_selekcji];
	for (unsigned i = 0; i < licznik_populacji; ++i)
	{
		selekcjaElitarna(populacja_pomocnicza);
		krzyzowanie(populacja_pomocnicza);
		mutacja(populacja_pomocnicza);
		ocen(populacja_pomocnicza, liczba_selekcji);
		sukcesja(populacja_pomocnicza);
		++nr_aktualna_populacja;
	}
}

void Algorytm::liczbaSelekcji(unsigned liczba_selekcji)
{
	this->liczba_selekcji = liczba_selekcji;
	this->liczba_dzieci = (unsigned)(liczba_selekcji / 2);
}

void Algorytm::krzyzowanie(Osobnik* populacja_pomocnicza)
{
	for (unsigned i = 0; i < liczba_dzieci; ++i)
	{
		populacja_pomocnicza[i].jako_dziecko(&populacja_pomocnicza[2 * i], &populacja_pomocnicza[2 * i + 1]);
	}
}

void Algorytm::mutacja(Osobnik* populacja_pomocnicza)
{
	for (unsigned i = 0; i < liczba_dzieci; ++i)
	{
		populacja_pomocnicza[i].mutuj();
	}
}

void Algorytm::ocen(Osobnik* populacja, unsigned rozmiar_populacji)
{
	Punkt* p = dynamic_cast<Punkt*>(populacja);
	for (unsigned i = 0; i < rozmiar_populacji; ++i)
	{
		p[i].setOcene(p[i].oblicz_ocene());
	}
}

void Algorytm::sukcesja(Osobnik* populacja_pomocnicza)
{
	Osobnik* max_dziecko = std::max_element(populacja_pomocnicza, populacja_pomocnicza + liczba_dzieci, Algorytm::comp);
	Osobnik* min_populacja = std::min_element(populacja, populacja + rozmiar_populacji, Algorytm::comp);
	while (max_dziecko->getOcena() < min_populacja->getOcena())
	{
		std::swap<Osobnik>(*max_dziecko, *min_populacja);
		max_dziecko = std::max_element(populacja_pomocnicza, populacja_pomocnicza + liczba_dzieci, Algorytm::comp);
		min_populacja = std::min_element(populacja, populacja_pomocnicza + rozmiar_populacji, Algorytm::comp);
	}
}

void Algorytm::selekcjaElitarna(Osobnik* populacja_pomocnicza)
{
	for (unsigned i = 0; i < liczba_selekcji; ++i)
	{
		populacja_pomocnicza[i] = *std::max_element(populacja, populacja + rozmiar_populacji, Algorytm::comp);
	}
}

bool Algorytm::comp(Osobnik os1, Osobnik os2)
{
	return os1.getOcena() < os2.getOcena();
}



