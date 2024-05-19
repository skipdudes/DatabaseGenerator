#pragma once
#include <string>
#include <vector>

class Pracownicy
{
private:
	static int counter;
	static std::vector<std::string> names;
	static std::vector<std::string> surnames;

public:
	int id;
	std::string imie;
	std::string nazwisko;
	std::string data_urodzenia;
	std::string data_zatrudnienia;
	int pensja;

	Pracownicy();
	std::string randomName();
	std::string randomSurname();
	std::string randomDateOfBirth();
	std::string randomDateOfEmployment();
	int randomSalary();
};