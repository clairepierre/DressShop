#pragma once
#include "File.h"
#include <string>

class CSVShoppingBasket :public FileShoppingBasket
{
public:
	CSVShoppingBasket(std::string file) : FileShoppingBasket(file) {};
	void writeToFile() override;
	void displayShoppingBasket() const override;
};

class HTMLShoppingbasket :public FileShoppingBasket 
{
public:
	HTMLShoppingbasket(std::string file) : FileShoppingBasket(file) {};
	void writeToFile() override;
	void displayShoppingBasket() const override;

};