#ifndef  ALGORYTM_DEF
#define ALGORYTM_DEF
#include "Osobnik.h"
#include <functional>
#include <algorithm>

class Algorytm
{
public:
	Algorytm(unsigned rozmiar_populajcji, Osobnik* populacja) noexcept;
	~Algorytm() noexcept;
	void ustawParametry(unsigned rozmiar_populacji, Osobnik* populacja) noexcept;
	void start(unsigned licznik_populacji);
	void liczbaSelekcji(unsigned liczba_selekcji);
private:
	void krzyzowanie(Osobnik* populacja_pomocnicza);
	void mutacja(Osobnik* populacja_pomocnicza);
	void ocen(Osobnik* populacja, unsigned rozmiar_populacji);
	void sukcesja(Osobnik* populacja_pomocnicza);
	unsigned nr_aktualna_populacja = 0;
	unsigned rozmiar_populacji = 0;
	unsigned liczba_selekcji = 0;
	unsigned liczba_dzieci = 0;
	Osobnik* populacja = nullptr;
	void selekcjaElitarna(Osobnik* populacja_pomocnicza);
	static bool comp(Osobnik os1, Osobnik os2);
};

#endif // ! ALGORYTM_DEF