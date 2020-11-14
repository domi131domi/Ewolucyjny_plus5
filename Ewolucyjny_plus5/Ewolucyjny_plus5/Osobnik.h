#ifndef OSOBNIK_DEF
#define OSOBNIK_DEF

class Osobnik
{
public:
	Osobnik();
	Osobnik(Osobnik rodzic1, Osobnik rodzic2);
	virtual void stworz_dziedzko(Osobnik rodzic1, Osobnik rodzic2);
	virtual void mutuj();
private:
	float ocena = 0;
};

#endif // OSOBNIK_DEF
