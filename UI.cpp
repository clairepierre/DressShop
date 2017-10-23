#include "UI.h"
#include <string>

using namespace std;
UI::UI()
{
	Controller ctrl;
}

UI::UI(Controller c, std::string filename)
{
	ctrl = c;
	this->filename = filename;
}

UI::~UI()
{
}

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Manage dress repository." << endl;
	cout << "2 - Manage catalogue." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add dress." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printCatalogueMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - See dresses." << endl;
	cout << "\t 2 - See the shopping basket." << endl;
	cout << "\t 0 - Back" << endl;
	
}

void UI::printCommands() 
{
	cout << "\t 1 - Next." << endl;
	cout << "\t 2 - Open." << endl;
	cout << "\t 3 - Add to cart." << endl;
	cout << "\t 0 - Back." << endl;
}


void UI::addDressR()
{
	cout << "Enter the size: ";
	std::string size;
	getline(cin, size);
	cout << "Enter the colour: ";
	std::string colour;
	getline(cin, colour);
	double price = 0;
	cout << "Enter the price: ";
	cin >> price;
	cin.ignore();
	/*while (price < 0) 
	{
		cout << "Enter a valid price: ";
		cin >> price;
		cin.ignore();
	}*/

	int quantity = 0;
	cout << "Enter the quantity:";
	cin >> quantity;
	cin.ignore();
	/*while (price < 0)
	{
		cout << "Enter a valid quantity ";
		cin >> quantity;
		cin.ignore();
	}*/
	cout << "Photo link: ";
	std::string link;
	getline(cin, link);
	try {
		this->ctrl.addDressRepo(size, colour, price, quantity, link);
		std::cout << "The dress was added successfully!\n";
	}
	catch (int&)
	{
		std::cout << "The coat is already stored!!!\n";
	}
	catch (DressException& error)
	{
		std::cout << error.what() << std::endl;
	}

}

void UI::displayAllDressesR()
{
	
	if (this->ctrl.getRepo().isEmpty())
	{
		cout << "There are no dresses in repository" << endl;
		return;
	}
	for (int i = 0; i < this->ctrl.getRepo().getCapacity(); i++)
	{
		Dress d = this->ctrl.getRepo().getOnPosition(i);
		cout << d.getSize() << "-" << d.getColour() << " " << d.getPrice()<< " RON " << d.getQuantity() << " BUC " << endl;
	}
}

void UI::displayAllDressesC()
{
	
	if (this->ctrl.getCatalogue().isEmpty())
	{
		cout << "There are no dresses in catalogue" << endl;
		return;
	}
	for (int i = 0; i < this->ctrl.getCatalogue().showAllC().size(); i++)
	{
		Dress d = this->ctrl.getCatalogue().showAllC()[i];
		cout << d.getSize() << "-" << d.getColour() << " " << d.getPrice() << " RON " << d.getQuantity() << " BUC " << endl;
	}
}

void UI::displayDressC(Dress d)
{
	double p;
	p = this->ctrl.showCartPrice();
	cout << d.getSize() << "-" << d.getColour() << " " << d.getPrice() << " RON " << d.getQuantity() << " BUC " << "\t Cart Total:" << this->ctrl.showCartPrice() << "RON"<< endl;

}

void UI::addDressC()
{
	this->ctrl.addAllDresses();
}

void readStringWithSpaces(int maxStrSize, char str[])
{
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

void UI::addAllDbyS()
{
	cout << "Enter the size: ";
	char size[50];
	string finalSize;
	readStringWithSpaces(50, size);
	for (int i = 0; i < strlen(size); i++) {

		finalSize += size[i];
	}
	if (finalSize==""){
	addDressC();
	}
	else {

		Dress d = this->ctrl.getRepo().findBySize(finalSize);
		if (d.getSize() == "")
		{
			cout << "There are no dresses with the given data in the repository. Nothing will be displayed in catalogue." << endl;
			return;
		}

		this->ctrl.addAllDressesbySize(finalSize);
	}
}
void UI::write_to_file()
{
	std::ofstream f(this->filename);
	//f.open(this->filename, std::ios::out | std::ios::trunc);
	Repository r{ this->ctrl.getRepo() };
	for (int i = 0; i < r.getCapacity(); i++)
	{
		Dress d = r.getOnPosition(i);
		f << d << "\n";
	}
}

void UI::read_from_file()
{
	std::ifstream f{ this->filename };
	Dress d;
	if (!f.is_open())
		return;
	while (!f.eof())
	{
		f >> d;
		this->ctrl.addDressRepo(d.getSize(), d.getColour(), d.getPrice(), d.getQuantity(), d.getPhoto());
	}
}



void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addDressR();
					break;
				case 2:
					this->displayAllDressesR();
				}
			}
		}

		if (command == 2)
		{
			while (true)
			{
				UI::printCatalogueMenu();
				int commandCatalogue{ 0 };
				cout << "Input the command: ";
				cin >> commandCatalogue;
				cin.ignore();
				if (commandCatalogue == 0)
					break;
				switch (commandCatalogue)
				{
				case 1:
					int comm;
					this->addAllDbyS();
					this->displayAllDressesC();
					while (true)
					{			
						Dress d=this->ctrl.startCatalogue();
						UI::printCommands();
						cout << "Input the command: ";
						cin >> comm;
						cin.ignore();
						if (comm == 0) { break; }
						else {
							if (comm == 1) 
							{
								displayDressC(this->ctrl.nextDressCatalogue());
								
							}
							if (comm == 2)
							{
								this->ctrl.openDress();
							}
							if (comm==3)
							{
								this->ctrl.addDressToShoppingBasket(d);
							}
						
						}



					}
					
					
					break;
				case 2:
				{
					if (this->ctrl.getBasket()->isEmpty())
					{
						cout << "Nothing to display, the basket is empty." << endl;
						continue;
					}
					for (int i = 0; i < this->ctrl.getBasket()->getLen();i++) 
					{
						Dress elems = this->ctrl.getBasket()->getDress(i);
						
						cout << "Dress- size: " << elems.getSize() << " colour: " << elems.getColour() << " price: " << elems.getPrice() << " RON " << endl;
					}
					cout << "Total: " << this->ctrl.getBasket()->showPrice() << "RON" << endl;
					this->ctrl.writeBasketFile();
					this->ctrl.displayDress();
					break;
				}
				
				}
			}
		}
	}
}