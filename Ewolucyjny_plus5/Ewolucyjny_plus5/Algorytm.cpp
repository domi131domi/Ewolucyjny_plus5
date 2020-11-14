#include "Algorytm.h"

Algorytm::Algorytm(unsigned rozmiar_populajcji, funkcja_inicjujaca init)
{
	ustawParametry(rozmiar_populacji, init);
}

Algorytm::~Algorytm()
{
	delete[] populacja;
}

void Algorytm::ustawParametry(unsigned rozmiar_populacji, funkcja_inicjujaca init)
{
	this->rozmiar_populacji = rozmiar_populacji;
	if (this->populacja != nullptr)
	{
		delete[] populacja;
	}
	populacja = new Osobnik[rozmiar_populacji];
	this->init = init;
}

void Algorytm::init_osobnikow()
{
	init(populacja, rozmiar_populacji);
}
