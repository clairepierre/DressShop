#include "CSVShoppingbasket.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"


using namespace std;

void CSVShoppingBasket::writeToFile()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->dresses)
		f << s<<"\n";

	f.close();
}

void CSVShoppingBasket::displayShoppingBasket() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "Notepad", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void HTMLShoppingbasket::writeToFile()
{
	std::string begin{ " <!DOCTYPE html>\n<html>\n<head>\n<title>Dresses</title>\n</head>\n<body>\n<table border = 1>\n<tr>\n<td>Size</td>\n<td>Colour</td>\n<td>Price</td>\n<td>Quantity</td>\n<td>Photograph</td>\n</tr>\n" };
	std::string end{ "</table></body></html> " };
	std::string rowbegin{ "<tr>" };
	std::string rowend{ "</tr>" };

	std::ofstream f{ this->filename.c_str() };
	f << begin << rowbegin;
	for (Dress d : this->dresses)
	{
		if (d.getPhoto() == "")
			break;
		f << rowbegin;
		f << "<td>" << d.getSize() << "</td>" << "\n<td>" << d.getColour() << "</td>" << "\n<td>" << d.getPrice() << "</td>" << "\n<td>" << d.getQuantity() << "</td>" << "\n<td><<a href =" << d.getPhoto() << ">Photo</a></td>\n";
		f << rowend;
	}
	f << rowend << end;
	f.close();
}

void HTMLShoppingbasket::displayShoppingBasket() const
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
