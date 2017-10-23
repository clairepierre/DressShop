
//#include "DressGUI.h"
#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
//#include"Controller.h"
//#include"CSVShoppingbasket.h"
//#include"ui_catalogue.h"
//#include"testui.h"
#include "textfile.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Repository *repo = new Repository("Dress.txt");
	//FileShoppingBasket* basket = new CSVShoppingBasket("Dress2.txt");
	//Controller c{*repo,basket};
	//DressGUI gui{ &c };
	//Ui_Dialog gui{};
	//gui.show();
	/*TestUI* ui = new TestUI();
	ui->show();*/
	TextFile* ui = new TextFile();
	ui->show();

	return a.exec();
}
