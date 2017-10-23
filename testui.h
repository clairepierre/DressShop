#ifndef TESTUI_H
#define TESTUI_H

#include <QWidget>
#include "ui_testui.h"
#include<Controller.h>
#include "modeGui.h"
#include "shpbas.h"

class TestUI : public QWidget
{
	Q_OBJECT

public:
	TestUI(Controller* ct, QWidget *parent = 0);
	~TestUI();

private:
	Ui::TestUI ui;
	Controller* c;
	void connectSignalsAndSlots();
	void displayShopB();
	
	

public slots:
	void addButtonHandler();
	void nextButtonHandler();
	void backButtonHandler();
	void openButtonHandler();
	void shoppingButtonHandler();
	void populateList();
	

};

#endif // TESTUI_H
