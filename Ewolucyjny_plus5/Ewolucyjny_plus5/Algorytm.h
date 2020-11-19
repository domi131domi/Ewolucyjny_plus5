#ifndef  ALGORYTM_DEF
#define ALGORYTM_DEF
#include "Osobnik.h"
#include <functional>
#include <algorithm>
#include "Punkt.h"

class Algorytm
{
public:
	Algorytm(const unsigned rozmiar_populajcji, Osobnik** populacja) noexcept;
	~Algorytm() noexcept;
	void ustawParametry(unsigned rozmiar_populacji, Osobnik** populacja) noexcept;
	void start(unsigned licznik_populacji);
	void liczbaSelekcji(unsigned liczba_selekcji);
	unsigned nr_aktualna_populacja = 0;
private:
	void krzyzowanie(Osobnik** rodzice, Osobnik** dzieci);
	void mutacja(Osobnik** populacja_pomocnicza);
	void ocen(Osobnik** populacja, unsigned rozmiar_populacji);
	void sukcesja(Osobnik** populacja_pomocnicza);
	unsigned rozmiar_populacji = 0;
	unsigned liczba_selekcji = 0;
	unsigned liczba_dzieci = 0;
	Osobnik** populacja = nullptr;
	void selekcjaElitarna(Osobnik** populacja_pomocnicza);
	static bool comp(Osobnik* os1, Osobnik* os2);
};

#endif // ! ALGORYTM_DEF