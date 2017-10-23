#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include "ui_graphic.h"
#include "Controller.h"

class Graphic : public QWidget
{
	Q_OBJECT

public:
	Graphic(Controller * cont, QWidget *parent = 0);
	~Graphic();

private:
	Ui::Graphic ui;
	void makePlot();

};

#endif // GRAPHIC_H
