#pragma once
#include "ShoppingBasket.h"

class FileShoppingBasket :public ShoppingBasket

{
protected:
	std::string filename;
public:
	FileShoppingBasket();
	FileShoppingBasket(std::string file) : filename(file) {};
	virtual ~FileShoppingBasket() {}
	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayShoppingBasket() const = 0;
};