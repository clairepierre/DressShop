#pragma once
#include <string>
#include "Dress.h"
#include <vector>

class DressException: public std::exception
{
private:
	std::string message;

public:
	DressException::DressException(std::string message);
	const char* what() const noexcept override;
};

class DressValidator
{
public:
	DressValidator() {}
	int validatelink(const Dress& d);

	int validate_size(std::string size);

	int validate_colour(std::string  colour);

	int validate_price(double price);

	int validate_quantity(int quantity);

	static void validate(std::string  size, std::string  colour, double price, int quantity, std::string  link);
};
