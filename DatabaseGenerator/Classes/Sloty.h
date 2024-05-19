#pragma once
#include <string>

class Sloty
{
private:
	static int counter;

public:
	int id;
	int id_wizyty;
	std::string data_slotu;
	std::string godzina;
	int id_pracownika;

	Sloty(int starting_month, int ending_month, int _id_wizyty, int _id_pracownika);
	std::string randomDate(int starting_month, int ending_month);
	std::string randomTime();
};