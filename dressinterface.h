#ifndef DRESSINTERFACE_H
#define DRESSINTERFACE_H

#include <QtWidgets/QMainWindow>
#include "ui_dressinterface.h"

class dressInterface : public QMainWindow
{
	Q_OBJECT

public:
	dressInterface(QWidget *parent = 0);
	~dressInterface();

private:
	Ui::dressInterfaceClass ui;
};

#endif // DRESSINTERFACE_H
