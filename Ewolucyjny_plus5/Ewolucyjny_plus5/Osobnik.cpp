#include "Osobnik.h"

Osobnik::Osobnik()
{
}

Osobnik* Osobnik::stworz_dziecko(Osobnik* rodzic2)
{
	return new Osobnik();
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
