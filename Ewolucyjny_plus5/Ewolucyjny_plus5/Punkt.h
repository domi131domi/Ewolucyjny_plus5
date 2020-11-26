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
	float prawd_mutacji = 0;
	float odchylenie_std = 0;

	Punkt() {}
	Punkt(float prawd, float odchyl)
	{
		prawd_mutacji = prawd;
		odchylenie_std = odchyl;
	}

	virtual Osobnik* stworz_dziecko(Osobnik* rodzic2) override
	{
		Punkt* p = new Punkt(prawd_mutacji, odchylenie_std);
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
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0.0, 1.0);
		if (dis(gen) < prawd_mutacji)
		{
			std::normal_distribution<> ndx(x, odchylenie_std);
			this->x = ndx(gen);
		}
		else if (dis(gen) < prawd_mutacji)
		{
			std::normal_distribution<> ndy(y, odchylenie_std);
			this->y = ndy(gen);
		}
	}
	virtual float oblicz_ocene() override
	{
		return (docelowy_X - this->x) * (docelowy_X - this->x) + (docelowy_Y - this->y) * (docelowy_Y - this->y);
	}
};