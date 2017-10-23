#pragma once
#include "Controller.h"
#include "DressValidator.h"
#include<fstream>
class UI
{
private:
	Controller ctrl;
	std::string filename;
public:
	UI();
	UI(Controller c, std::string filename);
	~UI();
	void run();
private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printCatalogueMenu();
	static void printCommands();

	void addDressR();
	void displayAllDressesR();
	void displayAllDressesC();
	void displayDressC(Dress d);
	void addDressC();
	void addAllDbyS();
	void write_to_file();
	void read_from_file();
};
