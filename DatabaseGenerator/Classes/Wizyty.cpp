#include "Wizyty.h"

int Wizyty::counter = 0;
//std::vector<std::string> Wizyty::statuses = { "odwo³ana", "odbyta", "zaplanowana" };
std::vector<std::string> Wizyty::statuses = { "odwolana", "odbyta", "zaplanowana" };
//std::vector<std::string> Wizyty::payment_methods = { "gotówka", "karta", "BLIK" };
std::vector<std::string> Wizyty::payment_methods = { "gotowka", "karta", "BLIK" };

std::string Wizyty::randomStatus()
{
	return statuses[rand() % statuses.size()];
}

std::string Wizyty::randomPaymentMethod()
{
	return payment_methods[rand() % payment_methods.size()];
}

float Wizyty::randomCost()
{
	//100 to 200 with .01 precision (10000 to 20000)
	int bigNumber = rand() % 10001 + 10000;
	return bigNumber / 100.00f;
}

Wizyty::Wizyty(int _id_klienta, std::string _nazwa_uslugi, std::vector<Wizyty>* _wizyty)
{
	wizyty = _wizyty;

	id = ++counter;
	status = randomStatus();
	sposob_platnosci = randomPaymentMethod();
	naleznosc = randomCost();
	id_klienta = _id_klienta;
	nazwa_uslugi = _nazwa_uslugi;

	//std::string czy_pierwsza;
	bool nowa_wizyta = true;
	for (const Wizyty& temp_wizyta : (*wizyty))
	{
		if (temp_wizyta.id_klienta == id_klienta)
		{
			nowa_wizyta = false;
			break;
		}
	}

	czy_pierwsza = (nowa_wizyta == true) ? "Tak" : "Nie";
}