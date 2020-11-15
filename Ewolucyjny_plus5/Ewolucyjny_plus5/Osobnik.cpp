#include "Osobnik.h"

Osobnik::Osobnik()
{
}

Osobnik::Osobnik(Osobnik* rodzic1, Osobnik* rodzic2)
{
	jako_dziecko(rodzic1, rodzic2);
}

void Osobnik::jako_dziecko(Osobnik* rodzic1, Osobnik* rodzic2)
{
}

void Osobnik::mutuj()
{
}

float Osobnik::oblicz_ocene()
{
	return 5.0f;
}

float Osobnik::getOcena()
{
	return ocena;
}

void Osobnik::setOcene(float ocena)
{
	this->ocena = ocena;
}
