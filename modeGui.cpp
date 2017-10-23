
#include "modeGui.h"

cartGUI::cartGUI(Controller* cont, QWidget *parent) : QWidget{ parent }
{
	uiCart.setupUi(this);
	this->c = cont;
	this->connectSignalandSlots();
}

cartGUI::~cartGUI()
{

}

void cartGUI::connectSignalandSlots()
{
	QObject::connect(uiCart.adButton, SIGNAL(clicked()), this, SLOT(adminHandler()));
	QObject::connect(uiCart.userButton, SIGNAL(clicked()), this, SLOT(userHandler()));
	QObject::connect(uiCart.graphButton, SIGNAL(clicked()), this, SLOT(graphHandler()));
}

void cartGUI::adminMode()
{
	DressGUI* gui=new DressGUI{ c };
	gui->show();
}

void cartGUI::userMode()
{
	TestUI* tgui=new TestUI{ c };
	tgui->show();
}

void cartGUI::userHandler()
{
	userMode();
}

void cartGUI::graphHandler()
{
	Graphic* Pui = new Graphic{c};
	Pui->show();
}

void cartGUI::adminHandler()
{
	DressGUI* gui = new DressGUI{ c };
	gui->show();
}
