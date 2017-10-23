#include "ShoppingBasket.h"

ShoppingBasket::ShoppingBasket()
{
	this->price = 0;
	
}

void ShoppingBasket::add(const Dress & dress)
{
	
	this->dresses.push_back(dress);
	this->price =this->price+dress.getPrice();
	
}



Dress ShoppingBasket:: getDress(int i)
{
	Dress d; 
	if (d  == dresses[i]){ return Dress{};}
	return dresses[i];
	
}


bool ShoppingBasket::isEmpty()
{
	return this->dresses.empty();
}

int ShoppingBasket::getLen() 
{
	return this->dresses.size();
}

double ShoppingBasket::showPrice()
{
	return this->price;
}

std::vector<Dress>& ShoppingBasket::showShoppingBasket()
{
	return this->dresses;
}
