#ifndef CARTGUI_H
#define CARTGUI_H

#include <QWidget>
#include "ui_modeGui.h"
#include <Controller.h>
#include "DressGUI.h"
#include "testui.h"
#include "graphic.h"

class cartGUI : public QWidget
{
	Q_OBJECT

public:
	cartGUI(Controller * cont, QWidget * parent=0);
	~cartGUI();

private:
	Ui::cartGUI uiCart;
	Controller* c;
	void connectSignalandSlots();
	void adminMode();
	void userMode();
	
public slots:
	void adminHandler();
	void userHandler();
	void graphHandler();

};

#endif // CARTGUI_H
