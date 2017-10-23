#include "textfile.h"
#include<qdebug.h>
#include"modeGui.h"
TextFile::TextFile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connectSignalandSlots();
}

TextFile::~TextFile()
{

}

void TextFile::initTextF()
{
}
void TextFile::HTMLButtonHandler()
{
	FileShoppingBasket *basket = nullptr;
	basket = new HTMLShoppingbasket("Dress.html");
	Repository *repo = new Repository("Dress.txt");
	Controller *c = new Controller{ *repo,basket };
	cartGUI* gui = new cartGUI{ c };
	gui->show();
	
}

void TextFile::CSVButtonHandler()
{
	FileShoppingBasket *basket = nullptr;
	basket = new CSVShoppingBasket("Dress2.txt");
	Repository *repo = new Repository("Dress.txt");
	Controller *c = new Controller{ *repo,basket };
	cartGUI* gui = new cartGUI{ c };
	gui->show();
}

void TextFile::connectSignalandSlots()
{
	QObject::connect(ui.CSVfile, SIGNAL(clicked()), this, SLOT(CSVButtonHandler()));
	QObject::connect(ui.radioButton, SIGNAL(clicked()), this, SLOT(HTMLButtonHandler()));
}


