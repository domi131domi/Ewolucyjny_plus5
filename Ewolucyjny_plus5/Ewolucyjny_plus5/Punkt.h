#pragma once
#include "Osobnik.h"
#include <random>
#include <time.h>

class Punkt : public Osobnik
{
public:
	float x = 0, y = 0;
	float docelowy_X = 10, docelowy_Y = 10;
	virtual void jako_dziecko(Osobnik* rodzic1, Osobnik* rodzic2) override
	{
		if (rand() % 2 == 0)
		{
			this->x = dynamic_cast<Punkt*>(rodzic1)->x;
		}
		else
		{
			this->x = dynamic_cast<Punkt*>(rodzic2)->x;
		}
		if (rand() % 2 == 0)
		{
			this->y = dynamic_cast<Punkt*>(rodzic1)->y;
		}
		else
		{
			this->y = dynamic_cast<Punkt*>(rodzic2)->y;
		}
	}
	virtual void mutuj() override
	{
		if (rand() % 10 == 0)
		{
			x *= 2;
		}
		else if (rand() % 10 == 0)
		{
			y *= 2;
		}
	}
	virtual float oblicz_ocene() override
	{
		return docelowy_X - x + docelowy_Y - y;
	}
};