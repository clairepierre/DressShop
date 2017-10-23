#include "DressValidator.h"
using namespace std;

DressException::DressException(std::string message)
{
	this->message = message;
}


int DressValidator::validatelink(const Dress & d)
{
	std:: string error;
	// search for "www" or "http" at the beginning of the source string
	int posWww = d.getPhoto().find("www");
	int posHttp = d.getPhoto().find("http");
	if (posWww != 0 && posHttp != 0)
		return 0;

	return 1;
}

int DressValidator::validate_size(std::string size)
{
	std::string s[]{ "S" }, m[]{ "M" }, l[]{ "L" }, xl[]{ "XL" }, xxl[]{ "XXL" };
	if (size == s[1])
		return 1;
	if (size == m[1])
		return 1;
	if (size == l[1])
		return 1;
	if (size == xl[1])
		return 1;
	if (size == xxl[1])
		return 1;
	
	return 0;
}

int DressValidator::validate_colour(std::string colour)
{
	return 0;
}

int DressValidator::validate_price(double price)
{

	if (price <= 0)
		return 0;
	return 1;
}

int DressValidator::validate_quantity(int quantity)
{
	if (quantity <= 0)
		return 0;
	return 1;
}



void DressValidator::validate(std::string size, std::string colour, double price, int quantity, std::string photo)
{
	std::string error{ "" };
	Dress d{ size,colour,price,quantity,photo};
	DressValidator v;
	if (v.validate_size(size) == 0)
		error += "Invalid size!!!\n";
	if (v.validate_colour(colour) == 0)
		error += "Invalid colour!!!\n";
	if (v.validate_price(price) == 0)
		error += "Invalid price!!!\n";
	if (v.validate_quantity(quantity) == 0)
		error += "Invalid quantity!!!\n";
	if (v.validatelink(d) == 0)
		error += "Invalid link to photo!!!\n";
	if (error != "")
		throw DressException(error);
}
const char* DressException::what() const noexcept
{
	return this->message.c_str();
}