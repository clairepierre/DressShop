#include "Dress.h"
#include <Windows.h>
#include <shellapi.h>
#include <string.h>
#include <sstream>

Dress::Dress() : size(" "), colour(" "),price(),quantity(),photo(" "){}

Dress::Dress(const std::string & size, const std::string & colour, double  price, int  quantity, const std::string & photo)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
}


void Dress::open()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Dress::destroyDress()
{
}

bool Dress::operator==(const Dress & dress)
{
	if (this->photo == dress.photo)
	{
		return true;
	}
	return false;
}

std::ostream & operator<<(std::ostream & out, Dress & dress)
{
	out << dress.getSize() << "," << dress.getColour() << "," << dress.getPrice() << "," << dress.getQuantity() << "," << dress.getPhoto();
	return out;
}

std::istream & operator >> (std::istream & in, Dress & dress)
{
	std::string s;
	char* sir,*p;
	int quantity;
	double price;
	getline(in,s);
//	in >> s;
	if (s.length() == 0)
		return in;
	sir = (char*)malloc(sizeof(char)*(s.size()+1));
	strcpy(sir, s.c_str());
	p = strtok(sir, ",");
	std::string size(p);
	p = strtok(NULL, ",");
	std::string colour(p);
	p = strtok(NULL, ",");
	price = atof(p);
	p = strtok(NULL, ",");
	quantity = atoi(p);
	p = strtok(NULL, ",");
	std::string photo(p);
	Dress n{ size,colour,price,quantity,photo};
	dress = n;
	free(sir);
	return in;

}
