#ifndef  ALGORYTM_DEF
#define ALGORYTM_DEF

#include "Osobnik.h";

typedef void (*funkcja_inicjujaca)(Osobnik* populajca, unsigned rozmiar_populacji);

class Algorytm
{
public:
	Algorytm(unsigned rozmiar_populajcji, funkcja_inicjujaca init);
	~Algorytm();
	void ustawParametry(unsigned rozmiar_populacji, funkcja_inicjujaca init);
	void init_osobnikow();
private:
	unsigned aktualna_populacja = 0;
	unsigned rozmiar_populacji = 0;
	Osobnik* populacja = nullptr;
	funkcja_inicjujaca init;
};

#endif // ! ALGORYTM_DEF