#include "Sloty.h"
#include <sstream>

int Sloty::counter = 0;

std::string Sloty::randomDate(int starting_month, int ending_month)
{
	//'2023-01-01' to '2023-12-31'
	int year = 2023;
	//int month = rand() % 12 + 1;
	int month = rand() % (ending_month - starting_month + 1) + starting_month;
	int day = 1;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = rand() % 31 + 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = rand() % 30 + 1;
		break;
	case 2:
		day = rand() % 28 + 1;
		break;
	}
	std::string date;
	std::stringstream stream;

	stream << year << '-';
	if (month >= 10)
		stream << month << '-';
	else
		stream << '0' << month << '-';
	if (day >= 10)
		stream << day;
	else
		stream << '0' << day;

	stream >> date;

	return date;
}

std::string Sloty::randomTime()
{
	//'hh:mm:ss' from '-838:59:59' to '838:59:59'
	// 10:00 do 18:00
	// 10:00, 10:15, 10:30, 10:45, 11:00 ... 17:00
	// 10:00 do 17:00, przy czym o 17 minuty to 00
	// 00 15 30 45
	int hour = rand() % 8 + 10;
	int minute = (rand() % 4) * 15;
	int second = 0;
	if (hour == 17)
	{
		minute = 0;
	}
	std::string time;
	std::stringstream stream;

	stream << hour << ':';
	if (minute >= 10)
		stream << minute << ':';
	else
		stream << '0' << minute << ':';
	if (second >= 10)
		stream << second;
	else
		stream << '0' << second;

	stream >> time;

	return time;
}

Sloty::Sloty(int starting_month, int ending_month, int _id_wizyty, int _id_pracownika)
{
	id = ++counter;
	id_wizyty = _id_wizyty;
	data_slotu = randomDate(starting_month, ending_month);
	godzina = randomTime();
	id_pracownika = _id_pracownika;
}