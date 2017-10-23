#pragma once
#include<vector>
#include "Dress.h"

class Catalogue
{
private:
	std::vector<Dress> dresses{ };
	int current;
public:
	class Catalogue();

	void add(const Dress&dress);

	void seeAll();

	//Returns the dress that is currently displayed
	Dress Catalogue::getCurrentDress();

	//Starts the catalog-shows the first dress
	void open();

	//Shows the next dress in the catalogue
	Dress next();

	//Checks if the catalogue is empty

	bool isEmpty();

	std::vector<Dress>&  showAllC();
	int Catalogue::valid();





};
