#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <QWidget>
#include "ui_textfile.h"
#include "UI.h"
#include "CSVShoppingbasket.h"
#include "DressGUI.h"

class TextFile : public QWidget
{
	Q_OBJECT

public:
	TextFile(QWidget *parent = 0);
	~TextFile();

private:
	Ui::TextFile ui;
	void initTextF();
	void connectSignalandSlots();
	

public slots:

	void CSVButtonHandler();
	void HTMLButtonHandler();
	

};

#endif // TEXTFILE_H
