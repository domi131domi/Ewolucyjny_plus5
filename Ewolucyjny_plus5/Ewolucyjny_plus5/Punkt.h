#pragma once
#include "Osobnik.h"
#include <random>
#include <time.h>
#include <math.h>

class Punkt : public Osobnik
{
public:
	float x = 0, y = 0;
	float docelowy_X = 100, docelowy_Y = 100;
	virtual Osobnik* stworz_dziecko(Osobnik* rodzic2) override
	{
		Punkt* p = new Punkt();
		if (rand() % 2 == 0)
		{
			p->x = dynamic_cast<Punkt*>(this)->x;
		}
		else
		{
			p->x = dynamic_cast<Punkt*>(rodzic2)->x;
		}
		if (rand() % 2 == 0)
		{
			p->y = dynamic_cast<Punkt*>(this)->y;
		}
		else
		{
			p->y = dynamic_cast<Punkt*>(rodzic2)->y;
		}
		return (Osobnik*)p;
	}
	virtual void mutuj() override
	{
		if (rand() % 2 == 0)
		{
			if (rand() % 4 == 0)
			{
				this->x *= 2;
			}
		}
		else
		{
			if (rand() % 4 == 0)
			{
				this->y *= 2;
			}
		}
	}
	virtual float oblicz_ocene() override
	{
		return (docelowy_X-this->x)* (docelowy_X - this->x) + (docelowy_Y - this->y) * (docelowy_Y - this->y);
	}
};