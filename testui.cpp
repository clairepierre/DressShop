#include "testui.h"

TestUI::TestUI(Controller* ct,QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	this->connectSignalsAndSlots();
	this->c = ct;
	this->c->addAllDresses();
	this->populateList();
	
}

TestUI::~TestUI()
{

}

void TestUI::connectSignalsAndSlots()
{
	QObject::connect(ui.addtoCartButton, SIGNAL(clicked()), this, SLOT(addButtonHandler()));
	QObject::connect(ui.nextButton, SIGNAL(clicked()), this, SLOT(nextButtonHandler()));
	QObject::connect(ui.openButton, SIGNAL(clicked()), this, SLOT(openButtonHandler()));
	QObject::connect(ui.BackButton,SIGNAL(clicked()),this, SLOT(backButtonHandler()));
	QObject::connect(ui.cartButton, SIGNAL(clicked()), this, SLOT(shoppingButtonHandler()));
}

void TestUI::displayShopB()
{
	this->c->writeBasketFile();
	this->c->displayDress();
}

void TestUI::nextButtonHandler()
{
	this->c->nextDressCatalogue();
	populateList();
}

void TestUI::backButtonHandler()
{
	cartGUI*cartG = new cartGUI{ c };
	cartG->show();
	this->~TestUI();
}

void TestUI::addButtonHandler()
{
	Dress d= this->c->startCatalogue();
	this->c->addDressToShoppingBasket(d);
	ui.cartLine->setText(QString::number(this->c->showCartPrice()));
}

void TestUI::openButtonHandler()
{
	this->c->openDress();
}

void TestUI::shoppingButtonHandler()
{
	this->displayShopB();
}

void TestUI::populateList()
{
	Dress D = this->c->getCatalogue().getCurrentDress();
	QString dS = QString::fromStdString(D.getSize());
	ui.sizeLine->setText(dS);
	QString dC = QString::fromStdString(D.getColour());
	ui.colorLine->setText(dC);
	QString dP = QString::number(D.getPrice());
	ui.priceLine->setText(dP);
}
