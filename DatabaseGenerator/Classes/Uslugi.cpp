#include "Uslugi.h"
#include <fstream>
int Uslugi::counter = -1;
//std::vector<std::string> Uslugi::names_verb = { "Woskowanie", "Mycie", "Nab³yszczanie", "Polerowanie", "Farbowanie", "Regeneracja", "Przycinanie", "Wyd³u¿anie" };
std::vector<std::string> Uslugi::names_verb = { "Woskowanie", "Mycie", "Nablyszczanie", "Polerowanie", "Farbowanie", "Regeneracja", "Przycinanie", "Wydluzanie" };
//std::vector<std::string> Uslugi::names_noun = { "w¹sów", "brwi", "paznokci", "w³osów", "rzês", "brody" };
std::vector<std::string> Uslugi::names_noun = { "wasow", "brwi", "paznokci", "wlosow", "rzes", "brody" };
//std::vector<std::string> Uslugi::descriptions = { "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus pulvinar ligula ac ultricies viverra. Nulla facilisi. Fusce luctus imperdiet sapien, ut ornare dolor hendrerit quis.", "Vivamus eget pulvinar leo. Ut aliquam turpis eu placerat vehicula. Morbi in molestie velit, non mattis libero. In volutpat feugiat porta. Maecenas semper dui quis maximus fringilla.", "Integer in justo tellus. Vivamus quis ornare dui. Morbi at ante elementum sem tristique venenatis. Vivamus tellus est, dignissim et auctor placerat, consequat non leo.", "Donec eget diam accumsan risus semper sagittis et ac odio. Donec malesuada orci non est blandit sodales. Sed at sapien nec elit pellentesque aliquet.", "Morbi ac magna at risus imperdiet posuere sed ut ex. Duis luctus massa ante, vel consequat metus ultrices et. Cras luctus nulla id rhoncus dictum.", "Donec id nulla mattis, molestie justo eget, imperdiet sem. Curabitur ullamcorper ante vitae justo interdum maximus. Nunc pretium tellus sit amet faucibus blandit.", "Ut tristique nisl pharetra dolor finibus porttitor. Integer eget nibh ut mauris convallis ullamcorper congue sed mauris. Nunc tristique augue purus, a aliquet dui vehicula non.", "Cras mauris mauris, ultrices id sem eu, ullamcorper sodales metus. Nullam rhoncus magna eget metus hendrerit, eu scelerisque dolor facilisis. Nullam scelerisque posuere pellentesque.", "Donec convallis dui sed lacus eleifend, eget mattis ex aliquam. Cras id tincidunt dolor. Fusce egestas quam molestie sapien mattis pulvinar. Nam rutrum dictum quam, a rutrum mauris condimentum a." };
std::vector<std::string> Uslugi::descriptions = { "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus pulvinar ligula ac ultricies viverra. Nulla facilisi. Fusce luctus imperdiet sapien, ut ornare dolor hendrerit quis.", "Vivamus eget pulvinar leo. Ut aliquam turpis eu placerat vehicula. Morbi in molestie velit, non mattis libero. In volutpat feugiat porta. Maecenas semper dui quis maximus fringilla.", "Integer in justo tellus. Vivamus quis ornare dui. Morbi at ante elementum sem tristique venenatis. Vivamus tellus est, dignissim et auctor placerat, consequat non leo.", "Donec eget diam accumsan risus semper sagittis et ac odio. Donec malesuada orci non est blandit sodales. Sed at sapien nec elit pellentesque aliquet.", "Morbi ac magna at risus imperdiet posuere sed ut ex. Duis luctus massa ante, vel consequat metus ultrices et. Cras luctus nulla id rhoncus dictum.", "Donec id nulla mattis, molestie justo eget, imperdiet sem. Curabitur ullamcorper ante vitae justo interdum maximus. Nunc pretium tellus sit amet faucibus blandit.", "Ut tristique nisl pharetra dolor finibus porttitor. Integer eget nibh ut mauris convallis ullamcorper congue sed mauris. Nunc tristique augue purus, a aliquet dui vehicula non.", "Cras mauris mauris, ultrices id sem eu, ullamcorper sodales metus. Nullam rhoncus magna eget metus hendrerit, eu scelerisque dolor facilisis. Nullam scelerisque posuere pellentesque.", "Donec convallis dui sed lacus eleifend, eget mattis ex aliquam. Cras id tincidunt dolor. Fusce egestas quam molestie sapien mattis pulvinar. Nam rutrum dictum quam, a rutrum mauris condimentum a." };
std::vector<std::string> Uslugi::names = Uslugi::init_names();

std::vector<std::string> Uslugi::init_names()
{
	std::vector<std::string> temp_vector;
	for (const std::string& name_verb : names_verb)
	{
		for (const std::string& name_noun : names_noun)
		{
			std::string temp_string = "";
			temp_string += name_verb;
			temp_string += ' ';
			temp_string += name_noun;
			temp_vector.push_back(temp_string);
		}
	}
	return temp_vector;
}

int Uslugi::getCount()
{
	return Uslugi::names.size();
}

std::string Uslugi::randomName()
{
	//return names_verb[rand() % names_verb.size()] + ' ' + names_noun[rand() % names_noun.size()];
	//return names[rand() % names.size()];
	return names[++counter];
}

std::string Uslugi::randomDescription()
{
	return descriptions[rand() % descriptions.size()];
}

Uslugi::Uslugi()
{
	nazwa = randomName();
	opis = randomDescription();
}