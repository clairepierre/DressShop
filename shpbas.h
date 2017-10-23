#ifndef SHPBAS_H
#define SHPBAS_H

#include <QWidget>
#include "ui_shpbas.h"
#include <Controller.h>

class ShpBas : public QWidget
{
	Q_OBJECT

public:
	ShpBas(Controller * cont,QWidget *parent = 0);
	~ShpBas();

private:
	Ui::ShpBas ui;
};

#endif // SHPBAS_H
