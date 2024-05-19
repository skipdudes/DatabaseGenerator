#pragma once
#include <string>
#include <vector>

class Wizyty
{
private:
	static int counter;
	static std::vector<std::string> statuses;
	static std::vector<std::string> payment_methods;
	std::vector<Wizyty>* wizyty;

public:
	int id;
	std::string status;
	std::string sposob_platnosci;
	float naleznosc;
	int id_klienta;
	std::string nazwa_uslugi;
	std::string czy_pierwsza;

	Wizyty(int _id_klienta, std::string _nazwa_uslugi, std::vector<Wizyty>* _wizyty);
	std::string randomStatus();
	std::string randomPaymentMethod();
	float randomCost();
};