#pragma once
#include <string>
#include <vector>

class Klienci
{
private:
	static int counter;
	static std::vector<std::string> names;
	static std::vector<std::string> surnames;

public:
	int id;
	std::string imie;
	std::string nazwisko;
	std::string numer_telefonu;

	Klienci();
	std::string randomName();
	std::string randomSurname();
	std::string randomTelNumber();
};