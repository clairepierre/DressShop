#pragma once
#include "Repository.h"
#include "ShoppingBasket.h"
#include "Catalogue.h"

class Controller
{
private:
	Repository repo;
	ShoppingBasket basket;
	Catalogue catalog;
public:
	Controller(Repository& r);
	Controller(Controller& c);
	Controller() {};

	Repository getRepo()  { return repo; }
	ShoppingBasket getBasket() { return basket; }
	Catalogue getCatalogue()  { return catalog; }

	//Adds a dress with the given data to the repository.
	void addDressRepo(const std::string&size, const std::string&colour, double&price, int &quantity, const std::string&photo);

	/*
	Adds a given dress to the current catalogue.
	Input: dress - Dress, the dress must belong to the repository.
	Output: the dress is added to the catalogue.
	*/
	void addDressToShoppingBasket(const Dress& dress);
	std::vector<Dress>& showBasket();

	double showCartPrice();

	// Adds all the dresses from the repository, that have the given size, to the current catalogue.
	void addAllDressesbySize(const std::string& size);

	void addAllDresses();
	void displayDressC();
	
	Dress startCatalogue();
	void openDress();
	Dress nextDressCatalogue();

	

};
