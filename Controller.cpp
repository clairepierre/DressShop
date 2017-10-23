#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(Repository & r, FileShoppingBasket* basket)
{
	this->repo=r;
	this->basket=basket;
	Catalogue catalog;
}

Controller::Controller(Controller & c)
{
	repo = c.repo;
	basket = c.basket;
	catalog = c.catalog;
}



void Controller::addDressRepo(const std::string & size,  const std::string & colour, double  price, int  quantity, const std::string & photo)
{
	Dress d{ size,colour,price,quantity,photo };
	this->repo.addDress(d);

}

void Controller::addDressToShoppingBasket(const Dress & dress)
{
	this->basket->add(dress);
}

std::vector<Dress>& Controller::showBasket()
{
	return this->basket->showShoppingBasket();
	
}

double Controller::showCartPrice()
{
	double p=this->basket->showPrice();
	return p;
}

void Controller::addAllDressesbySize(const std::string & size)
{
	
	for (int i = 0; i < this->repo.getDresses().size(); i++)
	{
		Dress d = this->repo.getOnPosition(i);
		if (d.getSize() == size)
			this->catalog.add(d);
	}

}

void Controller::addAllDresses()
{
	
	for (int i = 0; i < repo.getDresses().size(); i++)
	{
		Dress d = this->repo.getOnPosition(i);
		this->catalog.add(d);
	}

}

void Controller::displayDressC()
{
	this->catalog.showAllC();

}

Dress Controller::startCatalogue()
{
	Dress d=this->catalog.getCurrentDress();
	return d;
}

void Controller::openDress() 
{
	this->catalog.open();
}

Dress Controller::nextDressCatalogue()
{
	return this->catalog.next();
	
}

void Controller::writeBasketFile()
{
	return this->basket->writeToFile();
}

void Controller::displayDress()
{
	this->basket->displayShoppingBasket();
}
