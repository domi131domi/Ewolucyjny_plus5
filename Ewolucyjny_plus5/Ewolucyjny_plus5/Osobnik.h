#ifndef OSOBNIK_DEF
#define OSOBNIK_DEF

class Osobnik
{
public:
	Osobnik();
	Osobnik(Osobnik* rodzic1, Osobnik* rodzic2);
	virtual void jako_dziecko(Osobnik* rodzic1, Osobnik* rodzic2);
	virtual void mutuj();
	virtual float oblicz_ocene();
	float getOcena();
	void setOcene(float ocena);
private:
	float ocena = 0;
};

#endif // OSOBNIK_DEF
