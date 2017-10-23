#pragma once
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

class Dress
{
private:
	std::string size;
	std::string colour;
	double price;
	int quantity;
	std::string photo;
public:
	Dress();

	Dress(const std::string&size, const std::string&colour, double price, int quantity, const std::string&photo);
	std::string getSize() const { return size; }
	std::string getColour() const { return colour; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }
	std::string getPhoto() const { return photo; }
	bool Dress::operator==(const Dress & dress);
	void open();
	void destroyDress();
};

std::ostream& operator<<(std::ostream& out, Dress& dress);
std::istream& operator >> (std::istream& in, Dress& dress);