#ifndef OSOBNIK_DEF
#define OSOBNIK_DEF

class Osobnik
{
public:
	Osobnik();
	virtual Osobnik* stworz_dziecko(Osobnik* rodzic2);
	virtual void mutuj();
	virtual float oblicz_ocene();
	float getOcena();
	void setOcene(float ocena);
private:
	float ocena = 0;
};

#endif // OSOBNIK_DEF
