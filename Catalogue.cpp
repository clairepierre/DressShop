#include "Catalogue.h"

Catalogue::Catalogue()

{
	this->current = 0;
}

void Catalogue::add(const Dress & dress)
{
	this->dresses.push_back(dress);
}

int Catalogue::valid()
{
	if (this->current >= this->dresses.size() - 1)
	{
		this->current = 0;
		return 0;
	}
	return 1;
}

void Catalogue::seeAll()
{
	this->dresses;
}

Dress Catalogue::getCurrentDress()
{
	valid();
	Dress d;
	if (dresses.size()==0 || d == dresses[this->current]) { return Dress{}; }
	return dresses[this->current];
}



void Catalogue::open()
{
	if (this->dresses.size() == 0)
		return;
	this->current = 0;
	Dress currentDress = this->getCurrentDress();
	currentDress.open();
}

Dress Catalogue::next()
{
	valid();
	this->current++;
	Dress currentDress = this->getCurrentDress();
	return currentDress;
}

bool Catalogue::isEmpty()
{
	return this->dresses.empty();
}
std::vector<Dress>& Catalogue::showAllC()
{
	return this->dresses;
}
