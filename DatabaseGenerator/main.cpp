#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Classes/Klienci.h"
#include "Classes/Pracownicy.h"
#include "Classes/Uslugi.h"
#include "Classes/Wizyty.h"
#include "Classes/Sloty.h"

const std::string filename_klienci = "klienci";
const std::string filename_pracownicy = "pracownicy";
const std::string filename_uslugi = "uslugi";
const std::string filename_wizyty = "wizyty";
const std::string filename_sloty = "sloty";
const char FIELDTERMINATOR = '|';

int main(int argc, char* args[])
{
	const int uslugi_count = Uslugi::getCount();
	int nr_miesiaca_t0; //1
	int nr_miesiaca_t1; //9
	int nr_miesiaca_t2; //11
	int wizyty_count_t1; //800
	int wizyty_count_t2; //200

	if (argc > 1)
	{
		nr_miesiaca_t0 = std::stoi(args[1]);
		nr_miesiaca_t1 = std::stoi(args[2]);
		nr_miesiaca_t2 = std::stoi(args[3]);
		wizyty_count_t1 = std::stoi(args[4]);
		wizyty_count_t2 = std::stoi(args[5]);
	}
	else
	{
		std::cout << "Nie podano argumentow" << std::endl;
		std::cout << "Podaj nr miesiecy dla t0: "; std::cin >> nr_miesiaca_t0;
		std::cout << "Podaj nr miesiecy dla t1: "; std::cin >> nr_miesiaca_t1;
		std::cout << "Podaj nr miesiecy dla t2: "; std::cin >> nr_miesiaca_t2;
		std::cout << "Podaj liczbe zabiegow dla okresu 1: "; std::cin >> wizyty_count_t1;
		std::cout << "Podaj liczbe zabiegow dla okresu 2: "; std::cin >> wizyty_count_t2;
	}

	int sloty_count_t1 = wizyty_count_t1;
	int sloty_count_t2 = wizyty_count_t2;
	int wizyty_total = wizyty_count_t1 + wizyty_count_t2;
	int klienci_count_t1 = wizyty_total / 10;
	int klienci_przyrost = klienci_count_t1 * 0.1;
	int pracownicy_count_t1 = wizyty_total / 100;
	int pracownicy_przyrost = pracownicy_count_t1 * 0.1;

	srand(static_cast<unsigned>(time(nullptr)));
	std::vector<Klienci> klienci;
	std::vector<Pracownicy> pracownicy;
	std::vector<Uslugi> uslugi;
	std::vector<Wizyty> wizyty;
	std::vector<Sloty> sloty;

	//Generowanie danych t1
	for (int i = 0; i < klienci_count_t1; i++)
	{
		Klienci klient;
		klienci.push_back(klient);
	}

	for (int i = 0; i < pracownicy_count_t1; i++)
	{
		Pracownicy pracownik;
		pracownicy.push_back(pracownik);
	}

	for (int i = 0; i < uslugi_count; i++)
	{
		Uslugi usluga;
		uslugi.push_back(usluga);
	}

	for (int i = 0; i < wizyty_count_t1; i++)
	{
		Klienci random_klient = klienci[rand() % klienci.size()];
		Uslugi random_usluga = uslugi[rand() % uslugi.size()];
		Wizyty wizyta(random_klient.id, random_usluga.nazwa, &wizyty);
		wizyty.push_back(wizyta);
	}

	for (int i = 0; i < sloty_count_t1; i++)
	{
		Wizyty random_wizyta = wizyty[rand() % wizyty.size()];
		Pracownicy random_pracownik = pracownicy[rand() % pracownicy.size()];
		Sloty slot(nr_miesiaca_t0, nr_miesiaca_t1, random_wizyta.id, random_pracownik.id);
		sloty.push_back(slot);
	}

	//Zapis danych t1
	std::ofstream output_klienci_t1, output_pracownicy_t1, output_uslugi_t1, output_wizyty_t1, output_sloty_t1;
	std::string temp_filename_klienci_t1 = "Output/" + filename_klienci + "_t1.bulk";
	std::string temp_filename_pracownicy_t1 = "Output/" + filename_pracownicy + "_t1.bulk";
	std::string temp_filename_uslugi_t1 = "Output/" + filename_uslugi + "_t1.bulk";
	std::string temp_filename_wizyty_t1 = "Output/" + filename_wizyty + "_t1.bulk";
	std::string temp_filename_sloty_t1 = "Output/" + filename_sloty + "_t1.bulk";

	output_klienci_t1.open(temp_filename_klienci_t1.c_str());
	output_pracownicy_t1.open(temp_filename_pracownicy_t1.c_str());
	output_uslugi_t1.open(temp_filename_uslugi_t1.c_str());
	output_wizyty_t1.open(temp_filename_wizyty_t1.c_str());
	output_sloty_t1.open(temp_filename_sloty_t1.c_str());

	for (const Klienci& klient : klienci)
	{
		output_klienci_t1 << klient.id << FIELDTERMINATOR << klient.imie << FIELDTERMINATOR <<
			klient.nazwisko << FIELDTERMINATOR << klient.numer_telefonu << '\n';
	}

	for (const Pracownicy& pracownik : pracownicy)
	{
		output_pracownicy_t1 << pracownik.id << FIELDTERMINATOR << pracownik.imie << FIELDTERMINATOR <<
			pracownik.nazwisko << FIELDTERMINATOR << pracownik.data_urodzenia << FIELDTERMINATOR <<
			pracownik.data_zatrudnienia << FIELDTERMINATOR << pracownik.pensja << '\n';
	}

	for (const Uslugi& usluga : uslugi)
	{
		output_uslugi_t1 << usluga.nazwa << FIELDTERMINATOR << usluga.opis << '\n';
	}

	for (const Wizyty& wizyta : wizyty)
	{
		output_wizyty_t1 << wizyta.id << FIELDTERMINATOR << wizyta.status << FIELDTERMINATOR <<
			wizyta.sposob_platnosci << FIELDTERMINATOR << wizyta.naleznosc << FIELDTERMINATOR <<
			wizyta.id_klienta << FIELDTERMINATOR << wizyta.nazwa_uslugi << FIELDTERMINATOR << wizyta.czy_pierwsza << '\n';
	}

	for (const Sloty& slot : sloty)
	{
		output_sloty_t1 << slot.id << FIELDTERMINATOR << slot.id_wizyty << FIELDTERMINATOR <<
			slot.data_slotu << FIELDTERMINATOR << slot.godzina << FIELDTERMINATOR <<
			slot.id_pracownika << '\n';
	}

	output_klienci_t1.close();
	output_pracownicy_t1.close();
	output_uslugi_t1.close();
	output_wizyty_t1.close();
	output_sloty_t1.close();

	//Edycja danych t1
	//Klienci - klienci_count_t1/5 ostatnich zmienilo nr, klienci_przyrost nowych
	//Pracownicy - pracownicy_count_t1/5 ostatnim wzrosla pensja, pracownicy_przyrost nowych
	//Uslugi - bez zmian

	for (int i = (klienci_count_t1 - 1) - (klienci_count_t1 / 5); i < klienci_count_t1; i++)
		klienci[i].numer_telefonu = klienci[i].randomTelNumber();
	for (int i = 0; i < klienci_przyrost; i++)
	{
		Klienci klient;
		klienci.push_back(klient);
	}

	for (int i = (pracownicy_count_t1 - 1) - (pracownicy_count_t1 / 5); i < pracownicy_count_t1; i++)
		pracownicy[i].pensja += 500;
	for (int i = 0; i < pracownicy_przyrost; i++)
	{
		Pracownicy pracownik;
		pracownicy.push_back(pracownik);
	}

	//Generowanie danych t2
	//Wizyty - zwykla generacja nowych
	//Sloty - generacja w nowych miesiacach
	for (int i = 0; i < wizyty_count_t2; i++)
	{
		Klienci random_klient = klienci[rand() % klienci.size()];
		Uslugi random_usluga = uslugi[rand() % uslugi.size()];
		Wizyty wizyta(random_klient.id, random_usluga.nazwa, &wizyty);
		wizyty.push_back(wizyta);
	}

	for (int i = 0; i < sloty_count_t2; i++)
	{
		Wizyty random_wizyta = wizyty[rand() % wizyty.size()];
		Pracownicy random_pracownik = pracownicy[rand() % pracownicy.size()];
		Sloty slot(nr_miesiaca_t1, nr_miesiaca_t2, random_wizyta.id, random_pracownik.id);
		sloty.push_back(slot);
	}

	//Zapis danych t2
	std::ofstream output_klienci_t2, output_pracownicy_t2, output_uslugi_t2, output_wizyty_t2, output_sloty_t2;
	std::string temp_filename_klienci_t2 = "Output/" + filename_klienci + "_t2.bulk";
	std::string temp_filename_pracownicy_t2 = "Output/" + filename_pracownicy + "_t2.bulk";
	std::string temp_filename_uslugi_t2 = "Output/" + filename_uslugi + "_t2.bulk";
	std::string temp_filename_wizyty_t2 = "Output/" + filename_wizyty + "_t2.bulk";
	std::string temp_filename_sloty_t2 = "Output/" + filename_sloty + "_t2.bulk";

	output_klienci_t2.open(temp_filename_klienci_t2.c_str());
	output_pracownicy_t2.open(temp_filename_pracownicy_t2.c_str());
	output_uslugi_t2.open(temp_filename_uslugi_t2.c_str());
	output_wizyty_t2.open(temp_filename_wizyty_t2.c_str());
	output_sloty_t2.open(temp_filename_sloty_t2.c_str());

	for (const Klienci& klient : klienci)
	{
		output_klienci_t2 << klient.id << FIELDTERMINATOR << klient.imie << FIELDTERMINATOR <<
			klient.nazwisko << FIELDTERMINATOR << klient.numer_telefonu << '\n';
	}

	for (const Pracownicy& pracownik : pracownicy)
	{
		output_pracownicy_t2 << pracownik.id << FIELDTERMINATOR << pracownik.imie << FIELDTERMINATOR <<
			pracownik.nazwisko << FIELDTERMINATOR << pracownik.data_urodzenia << FIELDTERMINATOR <<
			pracownik.data_zatrudnienia << FIELDTERMINATOR << pracownik.pensja << '\n';
	}

	for (const Uslugi& usluga : uslugi)
	{
		output_uslugi_t2 << usluga.nazwa << FIELDTERMINATOR << usluga.opis << '\n';
	}

	for (const Wizyty& wizyta : wizyty)
	{
		output_wizyty_t2 << wizyta.id << FIELDTERMINATOR << wizyta.status << FIELDTERMINATOR <<
			wizyta.sposob_platnosci << FIELDTERMINATOR << wizyta.naleznosc << FIELDTERMINATOR <<
			wizyta.id_klienta << FIELDTERMINATOR << wizyta.nazwa_uslugi << FIELDTERMINATOR << wizyta.czy_pierwsza << '\n';
	}

	for (const Sloty& slot : sloty)
	{
		output_sloty_t2 << slot.id << FIELDTERMINATOR << slot.id_wizyty << FIELDTERMINATOR <<
			slot.data_slotu << FIELDTERMINATOR << slot.godzina << FIELDTERMINATOR <<
			slot.id_pracownika << '\n';
	}

	output_klienci_t2.close();
	output_pracownicy_t2.close();
	output_uslugi_t2.close();
	output_wizyty_t2.close();
	output_sloty_t2.close();

	return 0;
}