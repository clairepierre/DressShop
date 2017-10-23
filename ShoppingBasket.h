#pragma once
#include<vector>
#include "Dress.h"

class ShoppingBasket
{
protected:
	
	double price;
	std::vector<Dress> dresses{};
	
public:
	
	ShoppingBasket();

	//Adds a dress to the catalog.
	void add(const Dress&dress);

	//Returns the dress that is currently displayed
	//Dress getCurrentDress();
	Dress getDress(int i);

	
	

	bool isEmpty();

	double showPrice();
	std::vector<Dress>& showShoppingBasket();
	int getLen();
	int valid();


};
