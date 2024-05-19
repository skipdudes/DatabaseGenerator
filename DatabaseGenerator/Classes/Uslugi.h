#pragma once
#include <string>
#include <vector>

class Uslugi
{
private:
	static int counter;
	static std::vector<std::string> names;
	static std::vector<std::string> names_verb;
	static std::vector<std::string> names_noun;
	static std::vector<std::string> descriptions;
	static std::vector<std::string> init_names();

public:
	std::string nazwa;
	std::string opis;

	Uslugi();
	static int getCount();
	std::string randomName();
	std::string randomDescription();
};